/* See LICENSE file for copyright and license details. */

/* appearance */
#define CLR_GREY1     "#181818"
#define CLR_GREY2     "#282828"
#define CLR_GREY3     "#444444"
#define CLR_WHITE1    "#D8D8D8"
#define CLR_SEL       "#005577"
#define FNT_SANS      "sans:size=10"
#define FNT_GLYPH1    "Font Awesome 7 Free:size=10"
#define FNT_GLYPH2    "Font Awesome 7 Brands:size=10"

static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 8;        /* horiz inner gap between windows */
static const unsigned int gappiv    = 8;        /* vert inner gap between windows */
static const unsigned int gappoh    = 8;        /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 8;        /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int barlpad            = 5;        /* bar left padding */
static const int barrpad            = 5;        /* bar right padding */
static const int bartpad            = 5;        /* bar top padding */
static const int barbpad            = 5;        /* bar bottom padding */
static const int baripad            = 5;        /* padding between bar sections */
static const int bartagpad          = 5;        /* padding between tags */
static const int barsechpad         = 8;        /* bar section horizontal padding */
static const int barsecvpad         = 1;        /* bar section vertical padding */
static const int showtitle          = 0;        /* 0 means no title */
static const int showfloating       = 1;        /* 0 means no floating indicator */
static const char *fonts[]          = { FNT_SANS, FNT_GLYPH1, FNT_GLYPH2 };
static const char *barbgcol         = CLR_GREY1;
static const char *colors[][3]      = {
	/*                  fg          bg         border   */
	[SchemeNorm]    = { CLR_WHITE1, CLR_GREY1, CLR_GREY3 },
	[SchemeSel]     = { CLR_WHITE1, CLR_GREY1, CLR_SEL   },
	[SchemeTagNorm] = { CLR_WHITE1, CLR_GREY2, "#000000" },
	[SchemeTagSel]  = { CLR_WHITE1, CLR_SEL,   "#000000" },
	[SchemeLayout]  = { CLR_WHITE1, CLR_GREY1, "#000000" },
	[SchemeStatus]  = { CLR_WHITE1, CLR_GREY1, "#000000" },
};

/* tagging */
static const char *tags[] = {
	"\uf120", "\ue007", "\uf544", "\uf135", "\uf11b", "\uf1b6"
};

/* rules */
#define TAG_TERM    1 << 0
#define TAG_FFOX    1 << 1
#define TAG_GAME    1 << 4
#define TAG_STEAM   1 << 5

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class        instance    title            tags mask   isfloat   monitor */
	{ "firefox",    NULL,       NULL,            TAG_FFOX,   0,        -1 },
	{ "firefox",    NULL,       "Library",       TAG_FFOX,   1,        -1 },
	{ "firefox",    NULL,       "About"  ,       TAG_FFOX,   1,        -1 },
	{ "retroarch",  NULL,       NULL,            TAG_GAME,   0,        -1 },
	{ "steam",      NULL,       NULL,            TAG_STEAM,  0,        -1 },
	{ "steam",      NULL,       "Steam Login",   TAG_STEAM,  1,        -1 },
	{ "steam",      NULL,       "Steam - News",  TAG_STEAM,  1,        -1 },
	{ "steam",      NULL,       "Friends List",  TAG_STEAM,  1,        -1 },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
                                     /* set to 0 with noborder patch */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */
static const int refreshrate = 120;  /* refresh rate (per second) for client move/resize */

#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "\uf009",   tile },    /* first entry is default */
	{ "\uf2d2",   NULL },    /* no layout function means floating behavior */
	{ "\uf2d0",   monocle },
	{ "\ue80a",   spiral },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define XF86MonBrightnessDown    0x1008ff03
#define XF86MonBrightnessUp      0x1008ff02
#define XF86AudioMute            0x1008ff12
#define XF86AudioLowerVolume     0x1008ff11
#define XF86AudioRaiseVolume     0x1008ff13
#define XF86KbdBrightnessDown    0x1008ff06
#define XF86KbdBrightnessUp      0x1008ff05
#define XF86LaunchA              0x1008ff4a

#define AUDIO_DEV                "@DEFAULT_AUDIO_SINK@"
#define MONITOR_BACKLIGHT_DEV    "intel_backlight"
#define KEYBOARD_BACKLIGHT_DEV   "dell::kbd_backlight"

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", "sans:size=16", "-nb", CLR_GREY1, "-nf", CLR_WHITE1, "-sb", CLR_SEL, "-sf", CLR_WHITE1, NULL };
static const char *termcmd[]  = { "st", "-e", "/bin/bash", "--rcfile", "/home/isaac/.config/bash/bashrc", NULL };

static const Key keys[] = {
	/* modifier                     key                     function        argument */
	/* applications */
	{ MODKEY,                       XK_space,               spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return,              spawn,          {.v = termcmd } },
	/* volume control */
	{ 0,                            XF86AudioMute,          spawn,          SHCMD("wpctl set-mute "AUDIO_DEV" toggle && dwmui-adm volume "AUDIO_DEV) },
	{ 0,                            XF86AudioLowerVolume,   spawn,          SHCMD("wpctl set-volume "AUDIO_DEV" 0.05- && dwmui-adm volume "AUDIO_DEV) },
	{ 0,                            XF86AudioRaiseVolume,   spawn,          SHCMD("wpctl set-volume "AUDIO_DEV" 0.05+ --limit 1.0 && dwmui-adm volume "AUDIO_DEV) },
	/* monitor backlight */
	{ 0,                            XF86MonBrightnessDown,  spawn,          SHCMD("brightnessctl -q -d "MONITOR_BACKLIGHT_DEV" set 2400- && dwmui-adm backlight "MONITOR_BACKLIGHT_DEV) },
	{ 0,                            XF86MonBrightnessUp,    spawn,          SHCMD("brightnessctl -q -d "MONITOR_BACKLIGHT_DEV" set +2400 && dwmui-adm backlight "MONITOR_BACKLIGHT_DEV) },
	/* keyboard backlight */
	{ 0,                            XF86KbdBrightnessDown,  spawn,          SHCMD("brightnessctl -q -d "KEYBOARD_BACKLIGHT_DEV" set 1- && dwmui-adm backlight "KEYBOARD_BACKLIGHT_DEV) },
	{ 0,                            XF86KbdBrightnessUp,    spawn,          SHCMD("brightnessctl -q -d "KEYBOARD_BACKLIGHT_DEV" set +1 && dwmui-adm backlight "KEYBOARD_BACKLIGHT_DEV) },
	/* bar */
	{ MODKEY,                       XK_b,                   togglebar,      {0} },
	/* bar - status */
	{ MODKEY|ShiftMask,             XK_b,                   spawn,          {.v = (const char*[]){ "dwmui-adm", "statusbar", NULL } } },
	/* layouts */
	{ MODKEY,                       XK_t,                   setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,                   setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,                   setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_s,                   setlayout,      {.v = &layouts[3]} },
	/* tags */
	{ MODKEY,                       XK_Tab,                 view,           {0} },
	{ MODKEY,                       XK_0,                   view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,                   tag,            {.ui = ~0 } },
	TAGKEYS(                        XK_1,                                   0)
	TAGKEYS(                        XK_2,                                   1)
	TAGKEYS(                        XK_3,                                   2)
	TAGKEYS(                        XK_4,                                   3)
	TAGKEYS(                        XK_5,                                   4)
	TAGKEYS(                        XK_6,                                   5)
	/* window manipulation */
	{ MODKEY,                       XK_i,                   incnmaster,     {.i = +1} },
	{ MODKEY,                       XK_d,                   incnmaster,     {.i = -1} },
	{ MODKEY,                       XK_h,                   setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,                   setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_j,                   focusstack,     {.i = +1} },
	{ MODKEY,                       XK_k,                   focusstack,     {.i = -1} },
	{ MODKEY,                       XK_z,                   zoom,           {0} },
	{ MODKEY,                       XK_q,                   killclient,     {0} },
	/* monitors */
	{ MODKEY,                       XK_comma,               focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period,              focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,               tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,              tagmon,         {.i = +1 } },
	/* gaps */
	{ MODKEY,                       XK_g,                   togglegaps,     {0} },
	{ MODKEY|ShiftMask,             XK_g,                   defaultgaps,    {0} },
	{ MODKEY|ControlMask,           XK_i,                   incrgaps,       {.i = +1 } },
	{ MODKEY|ControlMask,           XK_d,                   incrgaps,       {.i = -1 } },
	/* quit */
	{ MODKEY|ShiftMask,             XK_q,                   quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	/* layouts */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	/* tags */
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	/* window manipulation */
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
};

