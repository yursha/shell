/* bashjmp.h -- wrapper for setjmp.h with necessary bash definitions. */

#ifndef _BASHJMP_H_
#define _BASHJMP_H_

#include <setjmp.h>

extern sigjmp_buf top_level;
extern sigjmp_buf subshell_top_level;
extern sigjmp_buf return_catch; /* used by `return' builtin */

extern int no_longjmp_on_fatal_error;

#define SHFUNC_RETURN() siglongjmp(return_catch, 1)

#define COPY_PROCENV(old, save) \
  xbcopy((char *)old, (char *)save, sizeof(sigjmp_buf));

/* Values for the second argument to siglongjmp. */
#define NOT_JUMPED 0 /* Not returning from a siglongjmp. */
#define FORCE_EOF 1  /* We want to stop parsing. */
#define DISCARD 2    /* Discard current command. */
#define EXITPROG 3   /* Unconditionally exit the program now. */
#define ERREXIT 4    /* Exit due to error condition */
#define SIGEXIT 5    /* Exit due to fatal terminating signal */

#endif /* _BASHJMP_H_ */
