/*
 _|_|_|                                                             
 _|    _|  _|_|_|  _|_|      _|_|    _|_|_|    _|    _|             
 _|    _|  _|    _|    _|  _|_|_|_|  _|    _|  _|    _|  
 _|    _|  _|    _|    _|  _|        _|    _|  _|    _|             
 _|_|_|    _|    _|    _|    _|_|_|  _|    _|    _|_|_|             



          _|_|_|      _|_|    _|      _|  _|_|_|_|  _|      _|
          _|    _|  _|    _|    _|  _|    _|        _|_|    _|
          _|_|_|    _|_|_|_|      _|      _|_|_|    _|  _|  _|
          _|    _|  _|    _|    _|  _|    _|        _|    _|_|
          _|    _|  _|    _|  _|      _|  _|_|_|_|  _|      _|

*/
/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 1;                      /* -b  option; if 0, dmenu appears at bottom     */
static int fuzzy = 1;                      /* -F  option; if 0, dmenu doesn't use fuzzy matching     */
/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {
    "Hack:size=13:antialias=true:autohint=true",
    "JoyPixels :pixelsize=10:antialias=true:autohint=true"
};
static const char *prompt      = "";      /* -p  option; prompt to the left of input field NULL for no value*/
static const char *symbol_1 = "玲";
static const char *symbol_2 = "怜";
/*static const char dark_blue[]   = "#3B4252"; dark_blue nodr */
static const char dark_blue[]   = "#262626"; 
static const char black[]       = "#1d2021";
static const char white[]       = "#928374";
static const char red[]         = "#CC241D";
static const char green[]       = "#98971A";
static const char yellow[]      = "#D79921";
static const char blue[]        = "#458588";
static const char purple[]      = "#B16286";
static const char aqua[]        = "#689D6A";
static const char orange[]      = "#D65D0E";
static const char *colors[SchemeLast][2] = {
                            /*     fg         bg       */
	[SchemeNorm]            = { white, black},
	[SchemeSel]             = { black, red},
	[SchemeSelHighlight]    = { black, blue},
	[SchemeNormHighlight]   = { black, green},
	[SchemeOut]             = { black, yellow},
};
/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines      = 0;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";

/* Size of the window border */
static const unsigned int border_width = 4;


