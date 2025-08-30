/* See LICENSE file for copyright and license details. */

/* appearance */
#define CLR_NORFG    "#BBBBBB"
#define CLR_NORBG    "#222222"
#define CLR_NORBO    "#444444"
#define CLR_SELFG    "#EEEEEE"
#define CLR_SELBG    "#005577"
#define CLR_SELBO    "#005577"
#define FNT_SANS     "sans:size=10"
#define FNT_GLYPH1   "Font Awesome 7 Free:size=10"
#define FNT_GLYPH2   "Font Awesome 7 Brands:size=10"

static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[] = {
	FNT_SANS,
	FNT_GLYPH1,
	FNT_GLYPH2,
};
static const char *colors[][3] = {
	/*               foreground  background  border   */
	[SchemeNorm] = { CLR_NORFG,  CLR_NORBG,  CLR_NORBO },
	[SchemeSel]  = { CLR_SELFG,  CLR_SELBG,  CLR_SELBO },
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
	/* class        instance    title            tags mask   isfloat   monitor */
	{ "firefox",    NULL,       NULL,            TAG_FFOX,   0,        -1 },
	{ "firefox",    NULL,       "Library",       TAG_FFOX,   1,        -1 },
	{ "firefox",    NULL,       "About"  ,       TAG_FFOX,   1,        -1 },
	{ "retroarch",  NULL,       NULL,            TAG_GAME,   0,        -1 },
	{ "Steam",      NULL,       NULL,            TAG_STEAM,  0,        -1 },
	{ "Steam",      NULL,       "Steam Login",   TAG_STEAM,  1,        -1 },
	{ "Steam",      NULL,       "Steam - News",  TAG_STEAM,  1,        -1 },
	{ "Steam",      NULL,       "Friends List",  TAG_STEAM,  1,        -1 },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */
static const int refreshrate = 120;  /* refresh rate (per second) for client move/resize */

static const Layout layouts[] = {
	/* symbol      arrange function */
	{ "\uf009",  tile },    /* first entry is default */
	{ "\uf2d2",  NULL },    /* no layout function means floating behavior */
	{ "\uf2d0",  monocle },
};

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {
	"dmenu_run", "-m", dmenumon, "-fn", FNT_SANS, "-nb", CLR_NORBG, "-nf", CLR_NORFG, "-sb", CLR_SELBG, "-sf", CLR_SELFG, NULL
};
static const char *cmd_term[] = {
	"st", "-e", "/bin/bash", "--rcfile", "/home/isaac/.config/bash/bashrc", NULL
};
static const char *cmd_status[] = {
	"tstat", "set", NULL
};
static const char *cmd_kbdlightdn[] = {
	"uictl", "kbdbright", "down", NULL
};
static const char *cmd_kbdlightup[] = {
	"uictl", "kbdbright", "up", NULL
};
static const char *cmd_monlightdn[] = {
	"uictl", "monbright", "down", NULL
};
static const char *cmd_monlightup[] = {
	"uictl", "monbright", "up", NULL
};
static const char *cmd_multmon[] = {
	"/home/isaac/.scripts/monctl", NULL
};
static const char *cmd_voldn[] = {
	"uictl", "volume", "down", NULL
};
static const char *cmd_volup[] = {
	"uictl", "volume", "up", NULL
};
static const char *cmd_voltg[] = {
	"uictl", "volume", "toggle", NULL
};
static const char *cmd_scrshot[] = {
	"/home/isaac/.scripts/scrshot", NULL
};
static const char *cmd_winshot[] = {
	"/home/isaac/.scripts/scrshot", "window", NULL
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

static const Key keys[] = {
	/* modifier                     key                     function        argument */
	/* applications */
	{ MODKEY,                       XK_space,               spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return,              spawn,          {.v = cmd_term } },
	{ MODKEY|ShiftMask,             XK_s,                   spawn,          {.v = cmd_scrshot } },
	{ MODKEY|ShiftMask,             XK_w,                   spawn,          {.v = cmd_winshot } },
	{ 0,                            XF86LaunchA,            spawn,          {.v = cmd_multmon } },
	/* volume control */
	{ 0,                            XF86AudioMute,          spawn,          {.v = cmd_voltg} },
	{ 0,                            XF86AudioLowerVolume,   spawn,          {.v = cmd_voldn} },
	{ 0,                            XF86AudioRaiseVolume,   spawn,          {.v = cmd_volup} },
	/* monitor backlight */
	{ 0,                            XF86MonBrightnessDown,  spawn,          {.v = cmd_monlightdn} },
	{ 0,                            XF86MonBrightnessUp,    spawn,          {.v = cmd_monlightup} },
	/* keyboard backlight */
	{ 0,                            XF86KbdBrightnessDown,  spawn,          {.v = cmd_kbdlightdn} },
	{ 0,                            XF86KbdBrightnessUp,    spawn,          {.v = cmd_kbdlightup} },
	/* bar */
	{ MODKEY,                       XK_b,                   togglebar,      {0} },
	/* status bar */
	{ MODKEY|ShiftMask,             XK_b,                   spawn,          {.v = cmd_status } },
	/* layouts */
	{ MODKEY,                       XK_t,                   setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,                   setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,                   setlayout,      {.v = &layouts[2]} },
	/*{ MODKEY,                       XK_space,               setlayout,      {0} },*/
	/*{ MODKEY|ShiftMask,             XK_space,               togglefloating, {0} },*/
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
	{ MODKEY,                       XK_Return,              zoom,           {0} },
	{ MODKEY|ShiftMask,             XK_c,                   killclient,     {0} },
	/* monitors */
	{ MODKEY,                       XK_comma,               focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period,              focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,               tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,              tagmon,         {.i = +1 } },
	/* quit */
	{ MODKEY|ShiftMask,             XK_q,                   quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                mask            button          function        argument */
	/* layouts */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	/* tags */
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	/* window manipulation */
	/*{ ClkWinTitle,          0,              Button2,        zoom,           {0} },*/
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
};

