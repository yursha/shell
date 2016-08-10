/* xmalloc.h -- defines for the `x' memory allocation functions */


#if !defined(_XMALLOC_H_)
#define _XMALLOC_H_

#include "stdc.h"
#include "bashansi.h"

/* Allocation functions in xmalloc.c */
extern void * xmalloc(size_t);
extern void * xrealloc(void *, size_t);
extern void xfree(void *);

#if defined(USING_BASH_MALLOC) && !defined(DISABLE_MALLOC_WRAPPERS)
extern void * sh_xmalloc(size_t, const char *, int);
extern void * sh_xrealloc(void *, size_t, const char *, int);
extern void sh_xfree(void *, const char *, int);

#define xmalloc(x) sh_xmalloc((x), __FILE__, __LINE__)
#define xrealloc(x, n) sh_xrealloc((x), (n), __FILE__, __LINE__)
#define xfree(x) sh_xfree((x), __FILE__, __LINE__)

#ifdef free
#undef free
#endif
#define free(x) sh_xfree((x), __FILE__, __LINE__)
#endif /* USING_BASH_MALLOC */

#endif /* _XMALLOC_H_ */
