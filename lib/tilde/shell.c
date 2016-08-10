/* shell.c -- tilde utility functions that are normally provided by
              bash when readline is linked as part of the shell. */


#if defined(HAVE_CONFIG_H)
#include <config.h>
#endif

#if defined(HAVE_UNISTD_H)
#include <unistd.h>
#endif /* HAVE_UNISTD_H */

#if defined(HAVE_STDLIB_H)
#include <stdlib.h>
#else
#include "ansi_stdlib.h"
#endif /* HAVE_STDLIB_H */

#if defined(HAVE_STRING_H)
#include <string.h>
#else
#include <strings.h>
#endif /* !HAVE_STRING_H */

#include <pwd.h>

#if !defined(HAVE_GETPW_DECLS)
extern struct passwd *getpwuid();
#endif /* !HAVE_GETPW_DECLS */

char *get_env_value(varname) char *varname;
{ return ((char *)getenv(varname)); }

/* If we're not using $HOME, assume that the passwd file information won't
   change while this shell instance is running. */
char *get_home_dir() {
  static char *home_dir = (char *)NULL;
  struct passwd *entry;

  if (home_dir) return (home_dir);

#if defined(HAVE_GETPWUID)
  entry = getpwuid(getuid());
  if (entry) home_dir = savestring(entry->pw_dir);
#endif

#if defined(HAVE_GETPWENT)
  endpwent(); /* some systems need this */
#endif

  return (home_dir);
}
