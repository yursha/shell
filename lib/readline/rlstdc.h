/* stdc.h -- macros to make source compile on both ANSI C and K&R C compilers.
 */


#if !defined(_RL_STDC_H_)
#define _RL_STDC_H_

/* Adapted from BSD /usr/include/sys/cdefs.h. */

/* A function can be defined using prototypes and compile on both ANSI C
   and traditional C compilers with something like this:
        extern char *func PARAMS((char *, char *, int)); */

#if !defined(PARAMS)
#if defined(__STDC__) || defined(__GNUC__) || defined(__cplusplus)
#define PARAMS(protos) protos
#else
#define PARAMS(protos) ()
#endif
#endif

#ifndef __attribute__
#if __GNUC__ < 2 || (__GNUC__ == 2 && __GNUC_MINOR__ < 8)
#define __attribute__(x)
#endif
#endif

/* Moved from config.h.in because readline.h:rl_message depends on these
   defines. */
#if defined(__STDC__) && defined(HAVE_STDARG_H)
#define PREFER_STDARG
#define USE_VARARGS
#else
#if defined(HAVE_VARARGS_H)
#define PREFER_VARARGS
#define USE_VARARGS
#endif
#endif

#endif /* !_RL_STDC_H_ */
