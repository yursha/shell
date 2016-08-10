/* zwrite - write contents of buffer to file descriptor, retrying on error */

#include <config.h>

#include <sys/types.h>

#if defined(HAVE_UNISTD_H)
#include <unistd.h>
#endif

#include <errno.h>

#if !defined(errno)
extern int errno;
#endif

/* Write NB bytes from BUF to file descriptor FD, retrying the write if
   it is interrupted.  We retry three times if we get a zero-length
   write.  Any other signal causes this function to return prematurely. */
int zwrite(fd, buf, nb) int fd;
char *buf;
size_t nb;
{
  int n, i, nt;

  for (n = nb, nt = 0;;) {
    i = write(fd, buf, n);
    if (i > 0) {
      n -= i;
      if (n <= 0) return nb;
      buf += i;
    } else if (i == 0) {
      if (++nt > 3) return (nb - n);
    } else if (errno != EINTR)
      return -1;
  }
}
