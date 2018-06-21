/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[] = {
	"Open Sans:size=10:style=bold",
	"fontawesome:antialias=true"
};
static const char dmenufont[] = "Open Sans:size=10";
static const char *colors[][3] = {
	/*               foreground  background  border   */
	[SchemeNorm] = { "#f5f5f5",  "#2f2d38",  "#2f2d38" },
	[SchemeSel]  = { "#f5f5f5",  "#8b97b1",  "#8b97b1" },
};

/* tagging */
static const char *tags[] = {
	" \uf120 ", " \uf11c ", " \uf269 ", " \uf524 ", " \uf523 ", " \uf526 "
};

/* rules */
#define TAG_TERM    1 << 0
#define TAG_WORK    1 << 1
#define TAG_WEB     1 << 2

static const Rule rules[] = {
	/* class      instance    title       tags mask   isfloat   monitor */
	{ "Firefox",  NULL,       "Library",  TAG_WEB,    1,        -1 },
	{ "Firefox",  NULL,       NULL,       TAG_WEB,    0,        -1 },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ " \uf009 ",      tile },    /* first entry is default */
	{ " \uf2d2 ",      NULL },    /* no layout function means floating behavior */
	{ " \uf2d0 ",      monocle },
};

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {
	"dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", "#181818", "-nf",
	"#887e75", "-sb", "#0f0f0f", "-sf", "#d6b89c", NULL
};
static const char *cmd_term[]       = { "urxvt", NULL };
static const char *cmd_voldn[]      = { "amixer", "-q", "set", "Master", "5%-", NULL };
static const char *cmd_volup[]      = { "amixer", "-q", "set", "Master", "5%+", NULL };
static const char *cmd_voltg[]      = { "amixer", "-q", "set", "Master", "toggle", NULL };
static const char *cmd_monlightdn[] = { "sudo", "/usr/local/bin/backlight-screen", "down", NULL };
static const char *cmd_monlightup[] = { "sudo", "/usr/local/bin/backlight-screen", "up", NULL };
static const char *cmd_kbdlightdn[] = { "sudo", "/usr/local/bin/backlight-kbd", "down", NULL };
static const char *cmd_kbdlightup[] = { "sudo", "/usr/local/bin/backlight-kbd", "up", NULL };

/* key definitions */
#define MODKEY Mod1Mask
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

static Key keys[] = {
	/* modifier                     key                     function        argument */
	/* applications */
	{ MODKEY,                       XK_p,                   spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return,              spawn,          {.v = cmd_term } },
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
	/* layouts */
	{ MODKEY,                       XK_t,                   setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,                   setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,                   setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,               setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,               togglefloating, {0} },
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
static Button buttons[] = {
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

