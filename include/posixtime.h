/* posixtime.h -- wrapper for time.h, sys/times.h mess. */

#ifndef _POSIXTIME_H_
#define _POSIXTIME_H_

/* include this after config.h */
/* Some systems require this, mostly for the definition of `struct timezone'.
   For example, Dynix/ptx has that definition in <time.h> rather than
      sys/time.h */
#if defined(TIME_WITH_SYS_TIME)
#include <sys/time.h>
#include <time.h>
#else
#if defined(HAVE_SYS_TIME_H)
#include <sys/time.h>
#else
#include <time.h>
#endif
#endif

#if !defined(HAVE_SYSCONF) || !defined(_SC_CLK_TCK)
#if !defined(CLK_TCK)
#if defined(HZ)
#define CLK_TCK HZ
#else
#define CLK_TCK 60 /* 60HZ */
#endif
#endif /* !CLK_TCK */
#endif /* !HAVE_SYSCONF && !_SC_CLK_TCK */

#endif /* _POSIXTIME_H_ */
