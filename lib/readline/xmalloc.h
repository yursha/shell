/* xmalloc.h -- memory allocation that aborts on errors. */


#if !defined(_XMALLOC_H_)
#define _XMALLOC_H_

#if defined(READLINE_LIBRARY)
#include "rlstdc.h"
#else
#include <readline/rlstdc.h>
#endif

extern void* xmalloc PARAMS((size_t));
extern void* xrealloc PARAMS((void *, size_t));
extern void xfree PARAMS((void *));

#endif /* _XMALLOC_H_ */
