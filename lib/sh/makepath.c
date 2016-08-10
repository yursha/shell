/* makepath.c - glue PATH and DIR together into a full pathname. */


#include <config.h>

#if defined(HAVE_UNISTD_H)
#include <unistd.h>
#endif

#include <bashansi.h>
#include "shell.h"

#include <tilde/tilde.h>

#ifndef NULL
#define NULL 0
#endif

/* MAKE SURE THESE AGREE WITH ../../externs.h. */

#ifndef MP_DOTILDE
#define MP_DOTILDE 0x01
#define MP_DOCWD 0x02
#define MP_RMDOT 0x04
#define MP_IGNDOT 0x08
#endif

extern char *get_working_directory(char *);

static char *nullpath = "";

/* Take PATH, an element from, e.g., $CDPATH, and DIR, a directory name,
   and paste them together into PATH/DIR.  Tilde expansion is performed on
   PATH if (flags & MP_DOTILDE) is non-zero.  If PATH is NULL or the empty
   string, it is converted to the current directory.  A full pathname is
   used if (flags & MP_DOCWD) is non-zero, otherwise `./' is used.  If
   (flags & MP_RMDOT) is non-zero, any `./' is removed from the beginning
   of DIR.  If (flags & MP_IGNDOT) is non-zero, a PATH that is "." or "./"
   is ignored. */

#define MAKEDOT()               \
  do {                          \
    xpath = (char *)xmalloc(2); \
    xpath[0] = '.';             \
    xpath[1] = '\0';            \
    pathlen = 1;                \
  } while (0)

char *sh_makepath(path, dir, flags) const char *path, *dir;
int flags;
{
  int dirlen, pathlen;
  char *ret, *xpath, *xdir, *r, *s;

  if (path == 0 || *path == '\0') {
    if (flags & MP_DOCWD) {
      xpath = get_working_directory("sh_makepath");
      if (xpath == 0) {
        ret = get_string_value("PWD");
        if (ret) xpath = savestring(ret);
      }
      if (xpath == 0)
        MAKEDOT();
      else
        pathlen = strlen(xpath);
    } else
      MAKEDOT();
  } else if ((flags & MP_IGNDOT) && path[0] == '.' &&
             (path[1] == '\0' || (path[1] == '/' && path[2] == '\0'))) {
    xpath = nullpath;
    pathlen = 0;
  } else {
    xpath = ((flags & MP_DOTILDE) && *path == '~') ? bash_tilde_expand(path, 0)
                                                   : (char *)path;
    pathlen = strlen(xpath);
  }

  xdir = (char *)dir;
  dirlen = strlen(xdir);
  if ((flags & MP_RMDOT) && dir[0] == '.' && dir[1] == '/') {
    xdir += 2;
    dirlen -= 2;
  }

  r = ret = (char *)xmalloc(2 + dirlen + pathlen);
  s = xpath;
  while (*s) *r++ = *s++;
  if (s > xpath && s[-1] != '/') *r++ = '/';
  s = xdir;
  while (*r++ = *s++)
    ;
  if (xpath != path && xpath != nullpath) free(xpath);
  return (ret);
}
