/* rlconf.h -- readline configuration definitions */

#if !defined(_RLCONF_H_)
#define _RLCONF_H_

/* Define this if you want the vi-mode editing available. */
#define VI_MODE

/* Define this to get an indication of file type when listing completions. */
#define VISIBLE_STATS

/* Define this to get support for colors when listing completions and in
   other places. */
#define COLOR_SUPPORT

/* This definition is needed by readline.c, rltty.c, and signals.c. */
/* If on, then readline handles signals in a way that doesn't suck. */
#define HANDLE_SIGNALS

/* Ugly but working hack for binding prefix meta. */
#define PREFIX_META_HACK

/* The next-to-last-ditch effort file name for a user-specific init file. */
#define DEFAULT_INPUTRC "~/.inputrc"

/* The ultimate last-ditch filenname for an init file -- system-wide. */
#define SYS_INPUTRC "/etc/inputrc"

/* If defined, expand tabs to spaces. */
#define DISPLAY_TABS

/* If defined, use the terminal escape sequence to move the cursor forward
   over a character when updating the line rather than rewriting it. */
/* #define HACK_TERMCAP_MOTION */

/* The string inserted by the `insert comment' command. */
#define RL_COMMENT_BEGIN_DEFAULT "#"

/* Define this if you want code that allows readline to be used in an
   X `callback' style. */
#define READLINE_CALLBACKS

/* Define this if you want the cursor to indicate insert or overwrite mode. */
/* #define CURSOR_MODE */

/* Define this if you want to enable code that talks to the Linux kernel
   tty auditing system. */
/* #define ENABLE_TTY_AUDIT_SUPPORT */

/* Defaults for the various editing mode indicators, inserted at the beginning
   of the last (maybe only) line of the prompt if show-mode-in-prompt is on */
#define RL_EMACS_MODESTR_DEFAULT "@"
#define RL_EMACS_MODESTR_DEFLEN 1

#define RL_VI_INS_MODESTR_DEFAULT "(ins)"
#define RL_VI_INS_MODESTR_DEFLEN 5
#define RL_VI_CMD_MODESTR_DEFAULT "(cmd)"
#define RL_VI_CMD_MODESTR_DEFLEN 5

#endif /* _RLCONF_H_ */
