/* xfree.c -- safe version of free that ignores attempts to free NUL */


#define READLINE_LIBRARY

#if defined(HAVE_CONFIG_H)
#include <config.h>
#endif

#if defined(HAVE_STDLIB_H)
#include <stdlib.h>
#else
#include "ansi_stdlib.h"
#endif /* HAVE_STDLIB_H */

#include "xmalloc.h"

/* **************************************************************** */
/*								    */
/*		   Memory Deallocation.				    */
/*								    */
/* **************************************************************** */

/* Use this as the function to call when adding unwind protects so we
   don't need to know what free() returns. */
void xfree(string) void* string;
{
  if (string) free(string);
}
