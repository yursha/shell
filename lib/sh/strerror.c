/* strerror.c - string corresponding to a particular value of errno. */

#include <config.h>

#if !defined(HAVE_STRERROR)

#include <bashtypes.h>
#if defined(HAVE_SYS_PARAM_H)
#include <sys/param.h>
#endif

#if defined(HAVE_UNISTD_H)
#include <unistd.h>
#endif

#include <stdio.h>
#include <errno.h>

#include <shell.h>

#if !defined(errno)
extern int errno;
#endif /* !errno */

/* Return a string corresponding to the error number E.  From
   the ANSI C spec. */
#if defined(strerror)
#undef strerror
#endif

static char *errbase = "Unknown system error ";

char *strerror(e) int e;
{
  static char emsg[40];
#if defined(HAVE_SYS_ERRLIST)
  extern int sys_nerr;
  extern char *sys_errlist[];

  if (e > 0 && e < sys_nerr)
    return (sys_errlist[e]);
  else
#endif /* HAVE_SYS_ERRLIST */
      {
    char *z;

    z = itos(e);
    strcpy(emsg, errbase);
    strcat(emsg, z);
    free(z);
    return (&emsg[0]);
  }
}
#endif /* HAVE_STRERROR */
