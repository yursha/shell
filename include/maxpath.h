/* maxpath.h - Find out what this system thinks PATH_MAX and NAME_MAX are. */

#if !defined(_MAXPATH_H_)
#define _MAXPATH_H_

/* These values are supposed to be in <limits.h> or one of the files
   it includes. */
#if defined(HAVE_LIMITS_H)
#include <limits.h>
#endif /* !HAVE_LIMITS_H */

/* If PATH_MAX is not defined, look for MAXPATHLEN */
#if !defined(PATH_MAX)
#if defined(HAVE_SYS_PARAM_H)
#include <sys/param.h>
#define maxpath_param_h
#endif
#if defined(MAXPATHLEN) && !defined(PATH_MAX)
#define PATH_MAX MAXPATHLEN
#endif /* MAXPATHLEN && !PATH_MAX */
#endif /* !PATH_MAX */

/* If NAME_MAX is not defined, look for MAXNAMLEN */
#if !defined(NAME_MAX)
#if defined(HAVE_SYS_PARAM_H) && !defined(maxpath_param_h)
#include <sys/param.h>
#endif
#if defined(MAXNAMLEN) && !defined(NAME_MAX)
#define NAME_MAX MAXNAMLEN
#endif /* MAXNAMLEN && !NAME_MAX */
#endif /* !NAME_MAX */

/* Default POSIX values */
#if !defined(PATH_MAX) && defined(_POSIX_PATH_MAX)
#define PATH_MAX _POSIX_PATH_MAX
#endif

#if !defined(NAME_MAX) && defined(_POSIX_NAME_MAX)
#define NAME_MAX _POSIX_NAME_MAX
#endif

/* Default values */
#if !defined(PATH_MAX)
#define PATH_MAX 1024
#endif

#if !defined(NAME_MAX)
#define NAME_MAX 14
#endif

#if PATH_MAX < 1024
#undef PATH_MAX
#define PATH_MAX 1024
#endif

#endif /* _MAXPATH_H_ */
