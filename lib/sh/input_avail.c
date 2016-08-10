/* input_avail.c -- check whether or not data is available for reading on a
                    specified file descriptor. */


#if defined(__TANDEM)
#include <floss.h>
#endif

#if defined(HAVE_CONFIG_H)
#include <config.h>
#endif

#include <sys/types.h>
#include <fcntl.h>
#if defined(HAVE_SYS_FILE_H)
#include <sys/file.h>
#endif /* HAVE_SYS_FILE_H */

#if defined(HAVE_UNISTD_H)
#include <unistd.h>
#endif /* HAVE_UNISTD_H */

#include "bashansi.h"

#include "posixselect.h"

#if defined(FIONREAD_IN_SYS_IOCTL)
#include <sys/ioctl.h>
#endif

#include <stdio.h>
#include <errno.h>

#if !defined(errno)
extern int errno;
#endif /* !errno */

#if !defined(O_NDELAY) && defined(O_NONBLOCK)
#define O_NDELAY O_NONBLOCK /* Posix style */
#endif

/* Return >= 1 if select/FIONREAD indicates data available for reading on
   file descriptor FD; 0 if no data available.  Return -1 on error. */
int input_avail(fd) int fd;
{
  int result, chars_avail;
#if defined(HAVE_SELECT)
  fd_set readfds, exceptfds;
  struct timeval timeout;
#endif

  if (fd < 0) return -1;

  chars_avail = 0;

#if defined(HAVE_SELECT)
  FD_ZERO(&readfds);
  FD_ZERO(&exceptfds);
  FD_SET(fd, &readfds);
  FD_SET(fd, &exceptfds);
  timeout.tv_sec = 0;
  timeout.tv_usec = 0;
  result = select(fd + 1, &readfds, (fd_set *)NULL, &exceptfds, &timeout);
  return ((result <= 0) ? 0 : 1);

#endif

  result = -1;
#if defined(FIONREAD)
  errno = 0;
  result = ioctl(fd, FIONREAD, &chars_avail);
  if (result == -1 && errno == EIO) return -1;
  return (chars_avail);
#endif

  return 0;
}
