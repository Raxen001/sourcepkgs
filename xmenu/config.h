static struct Config config = {
	/* font, separate different fonts with comma */
	.font = "Hack:size=13,DejaVuSansMono:size=9",

	/* colors */
	/*.background_color = "#2E3440",*/
	.background_color    = "#282828",
	.foreground_color    = "#a89984",
	.selbackground_color = "#458588",
	.selforeground_color = "#262626",
	.separator_color     = "#cc241d",
	.border_color        = "#282828",

	/* sizes in pixels */
	.width_pixels = 150,        /* minimum width of a menu */
	.height_pixels = 30,        /* height of a single menu item */
	.border_pixels = 2,         /* menu border */
	.separator_pixels = 2,      /* space around separator */
	.gap_pixels = 2,            /* gap between menus */

	/* text alignment, set to LeftAlignment, CenterAlignment or RightAlignment */
	.alignment = LeftAlignment,

	/*
	 * The variables below cannot be set by X resources.
	 * Their values must be less than .height_pixels.
	 */

	/* geometry of the right-pointing isoceles triangle for submenus */
	.triangle_width = 3,
	.triangle_height = 7,

	/* the icon size is equal to .height_pixels - .iconpadding * 2 */
	.iconpadding = 2,

	/* area around the icon, the triangle and the separator */
	.horzpadding = 8,
};

/*
 * KEYBINDINGS
 *
 * Look at your /usr/include/X11/keysymdef.h  (or the equivalent file
 * in your system) for a list of key symbol constants, and change the
 * macros below accordingly.  All key symbol constants begin with the
 * prefix XK_.
 *
 * For example, to use vim-like key bindings, set KEYSYMLEFT to XK_h,
 * KEYSYMDOWN to XK_j, KEYSYMUP to XK_k, etc.
 *
 * Note that the regular keys like ArrowUp, ArrowDown, Tab, Home, etc
 * will ALWAYS work, so you do not need to set them.
 *
 * If you do not want to set a key binding, keep it with the value of
 * XK_VoidSymbol
 */
#define KSYMFIRST   XK_VoidSymbol       /* select first item */
#define KSYMLAST    XK_VoidSymbol       /* select last item */
#define KSYMUP      XK_VoidSymbol       /* select previous item */
#define KSYMDOWN    XK_VoidSymbol       /* select next item */
#define KSYMLEFT    XK_VoidSymbol       /* close current menu */
#define KSYMRIGHT   XK_VoidSymbol       /* enter selected item */
