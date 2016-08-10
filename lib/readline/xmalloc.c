/* xmalloc.c -- safe versions of malloc and realloc */


#define READLINE_LIBRARY

#if defined(HAVE_CONFIG_H)
#include <config.h>
#endif

#include <stdio.h>

#if defined(HAVE_STDLIB_H)
#include <stdlib.h>
#else
#include "ansi_stdlib.h"
#endif /* HAVE_STDLIB_H */

#include "xmalloc.h"

/* **************************************************************** */
/*								    */
/*		   Memory Allocation and Deallocation.		    */
/*								    */
/* **************************************************************** */

static void memory_error_and_abort(fname) char *fname;
{
  fprintf(stderr, "%s: out of virtual memory\n", fname);
  exit(2);
}

/* Return a pointer to free()able block of memory large enough
   to hold BYTES number of bytes.  If the memory cannot be allocated,
   print an error message and abort. */
void*
xmalloc(bytes) size_t bytes;
{
  void* temp;

  temp = malloc(bytes);
  if (temp == 0) memory_error_and_abort("xmalloc");
  return (temp);
}

void*
xrealloc(pointer, bytes) void* pointer;
size_t bytes;
{
  void* temp;

  temp = pointer ? realloc(pointer, bytes) : malloc(bytes);

  if (temp == 0) memory_error_and_abort("xrealloc");
  return (temp);
}
