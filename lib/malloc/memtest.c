/*
 * malloc test program.
 *
 * to build:
 * 	make x.o
 * 	gcc -g -o x x.o xmalloc.o lib/malloc/libmalloc.a
 */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#define USING_BASH_MALLOC
#define HAVE_STRINGIZE

#include "xmalloc.h"

int interrupt_immediately = 0;

static char xp[64];

main(int c, char **v) {
  char *p;

  malloc_set_register(1);

#if 0
	free (xp);	/* free unallocated memory */
#endif

#if 0
	p = xrealloc(xp, 128);
#endif

#if 0
	/*
	 * request an amount so that the bucket changes when the malloc
	 * overhead is added to the requested size.  This had better
	 * succeed.
	 */
	p = xmalloc(25);
	p[0] = 'a';
	p[1] = '\0';
	free(p);	/* sanity check on underflow checks in free() */
#endif

#if 0
	p = xmalloc(28);
	/* This works for little-endian machines like i386. */
	p[-4] = '\7';	/* underflow */
	p = xrealloc(p, 128);	/* realloc corrupted memory */
#endif

#if 0
	p = xmalloc(28);
	/* This works for little-endian machines like i386. */
	p[-4] = '\7';	/* underflow */
	free(p);
#endif

#if 0
	p = xmalloc(2);
	free(p);
	free(p); 	/* duplicate free */
#endif

#if 0
	p = xmalloc(32);
	free(p);
	p = xrealloc(p, 128);	/* realloc freed mem */
#endif

#if 0
	p = xmalloc(64);
	p[64] = '\0';
	p = xrealloc(p, 128);	/* overflow */
#endif

#if 0
	p = xmalloc(64);
	p[64] = '\0';
	free(p);		/* overflow */
#endif

#if 0
	p = xmalloc(64);
	p[-1] = 'a';
	free (p);		/* underflow */
#endif

#if 0
	p = xmalloc(64);
	p[-1] = 'a';
	p = xrealloc(p, 129);	/* underflow */
#endif

  mregister_dump_table();
  exit(0);
}

void fatal_error(const char *format, ...) {
  va_list args;

  fprintf(stderr, "malloc-test: ");
  va_start(args, format);
  vfprintf(stderr, format, args);
  fprintf(stderr, "\n");
  va_end(args);
  exit(2);
}

void programming_error(const char *format, ...) {
  va_list args;

  fprintf(stderr, "malloc-test: ");
  va_start(args, format);
  vfprintf(stderr, format, args);
  fprintf(stderr, "\n");
  va_end(args);

  abort();
}

int signal_is_trapped(int n) { return 0; }
