/* watch.c - watchpoint functions for malloc */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>

#include "imalloc.h"

#ifdef MALLOC_WATCH
#include "watch.h"

#define WATCH_MAX 32

int _malloc_nwatch;
static void *_malloc_watch_list[WATCH_MAX];

static void watch_warn(addr, file, line, type, data) void *addr;
const char *file;
int line, type;
unsigned long data;
{
  char *tag;

  if (type == W_ALLOC)
    tag = "allocated";
  else if (type == W_FREE)
    tag = "freed";
  else if (type == W_REALLOC)
    tag = "requesting resize";
  else if (type == W_RESIZED)
    tag = "just resized";
  else
    tag = "bug: unknown operation";

  fprintf(stderr, "malloc: watch alert: %p %s ", addr, tag);
  if (data != (unsigned long)-1) fprintf(stderr, "(size %lu) ", data);
  fprintf(stderr, "from '%s:%d'\n", file ? file : "unknown", line);
}

void _malloc_ckwatch(addr, file, line, type, data) void *addr;
const char *file;
int line, type;
unsigned long data;
{
  register int i;

  for (i = _malloc_nwatch - 1; i >= 0; i--) {
    if (_malloc_watch_list[i] == addr) {
      watch_warn(addr, file, line, type, data);
      return;
    }
  }
}
#endif /* MALLOC_WATCH */

void *malloc_watch(addr) void *addr;
{
  register int i;
  void *ret;

  if (addr == 0) return addr;
  ret = (void *)0;

#ifdef MALLOC_WATCH
  for (i = _malloc_nwatch - 1; i >= 0; i--) {
    if (_malloc_watch_list[i] == addr) break;
  }
  if (i < 0) {
    if (_malloc_nwatch == WATCH_MAX) /* full, take out first */
        {
      ret = _malloc_watch_list[0];
      _malloc_nwatch--;
      for (i = 0; i < _malloc_nwatch; i++)
        _malloc_watch_list[i] = _malloc_watch_list[i + 1];
    }
    _malloc_watch_list[_malloc_nwatch++] = addr;
  }
#endif

  return ret;
}

/* Remove a watchpoint set on ADDR.  If ADDR is NULL, remove all
   watchpoints.  Returns ADDR if everything went OK, NULL if ADDR was
   not being watched. */
void *malloc_unwatch(addr) void *addr;
{
#ifdef MALLOC_WATCH
  register int i;

  if (addr == 0) {
    for (i = 0; i < _malloc_nwatch; i++) _malloc_watch_list[i] = (void *)0;
    _malloc_nwatch = 0;
    return ((void *)0);
  } else {
    for (i = 0; i < _malloc_nwatch; i++) {
      if (_malloc_watch_list[i] == addr) break;
    }
    if (i == _malloc_nwatch) return ((void *)0); /* not found */
    /* shuffle everything from i+1 to end down 1 */
    _malloc_nwatch--;
    for (; i < _malloc_nwatch; i++)
      _malloc_watch_list[i] = _malloc_watch_list[i + 1];
    return addr;
  }
#else
  return ((void *)0);
#endif
}
