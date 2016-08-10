/* rltty.h - tty driver-related definitions used by some library files. */


#if !defined(_RLTTY_H_)
#define _RLTTY_H_

/* Posix systems use termios and the Posix signal functions. */
#if defined(TERMIOS_TTY_DRIVER)
#include <termios.h>
#endif /* TERMIOS_TTY_DRIVER */

/* System V machines use termio. */
#if defined(TERMIO_TTY_DRIVER)
#include <termio.h>
#if !defined(TCOON)
#define TCOON 1
#endif
#endif /* TERMIO_TTY_DRIVER */

/* Other (BSD) machines use sgtty. */
#if defined(NEW_TTY_DRIVER)
#include <sgtty.h>
#endif

#include "rlwinsize.h"

/* Define _POSIX_VDISABLE if we are not using the `new' tty driver and
   it is not already defined.  It is used both to determine if a
   special character is disabled and to disable certain special
   characters.  Posix systems should set to 0, USG systems to -1. */
#if !defined(NEW_TTY_DRIVER) && !defined(_POSIX_VDISABLE)
#if defined(_SVR4_VDISABLE)
#define _POSIX_VDISABLE _SVR4_VDISABLE
#else
#if defined(_POSIX_VERSION)
#define _POSIX_VDISABLE 0
#else /* !_POSIX_VERSION */
#define _POSIX_VDISABLE -1
#endif /* !_POSIX_VERSION */
#endif /* !_SVR4_DISABLE */
#endif /* !NEW_TTY_DRIVER && !_POSIX_VDISABLE */

typedef struct _rl_tty_chars {
  unsigned char t_eof;
  unsigned char t_eol;
  unsigned char t_eol2;
  unsigned char t_erase;
  unsigned char t_werase;
  unsigned char t_kill;
  unsigned char t_reprint;
  unsigned char t_intr;
  unsigned char t_quit;
  unsigned char t_susp;
  unsigned char t_dsusp;
  unsigned char t_start;
  unsigned char t_stop;
  unsigned char t_lnext;
  unsigned char t_flush;
  unsigned char t_status;
} _RL_TTY_CHARS;

#endif /* _RLTTY_H_ */
