/* tcap.h -- termcap library functions and variables. */

#if !defined(_RLTCAP_H_)
#define _RLTCAP_H_

#if defined(HAVE_CONFIG_H)
#include "config.h"
#endif

#if defined(HAVE_TERMCAP_H)
#if defined(__linux__) && !defined(SPEED_T_IN_SYS_TYPES)
#include "rltty.h"
#endif
#include <termcap.h>
#elif defined(HAVE_NCURSES_TERMCAP_H)
#include <ncurses/termcap.h>
#else

/* On Solaris2, sys/types.h #includes sys/reg.h, which #defines PC.
   Unfortunately, PC is a global variable used by the termcap library. */
#ifdef PC
#undef PC
#endif

extern char PC;
extern char *UP, *BC;

extern short ospeed;

extern int tgetent();
extern int tgetflag();
extern int tgetnum();
extern char *tgetstr();

extern int tputs();

extern char *tgoto();

#endif /* HAVE_TERMCAP_H */

#endif /* !_RLTCAP_H_ */
