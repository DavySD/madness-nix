/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static int   smartgaps              = 0;        /* 1 means no outer gap when there is only one window */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;    /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;        /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "Hurmit Nerd Font:style=Bold:size=10" };
static const char *colors[][3] = {
    /*                 fg         bg         border   */
    [SchemeNorm] = { "#6b6052", "#0f0f0f", "#2e2820" }, 
    [SchemeSel]  = { "#d4c5a9", "#1a1612", "#c4633a" }, // ferrugem viva na borda!
};

typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd1[] = {"st", "-n", "spterm", "-g", "120x30", NULL };
static Sp scratchpads[] = {
	/* name          cmd  */
	{"spterm",      spcmd1},
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            0,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
	{ "Discord",  NULL,       NULL,       0,            1,           -1 },
	{ "Steam",    NULL,       NULL,       0,            1,           -1 },
	{ "steam",    NULL,       NULL,       0,            1,           -1 },
	{ "Thunar",   NULL,       NULL,       0,            1,           -1 },
	{ NULL,		    "spterm",		NULL,		    SPTAG(0),		  1,			     -1 },

};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */
static const int refreshrate = 120;  /* refresh rate (per second) for client move/resize */

#define FORCE_VSPLIT 1
#include "vanitygaps.c"
// #include "fibonacci.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
 	{ "[\\]",     dwindle },
	{ "[@]",      spiral },
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define MOD4KEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "j4-dmenu-desktop", "--dmenu=dmenu", "--term=st", NULL };
static const char *filemgr[]  = { "dbus-launch", "Thunar", NULL };
static const char *termcmd[]  = { "alacritty", NULL };
static const char *ll[]       = { "st", NULL };
static const char *upvol[]    = { "wpctl", "set-volume", "@DEFAULT_AUDIO_SINK@", "5%+", NULL };
static const char *downvol[]  = { "wpctl", "set-volume", "@DEFAULT_AUDIO_SINK@", "5%-", NULL };
static const char *mutevol[]  = { "wpctl", "set-mute", "@DEFAULT_AUDIO_SINK@", "toggle", NULL };
static const char *screenshot_full[] = { "sh", "-c", "maim | tee ~/Imagens/CT/X11/$(date +'%Y-%m-%d-%H%M%S').png | xclip -selection clipboard -t image/png", NULL };
static const char *screenshot_sel[] = { "sh", "-c", "maim -s -u | tee ~/Imagens/CT/X11/$(date +'%Y-%m-%d-%H%M%S').png | xclip -selection clipboard -t image/png", NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MOD4KEY,                      XK_Return, spawn,          {.v = ll } },
	{ MODKEY,                       XK_e,      spawn,          {.v = filemgr } },
  { 0,                            XK_Print,  spawn,          {.v = screenshot_full } },
  { ShiftMask,                    XK_Print,  spawn,          {.v = screenshot_sel } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Escape, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_r,      setlayout,      {.v = &layouts[3]} },
	{ MOD4KEY|ShiftMask,             XK_r,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ 0, XF86XK_AudioMute,          spawn,                     {.v = mutevol } },
	{ 0, XF86XK_AudioLowerVolume,   spawn,                     {.v = downvol } },
	{ 0, XF86XK_AudioRaiseVolume,   spawn,                     {.v = upvol } },
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY|ShiftMask,             XK_r,      quit,           {1} },
	{ MODKEY,            			      XK_w,  	   togglescratch,  {.ui = 0 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)

};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
