/* See LICENSE file for copyright and license details. */
#include <X11/XF86keysym.h>

/* appearance */
static const unsigned int borderpx      = 4;        /* border pixel of windows */
static const int gappx                  = 8;                 /* gaps between windows */
static const unsigned int snap          = 32;       /* snap pixel */
static const unsigned int systraypinning= 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;   	/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing= 2;   /* systray spacing */
static const int systraypinningfailfirst= 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
#define ICONSIZE 26   /* icon size */
#define ICONSPACING 8 /* space between icon and title */
static const int showsystray            = 1;     /* 0 means no systray */
static const int showbar                = 1;        /* 0 means no bar */
static const int topbar                 = 0;        /* 0 means bottom bar */
static const char *fonts[]              = { "Symbols Nerd Font:size=18:antialias=true:autohint:true"};

static const char black[]               = "#1d2021";
static const char white[]               = "#928374";
static const char gray[]                = "#282828";
static const char red[]                 = "#CC241D";
static const char green[]               = "#98971A";
static const char yellow[]              = "#D79921";
static const char blue[]                = "#458588";
static const char purple[]              = "#B16286";
static const char aqua[]                = "#689D6A";
static const char orange[]              = "#D65D0E";
static const char *colors[][3]          = {
	/*               fg         bg         border   */
	[SchemeNorm] = { white, gray, white },
	[SchemeSel]  = { red,   gray, red  },
};

/* tagging */
//static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const char *tags[] = {"", "", "ﬓ", ""};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class               instance  title      tags mask isfloating   monitor  scratch key x     y    h    w     border px*/
    { "CmusPlayerScratch", NULL,     NULL,      0,           1,          -1,    'c',        300, 200, 1280, 720,   4 },
    { "NewsBoat",          NULL,     NULL,      0,           1,          -1,    'n',        300, 200, 1280, 720,   4 },
    { NULL,                NULL,     "dict",    0,           1,          -1,    'd',        300, 200, 1200, 800,   4 },
    { NULL,                NULL,     "term",    0,           1,          -1,    't',        516, 230, 1440, 810,   4 },
    { NULL,                NULL,     "nnn",     0,           1,          -1,    'r',        380, 100, 960,  540,   3 },
    { NULL,                NULL,     "youtube", 0,           1,          -1,    'y',        516, 230, 1600, 900,   4 },
    { NULL,                NULL,     "subs",    0,           1,          -1,    's',        516, 230, 1600, 900,   4 }
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 0; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
    {"", tile}, /* first entry is default */
    {"", NULL}, /* no layout function means floating behavior */
    {"", monocle},
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", NULL };
static const char *termcmd[]  = { "alacritty", NULL };
static const char terminal[10] =  "alacritty";

/*       First arg only serves to match against key in rules    */
/*       Scratch pad */
static const char *term[]           = { "t", terminal, "-o", "background_opacity=1", "-t", "term",   NULL};
static const char *cmus[]           = { "c", terminal, "--class", "CmusPlayerScratch,CmusPlayerScratch", "-e", "cmus",   NULL};
static const char *ytfzf[]          = { "y", terminal, "-t", "youtube", "-e","ytfzf", "-lt", "--force-youtube",  "--detach", NULL};
static const char *ytfzfs[]         = { "s", terminal, "-t", "subs", "-e","ytfzf", "-lt", "-cS", "--sort", "--force-youtube",  "--detach", NULL};
static const char *nnn[]            = { "r", terminal, "-t", "nnn", "-e", "zsh", "/home/raxen/.local/configs/scripts/nnn.sh", NULL};
//static const char *nnn[]            = { "r", terminal, "-t", "nnn", "-e", "nnn","-ad", NULL};
static const char *dict[]           = { "d", terminal, "-t", "dict", "-e", "sdcv",   "--color=auto", NULL};
static const char *newsboat[]       = { "n", terminal, "--class", "NewsBoat,NewsBoat", "-e", "newsboat", "-c", "/home/raxen/.cache/newsboat.db", NULL};

/* dmenu scripts */
static const char *go[]             = { "zsh", "/home/raxen/.local/configs/scripts/dmenu_websearch.sh", NULL};
static const char *search[]         = { "zsh", "/home/raxen/.local/configs/scripts/dmenu_search", NULL };
//static const char *bookmark[]     = { "bash", "/home/raxen/.local/configs/scripts/dmenu_bookmarks.sh", NULL };
//static const char *bookmark_o[]   = { "bash", "/home/raxen/.local/configs/scripts/dmenu_bookmarks.sh","-o", NULL };
static const char *dmenu_colors[]        = { "bash", "/home/raxen/.local/configs/scripts/dmenu_colors", NULL};
static const char *redyt[]          = {"redyt", NULL};

/* terminal applications */
//static const char *notes[]          = { "/home/raxen/.local/configs/scripts/note.sh", NULL};
//static const char *notes_s[]        = { "/home/raxen/.local/configs/scripts/note.sh", "-s", NULL};
static const char *qalc[]           = { terminal, "-e", "qalc", NULL};
static const char *calcurse[]       = { terminal, "-e", "calcurse", NULL };
static const char *dotfiles[]       = { terminal, "-e", "bash", "/home/raxen/.local/configs/scripts/dmenu_dotfiles", NULL };
//
/* GUI applications */

//static const char *browser[]      = { "chromium", "--enable-features=VaapiVideoDecoder", NULL};
//static const char *browser_p[]    = { "chromium", "--incognito", NULL};
static const char *browser[]      = { "firefox", NULL};
static const char *browser_p[]    = { "firefox", "--private-window", NULL};
//static const char *browser[]      = { "librewolf", NULL};
//static const char *browser_p[]    = { "librewolf", "--private-window", NULL};
//static const char *discord[]        = { "discord", NULL};
static const char *discord[]        = { "chromium", "--app=https://discord.com/channels/@me", NULL};
static const char *freetube[]       = { "freetube", NULL};
static const char *qbittorrent[]    = { "qbittorrent", NULL};
static const char *vlc[]            = { "vlc", NULL};
static const char *cal[]            = { "bash", "/home/raxen/.local/configs/scripts/calendar", NULL};
static const char *atom[]           = { "atom", NULL};
static const char *clock[]          = { "alacritty", "-e", "tty-clock", "-xsct", "-C", "4",  NULL};
static const char *spotify[]        = { "spotify", NULL};
static const char *pcmanfm[]        = { "pcmanfm", NULL};
/* playerctl controls */
static const char *c_play[]         = { "playerctl", "play-pause", NULL};
static const char *c_pause[]        = { "playerctl", "pause", NULL};
static const char *c_next[]         = { "playerctl", "next", NULL};
static const char *c_prev[]         = { "playerctl", "previous", NULL};
/* volume controls*/
static const char *upvol[]          = { "bash", "/home/raxen/.local/configs/scripts/sound_notify.sh", "1%+", NULL};
static const char *downvol[]        = { "bash", "/home/raxen/.local/configs/scripts/sound_notify.sh", "1%-", NULL};
static const char *mutevol[]        = { "amixer", "set", "Master", "toggle", NULL};
/* Brightness controls using brightnessctl */
static const char *brightup[]       = { "bash", "/home/raxen/.local/configs/scripts/brightness_notify.sh", "3%+", NULL};
static const char *brightdown[]     = { "bash", "/home/raxen/.local/configs/scripts/brightness_notify.sh", "3%-", NULL};
/* misc */
static const char *screenshot[]     = { "bash", "/home/raxen/.local/configs/scripts/screenshot.sh", NULL};
static const char *slock[]          = {"slock", NULL};
static const char *suspend[]        = {"systemctl", "suspend", NULL};
static const char *shut[]           = { "bash", "/home/raxen/.local/configs/scripts/dmscripts.sh", NULL};
static const char *xmenu[]          = { "bash", "/home/raxen/.local/configs/sourcepkgs/xmenu/xmenu.sh", NULL};
static const char *dunst[]          = { "dunstctl", "close-all", NULL };



static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_u,      incnmaster,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY|ShiftMask,             XK_l,      setmfact,       {.f = +0.05} },
/*                              cfacts                                          */
    {MODKEY|ShiftMask,                      XK_j,               setcfact,      {.f = +0.25         }},
    {MODKEY|ShiftMask,                      XK_k,               setcfact,      {.f = -0.25         }},
    {MODKEY|ShiftMask,                      XK_o,               setcfact,      {.f = 0.00          }},
/*                  push up and down                                            */
    {MODKEY|ControlMask,                    XK_j,               pushdown,               {0                  }},
    {MODKEY|ControlMask,                    XK_k,               pushup,                 {0                  }},

	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },

	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },

	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },

	{ MODKEY,                       XK_minus,  setgaps,        {.i = -5 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +5 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },


    {MODKEY|ShiftMask,                      XK_t,                   spawn,              {.v = calcurse      }},
    //{MODKEY,                                XK_e,                   spawn,              {.v = notes         }},
    //{MODKEY|ShiftMask,                      XK_e,                   spawn,              {.v = notes_s       }},
    {MODKEY|ShiftMask,                      XK_p,                   spawn,              {.v = qalc          }},

    {MODKEY|ShiftMask,                      XK_r,                   spawn,              {.v = redyt         }},
    {MODKEY|ShiftMask,                      XK_u,                   spawn,              {.v = dmenu_colors  }},
    {MODKEY,                                XK_w,                   spawn,              {.v = browser       }},
    {MODKEY|ShiftMask,                      XK_w,                   spawn,              {.v = browser_p     }},
  //{ MODKEY,                               XK_g,                   spawn,              { .v = go           }},
    {MODKEY,                                XK_o,                   spawn,              {.v = go            }},
    {MODKEY|ShiftMask,                      XK_o,                   spawn,              {.v = search        }},
 // { MODKEY|ShiftMask,                     XK_o,                   spawn,              { .v = bookmark_o   }},
    { MODKEY,                               XK_d,                   spawn,              { .v = dotfiles     }},

    {0,                                 XF86XK_AudioPlay,           spawn,              {.v = c_play        }},
    {0,                                 XF86XK_AudioStop,           spawn,              {.v = c_pause       }},
    {0,                                 XF86XK_AudioNext,           spawn,              {.v = c_next        }},
    {0,                                 XF86XK_AudioPrev,           spawn,              {.v = c_prev        }},
    {0,                                 XK_Print,                   spawn,              {.v = screenshot    }},

    {MODKEY,                                 XK_KP_Next,                 spawn,              {.v = atom          }},
    {MODKEY,                                 XK_KP_Left,                 spawn,              {.v = pcmanfm       }},
    {MODKEY,                                 XK_KP_Begin,                spawn,              {.v = vlc           }},
    {MODKEY,                                 XK_KP_Right,                spawn,              {.v = qbittorrent   }},
    {MODKEY,                                 XK_KP_Up,                   spawn,              {.v = discord       }},
    {MODKEY,                                 XK_KP_Prior,                spawn,              {.v = spotify       }},
    {MODKEY,                                 XK_KP_End,                  spawn,              {.v = clock         }},
    {MODKEY,                                 XK_KP_Home,                 spawn,              {.v = freetube      }},
    {MODKEY,                                 XK_KP_Down,                 spawn,              {.v = cal           }},

    {0,                                 XF86XK_AudioRaiseVolume,    spawn,              {.v = upvol         }},
    {0,                                 XF86XK_AudioLowerVolume,    spawn,              {.v = downvol       }},
    {0,                                 XF86XK_AudioMute,           spawn,              {.v = mutevol       }},
    {0,                                 XF86XK_MonBrightnessUp,     spawn,              {.v = brightup      }},
    {0,                                 XF86XK_MonBrightnessDown,   spawn,              {.v = brightdown    }},
    {0,                                 XF86XK_Calculator,          spawn,              {.v = suspend       }},

    {MODKEY|ShiftMask|ControlMask,      XK_Return,              togglescratch,          {.v = term          }},
    {MODKEY,                                XK_c,               togglescratch,          {.v = cmus          }},
    {MODKEY,                                XK_r,               togglescratch,          {.v = nnn           }},
    {MODKEY,                                XK_y,               togglescratch,          {.v = ytfzf         }},
    {MODKEY|ShiftMask,                      XK_y,               togglescratch,          {.v = ytfzfs        }},
    {MODKEY,                                XK_a,               togglescratch,          {.v = dict          }},
    {MODKEY,                                XK_n,               togglescratch,          {.v = newsboat      }},

    {MODKEY|ControlMask|ShiftMask,          XK_l,               spawn,                  {.v = slock         }},
    {MODKEY,                                XK_Escape,          spawn,                  {.v = shut          }},
    {ControlMask|ShiftMask,                 XK_space,           spawn,                  {.v = dunst         }},

	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
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
    {ClkRootWin, 0, Button3, spawn, {.v = xmenu}},
};
