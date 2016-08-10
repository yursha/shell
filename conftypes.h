/* conftypes.h -- defines for build and host system. */

#if !defined(_CONFTYPES_H_)
#define _CONFTYPES_H_

/* Placeholder for future modifications if cross-compiling or building a
   `fat' binary, e.g. on Apple Rhapsody.  These values are used in multiple
   files, so they appear here. */
#if !defined(RHAPSODY) && !defined(MACOSX)
#define HOSTTYPE CONF_HOSTTYPE
#define OSTYPE CONF_OSTYPE
#define MACHTYPE CONF_MACHTYPE
#else /* RHAPSODY */
#if defined(__powerpc__) || defined(__ppc__)
#define HOSTTYPE "powerpc"
#elif defined(__i386__)
#define HOSTTYPE "i386"
#else
#define HOSTTYPE CONF_HOSTTYPE
#endif

#define OSTYPE CONF_OSTYPE
#define VENDOR CONF_VENDOR

#define MACHTYPE HOSTTYPE "-" VENDOR "-" OSTYPE
#endif /* RHAPSODY */

#ifndef HOSTTYPE
#define HOSTTYPE "unknown"
#endif

#ifndef OSTYPE
#define OSTYPE "unknown"
#endif

#ifndef MACHTYPE
#define MACHTYPE "unknown"
#endif

#endif /* _CONFTYPES_H_ */
