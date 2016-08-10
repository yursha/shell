/* zgetline - read a line of input from a specified file descriptor and return
              a pointer to a newly-allocated buffer containing the data. */


#include <config.h>

#include <sys/types.h>

#if defined(HAVE_UNISTD_H)
#include <unistd.h>
#endif

#include <errno.h>
#include "xmalloc.h"

#if !defined(errno)
extern int errno;
#endif

extern ssize_t zread(int, char *, size_t);
extern ssize_t zreadc(int, char *);
extern ssize_t zreadintr(int, char *, size_t);
extern ssize_t zreadcintr(int, char *);

typedef ssize_t breadfunc_t(int, char *, size_t);
typedef ssize_t creadfunc_t(int, char *);

/* Initial memory allocation for automatic growing buffer in zreadlinec */
#define GET_LINE_INITIAL_ALLOCATION 16

/* Derived from GNU libc's getline.
   The behavior is almost the same as getline. See man getline.
   The differences are
        (1) using file descriptor instead of FILE *;
        (2) the order of arguments: the file descriptor comes first;
        (3) the addition of a fourth argument, DELIM; sets the delimiter to
            be something other than newline if desired.  If setting DELIM,
            the next argument should be 1; and
        (4) the addition of a fifth argument, UNBUFFERED_READ; this argument
            controls whether get_line uses buffering or not to get a byte data
            from FD. get_line uses zreadc if UNBUFFERED_READ is zero; and
            uses zread if UNBUFFERED_READ is non-zero.

   Returns number of bytes read or -1 on error. */

ssize_t zgetline(fd, lineptr, n, delim, unbuffered_read) int fd;
char **lineptr;
size_t *n;
int delim;
int unbuffered_read;
{
  int nr, retval;
  char *line, c;

  if (lineptr == 0 || n == 0 || (*lineptr == 0 && *n != 0)) return -1;

  nr = 0;
  line = *lineptr;

  while (1) {
    retval = unbuffered_read ? zread(fd, &c, 1) : zreadc(fd, &c);

    if (retval <= 0) {
      if (line && nr > 0) line[nr] = '\0';
      break;
    }

    if (nr + 2 >= *n) {
      size_t new_size;

      new_size = (*n == 0) ? GET_LINE_INITIAL_ALLOCATION : *n * 2;
      line = (*n >= new_size) ? NULL : xrealloc(*lineptr, new_size);

      if (line) {
        *lineptr = line;
        *n = new_size;
      } else {
        if (*n > 0) {
          (*lineptr)[*n - 1] = '\0';
          nr = *n - 2;
        }
        break;
      }
    }

    line[nr] = c;
    nr++;

    if (c == delim) {
      line[nr] = '\0';
      break;
    }
  }

  return nr - 1;
}
