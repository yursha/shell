/* zmapfd - read contents of file descriptor into a newly-allocated buffer */


#include <config.h>

#include <sys/types.h>

#if defined(HAVE_UNISTD_H)
#include <unistd.h>
#endif

#include <errno.h>

#include "bashansi.h"
#include "command.h"
#include "general.h"

#if !defined(errno)
extern int errno;
#endif

extern ssize_t zread(int, char *, size_t);

/* Dump contents of file descriptor FD to *OSTR.  FN is the filename for
   error messages (not used right now). */
int zmapfd(fd, ostr, fn) int fd;
char **ostr;
char *fn;
{
  ssize_t nr;
  int rval;
  char lbuf[128];
  char *result;
  int rsize, rind;

  rval = 0;
  result = (char *)xmalloc(rsize = 64);
  rind = 0;

  while (1) {
    nr = zread(fd, lbuf, sizeof(lbuf));
    if (nr == 0) {
      rval = rind;
      break;
    } else if (nr < 0) {
      free(result);
      if (ostr) *ostr = (char *)NULL;
      return -1;
    }

    RESIZE_MALLOCED_BUFFER(result, rind, nr, rsize, 128);
    memcpy(result + rind, lbuf, nr);
    rind += nr;
  }

  RESIZE_MALLOCED_BUFFER(result, rind, 1, rsize, 128);
  result[rind] = '\0';

  if (ostr)
    *ostr = result;
  else
    free(result);

  return rval;
}
