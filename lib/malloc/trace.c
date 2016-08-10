/* trace.c - tracing functions for malloc */


#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#include "imalloc.h"

extern int malloc_trace;

static int _mtrace_verbose = 0;

#ifdef MALLOC_TRACE

extern FILE *_imalloc_fopen(char *, char *, char *, char *, size_t);

FILE *_mtrace_fp = NULL;
extern char _malloc_trace_buckets[];

void mtrace_alloc(tag, mem, size, file, line) const char *tag;
void * mem;
size_t size;
const char *file;
int line;
{
  if (_mtrace_fp == NULL) _mtrace_fp = stderr;

  if (_mtrace_verbose)
    fprintf(_mtrace_fp, "alloc: %s: %p (%zu bytes) from '%s:%d'\n", tag, mem,
            size, file ? file : "unknown", line);
  else
    fprintf(_mtrace_fp, "alloc:%p:%zu:%s:%d\n", mem, size,
            file ? file : "unknown", line);
}

void mtrace_free(mem, size, file, line) void * mem;
int size;
const char *file;
int line;
{
  if (_mtrace_fp == NULL) _mtrace_fp = stderr;

  if (_mtrace_verbose)
    fprintf(_mtrace_fp, "free: %p (%d bytes) from '%s:%d'\n", mem, size,
            file ? file : "unknown", line);
  else
    fprintf(_mtrace_fp, "free:%p:%d:%s:%d\n", mem, size,
            file ? file : "unknown", line);
}
#endif /* MALLOC_TRACE */

int malloc_set_trace(n) int n;
{
  int old;

  old = malloc_trace;
  malloc_trace = n;
  _mtrace_verbose = (n > 1);
  return old;
}

void malloc_set_tracefp(fp) FILE *fp;
{
#ifdef MALLOC_TRACE
  _mtrace_fp = fp ? fp : stderr;
#endif
}

void malloc_trace_bin(n) int n;
{
#ifdef MALLOC_TRACE
  _malloc_trace_buckets[n] = 1;
#endif
}

#define TRACEROOT "/var/tmp/maltrace/trace."

void malloc_set_tracefn(s, fn) char *s;
char *fn;
{
#ifdef MALLOC_TRACE
  FILE *fp;
  char defname[sizeof(TRACEROOT) + 64];

  fp = _imalloc_fopen(s, fn, TRACEROOT, defname, sizeof(defname));
  if (fp) malloc_set_tracefp(fp);
#endif
}
