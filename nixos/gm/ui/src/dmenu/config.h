/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 0;                      /* -b  option; if 0, dmenu appears at bottom */
#if ALPHA_PATCH
static int opacity = 1;                     /* -o  option; if 0, then alpha is disabled */
#endif // ALPHA_PATCH
#if CARET_WIDTH_PATCH
static int caret_width = 2;                 /* -cw option; set default caret width */
#endif // CARET_WIDTH_PATCH
#if FUZZYMATCH_PATCH
static int fuzzy = 1;                       /* -F  option; if 0, dmenu doesn't use fuzzy matching */
#endif // FUZZYMATCH_PATCH
#if INCREMENTAL_PATCH
static int incremental = 0;                 /* -r  option; if 1, outputs text each time a key is pressed */
#endif // INCREMENTAL_PATCH
#if INSTANT_PATCH
static int instant = 0;                     /* -n  option; if 1, selects matching item without the need to press enter */
#endif // INSTANT_PATCH
#if CENTER_PATCH
/* CONFIG: Centralizado e Largura */
static int center = 1;                      /* MUDADO PARA 1 (Centro) */
static int min_width = 600;                 /* MUDADO PARA 600 (Simular width=20 do fuzzel) */
#endif // CENTER_PATCH
#if BARPADDING_PATCH
static const int vertpad = 10;              /* vertical padding of bar */
static const int sidepad = 10;              /* horizontal padding of bar */
#endif // BARPADDING_PATCH
#if QUIET_PATCH
static int quiet = 0;                       /* -q  option; if 1, dmenu will not show any items if the search string is empty */
#endif // QUIET_PATCH
#if RESTRICT_RETURN_PATCH
static int restrict_return = 0;             /* -1 option; if 1, disables shift-return and ctrl-return */
#endif // RESTRICT_RETURN_PATCH
/* -fn option overrides fonts[0]; default X11 font or font set */
#if PANGO_PATCH
static char *font = "JetBrainsMono Nerd Font:size=12";
#else
#if XRESOURCES_PATCH
static char *fonts[] =
#else
static const char *fonts[] =
#endif // XRESOURCES_PATCH
{
	/* CONFIG: Fonte do Fuzzel */
	"JetBrainsMono Nerd Font:size=12"
};
#endif // PANGO_PATCH
#if MANAGED_PATCH
static char *prompt            = NULL;      /* -p  option; prompt to the left of input field */
#else
static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */
#endif // MANAGED_PATCH
#if DYNAMIC_OPTIONS_PATCH
static const char *dynamic     = NULL;      /* -dy option; dynamic command to run on input change */
#endif // DYNAMIC_OPTIONS_PATCH
#if SYMBOLS_PATCH
static const char *symbol_1 = "<";
static const char *symbol_2 = ">";
#endif // SYMBOLS_PATCH

#if ALPHA_PATCH
static const unsigned int baralpha = 0xff; 
static const unsigned int borderalpha = 0xff; /* Borda levemente transparente */
static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
	#if BORDER_PATCH
	[SchemeBorder] = { OPAQUE, OPAQUE, OPAQUE },
	#endif // BORDER_PATCH
	#if MORECOLOR_PATCH
	[SchemeMid] = { OPAQUE, baralpha, borderalpha },
	#endif // MORECOLOR_PATCH
	#if HIGHLIGHT_PATCH
	[SchemeSelHighlight] = { OPAQUE, baralpha, borderalpha },
	[SchemeNormHighlight] = { OPAQUE, baralpha, borderalpha },
	#endif // HIGHLIGHT_PATCH
	#if HIGHPRIORITY_PATCH
	[SchemeHp] = { OPAQUE, baralpha, borderalpha },
	#endif // HIGHPRIORITY_PATCH
	#if EMOJI_HIGHLIGHT_PATCH
	[SchemeHover] = { OPAQUE, baralpha, borderalpha },
	[SchemeGreen] = { OPAQUE, baralpha, borderalpha },
	[SchemeRed] = { OPAQUE, baralpha, borderalpha },
	[SchemeYellow] = { OPAQUE, baralpha, borderalpha },
	[SchemeBlue] = { OPAQUE, baralpha, borderalpha },
	[SchemePurple] = { OPAQUE, baralpha, borderalpha },
	#endif // EMOJI_HIGHLIGHT_PATCH
	#if VI_MODE_PATCH
	[SchemeCursor] = { OPAQUE, baralpha, borderalpha },
	#endif // VI_MODE_PATCH
	#if CARET_SCHEME_PATCH
	[SchemeCaret] = { OPAQUE, baralpha, borderalpha },
	#endif // CARET_SCHEME_PATCH
};
#endif // ALPHA_PATCH

static
#if !XRESOURCES_PATCH
const
#endif // XRESOURCES_PATCH
char *colors[][2] = {
	/* CONFIG: Cores Kanagawa (Fuzzel Match) */
	/*               fg         bg       */
	[SchemeNorm] = { "#5c5048", "#0f0f0f" }, // Normal Text/Bg
	[SchemeSel]  = { "#a89080", "#1a1a1a" }, // Selected Text/Bg
	[SchemeOut]  = { "#000000", "#00ffff" },
	
	#if BORDER_PATCH
	[SchemeBorder] = { "#2a2a2a", "#2a2a2a" }, // Border Color
	#endif // BORDER_PATCH
	
	#if MORECOLOR_PATCH
	[SchemeMid]  = { "#eeeeee", "#770000" },
	#endif // MORECOLOR_PATCH
	
	#if HIGHLIGHT_PATCH
	/* Match Highlight Colors (Laranja Kanagawa) */
	[SchemeSelHighlight]  = { "#b5541a", "#1a1a1a" },
	[SchemeNormHighlight] = { "#b5541a", "#0f0f0f" },
	#endif // HIGHLIGHT_PATCH
	
	#if HIGHPRIORITY_PATCH
	[SchemeHp]   = { "#bbbbbb", "#333333" },
	#endif // HIGHPRIORITY_PATCH
	#if EMOJI_HIGHLIGHT_PATCH
	[SchemeHover]  = { "#ffffff", "#353D4B" },
	[SchemeGreen]  = { "#ffffff", "#52E067" },
	[SchemeRed]    = { "#ffffff", "#e05252" },
	[SchemeYellow] = { "#ffffff", "#e0c452" },
	[SchemeBlue]   = { "#ffffff", "#5280e0" },
	[SchemePurple] = { "#ffffff", "#9952e0" },
	#endif // EMOJI_HIGHLIGHT_PATCH
	#if VI_MODE_PATCH
	[SchemeCursor] = { "#222222", "#bbbbbb" },
	#endif // VI_MODE_PATCH
	#if CARET_SCHEME_PATCH
	[SchemeCaret] = { "#eeeeee", "#222222" },
	#endif // CARET_SCHEME_PATCH
};

/* CONFIG: Número de linhas */
/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines      = 10; 

#if GRID_PATCH
/* -g option; if nonzero, dmenu uses a grid comprised of columns and lines */
static unsigned int columns    = 0;
#endif // GRID_PATCH

#if LINE_HEIGHT_PATCH
/* CONFIG: Altura da linha (Simulando padding vertical) */
static unsigned int lineheight = 28;         /* -h option; minimum height of a menu line */
static unsigned int min_lineheight = 8;
#endif // LINE_HEIGHT_PATCH

#if NAVHISTORY_PATCH
static unsigned int maxhist    = 15;
static int histnodup           = 1;	/* if 0, record repeated histories */
#endif // NAVHISTORY_PATCH

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
#if PIPEOUT_PATCH
static const char startpipe[] = "#";
#endif // PIPEOUT_PATCH
static const char worddelimiters[] = " ";

#if VI_MODE_PATCH
/*
 * -vi option; if nonzero, vi mode is always enabled and can be
 * accessed with the global_esc keysym + mod mask
 */
static unsigned int vi_mode = 1;
static unsigned int start_mode = 0;			/* mode to use when -vi is passed. 0 = insert mode, 1 = normal mode */
static Key global_esc = { XK_n, Mod1Mask };	/* escape key when vi mode is not enabled explicitly */
static Key quit_keys[] = {
	/* keysym	modifier */
	{ XK_q,		0 }
};
#endif // VI_MODE_PATCH

#if BORDER_PATCH
/* CONFIG: Largura da Borda */
static unsigned int border_width = 2;
#endif // BORDER_PATCH

#if PREFIXCOMPLETION_PATCH
/*
 * Use prefix matching by default; can be inverted with the -x flag.
 */
static int use_prefix = 1;
#endif // PREFIXCOMPLETION_PATCH
