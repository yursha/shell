/* zcatfd - copy contents of file descriptor to another */

#include <config.h>

#include <sys/types.h>

#if defined(HAVE_UNISTD_H)
#include <unistd.h>
#endif

#include <errno.h>

#include <stdc.h>

#if !defined(errno)
extern int errno;
#endif

extern ssize_t zread(int, char *, size_t);
extern int zwrite(int, char *, ssize_t);

/* Dump contents of file descriptor FD to OFD.  FN is the filename for
   error messages (not used right now). */
int zcatfd(fd, ofd, fn) int fd, ofd;
char *fn;
{
  ssize_t nr;
  int rval;
  char lbuf[128];

  rval = 0;
  while (1) {
    nr = zread(fd, lbuf, sizeof(lbuf));
    if (nr == 0)
      break;
    else if (nr < 0) {
      rval = -1;
      break;
    } else if (zwrite(ofd, lbuf, nr) < 0) {
      rval = -1;
      break;
    }
  }

  return rval;
}
