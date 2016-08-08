/* stdc.h -- macros to make source compile on both ANSI C and K&R C
   compilers. */

#if !defined(_STDC_H_)
#define _STDC_H_

/* Fortify, at least, has trouble with this definition */
#if defined(HAVE_STRINGIZE)
#define CPP_STRING(x) #x
#else
#define CPP_STRING(x) "x"
#endif

#if !defined(__STDC__)

#if defined(__GNUC__) /* gcc with -traditional */
#if !defined(signed)
#define signed __signed
#endif
#if !defined(volatile)
#define volatile __volatile
#endif
#else /* !__GNUC__ */
#if !defined(inline)
#define inline
#endif
#if !defined(signed)
#define signed
#endif
#if !defined(volatile)
#define volatile
#endif
#endif /* !__GNUC__ */

#endif /* !__STDC__ */

#ifndef __attribute__
#if __GNUC__ < 2 || (__GNUC__ == 2 && __GNUC_MINOR__ < 8)
#define __attribute__(x)
#endif
#endif

/* For those situations when gcc handles inlining a particular function but
   other compilers complain. */
#ifdef __GNUC__
#define INLINE inline
#else
#define INLINE
#endif

#if defined(PREFER_STDARG)
#define SH_VA_START(va, arg) va_start(va, arg)
#else
#define SH_VA_START(va, arg) va_start(va)
#endif

#endif /* !_STDC_H_ */
