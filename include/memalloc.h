/* memalloc.h -- consolidate code for including alloca.h or malloc.h and
   defining alloca. */

#if !defined(_MEMALLOC_H_)
#define _MEMALLOC_H_

#if defined(sparc) && defined(sun) && !defined(HAVE_ALLOCA_H)
#define HAVE_ALLOCA_H
#endif

#if defined(__GNUC__) && !defined(HAVE_ALLOCA)
#define HAVE_ALLOCA
#endif

#if defined(HAVE_ALLOCA_H) && !defined(HAVE_ALLOCA) && !defined(C_ALLOCA)
#define HAVE_ALLOCA
#endif /* HAVE_ALLOCA_H && !HAVE_ALLOCA */

#if defined(__GNUC__) && !defined(C_ALLOCA)
#undef alloca
#define alloca __builtin_alloca
#else /* !__GNUC__ || C_ALLOCA */
#if defined(HAVE_ALLOCA_H) && !defined(C_ALLOCA)
#if defined(IBMESA)
#include <malloc.h>
#else /* !IBMESA */
#include <alloca.h>
#endif /* !IBMESA */
#else  /* !HAVE_ALLOCA_H || C_ALLOCA */
#if defined(__hpux) && defined(__STDC__) && !defined(alloca)
extern void *alloca();
#else
#if !defined(alloca)
#if defined(__STDC__)
extern void *alloca(size_t);
#else
extern char *alloca();
#endif /* !__STDC__ */
#endif /* !alloca */
#endif /* !__hpux || !__STDC__ && !alloca */
#endif /* !HAVE_ALLOCA_H || C_ALLOCA */
#endif /* !__GNUC__ || C_ALLOCA */

#endif /* _MEMALLOC_H_ */
