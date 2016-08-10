/* savestring.c - function version of savestring for backwards compatibility */


#define READLINE_LIBRARY

#include <config.h>
#ifdef HAVE_STRING_H
#include <string.h>
#endif
#include "xmalloc.h"

/* Backwards compatibility, now that savestring has been removed from
   all `public' readline header files. */
char *savestring(s) const char *s;
{
  char *ret;

  ret = (char *)xmalloc(strlen(s) + 1);
  strcpy(ret, s);
  return ret;
}
