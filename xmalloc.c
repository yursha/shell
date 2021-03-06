/* xmalloc.c -- safe versions of malloc and realloc */

#if defined(HAVE_CONFIG_H)
#include <config.h>
#endif

#include "bashtypes.h"
#include <stdio.h>

#if defined(HAVE_UNISTD_H)
#include <unistd.h>
#endif

#if defined(HAVE_STDLIB_H)
#include <stdlib.h>
#else
#include "ansi_stdlib.h"
#endif /* HAVE_STDLIB_H */

#include "error.h"

#if defined(HAVE_SBRK) && !HAVE_DECL_SBRK
extern char *sbrk();
#endif

static void *lbreak;
static int brkfound;
static size_t allocated;

/* **************************************************************** */
/*								    */
/*		   Memory Allocation and Deallocation.		    */
/*								    */
/* **************************************************************** */

#if defined(HAVE_SBRK)
#define FINDBRK()               \
  do {                          \
    if (brkfound == 0) {        \
      lbreak = (void *)sbrk(0); \
      brkfound++;               \
    }                           \
  } while (0)

static size_t findbrk() {
  FINDBRK();
  return (char *)sbrk(0) - (char *)lbreak;
}
#else
#define FINDBRK()
#endif

static void allocerr(func, bytes) const char *func;
size_t bytes;
{
#if defined(HAVE_SBRK)
  allocated = findbrk();
  fatal_error("%s: cannot allocate %lu bytes (%lu bytes allocated)", func,
              (unsigned long)bytes, (unsigned long)allocated);
#else
  fatal_error("%s: cannot allocate %lu bytes", func, (unsigned long)bytes);
#endif /* !HAVE_SBRK */
}

/* Return a pointer to free()able block of memory large enough
   to hold BYTES number of bytes.  If the memory cannot be allocated,
   print an error message and abort. */
void *xmalloc(bytes) size_t bytes;
{
  void *temp;

#if defined(DEBUG)
  if (bytes == 0) internal_warning("xmalloc: size argument is 0");
#endif

  FINDBRK();
  temp = malloc(bytes);

  if (temp == 0) allocerr("xmalloc", bytes);

  return (temp);
}

void *xrealloc(pointer, bytes) void *pointer;
size_t bytes;
{
  void *temp;

#if defined(DEBUG)
  if (bytes == 0) internal_warning("xrealloc: size argument is 0");
#endif

  FINDBRK();
  temp = pointer ? realloc(pointer, bytes) : malloc(bytes);

  if (temp == 0) allocerr("xrealloc", bytes);

  return (temp);
}

/* Use this as the function to call when adding unwind protects so we
   don't need to know what free() returns. */
void xfree(string) void *string;
{
  if (string) free(string);
}

#ifdef USING_BASH_MALLOC
#include <malloc/shmalloc.h>

static void sh_allocerr(func, bytes, file, line) const char *func;
size_t bytes;
char *file;
int line;
{
#if defined(HAVE_SBRK)
  allocated = findbrk();
  fatal_error("%s: %s:%d: cannot allocate %lu bytes (%lu bytes allocated)",
              func, file, line, (unsigned long)bytes, (unsigned long)allocated);
#else
  fatal_error("%s: %s:%d: cannot allocate %lu bytes", func, file, line,
              (unsigned long)bytes);
#endif /* !HAVE_SBRK */
}

void *sh_xmalloc(bytes, file, line) size_t bytes;
char *file;
int line;
{
  void *temp;

#if defined(DEBUG)
  if (bytes == 0)
    internal_warning("xmalloc: %s:%d: size argument is 0", file, line);
#endif

  FINDBRK();
  temp = sh_malloc(bytes, file, line);

  if (temp == 0) sh_allocerr("xmalloc", bytes, file, line);

  return (temp);
}

void *sh_xrealloc(pointer, bytes, file, line) void *pointer;
size_t bytes;
char *file;
int line;
{
  void *temp;

#if defined(DEBUG)
  if (bytes == 0)
    internal_warning("xrealloc: %s:%d: size argument is 0", file, line);
#endif

  FINDBRK();
  temp = pointer ? sh_realloc(pointer, bytes, file, line)
                 : sh_malloc(bytes, file, line);

  if (temp == 0) sh_allocerr("xrealloc", bytes, file, line);

  return (temp);
}

void sh_xfree(string, file, line) void *string;
char *file;
int line;
{
  if (string) sh_free(string, file, line);
}
#endif
