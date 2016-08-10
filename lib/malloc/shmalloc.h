/* Functions (currently) for use by the shell to do malloc debugging and
   tracking. */

#ifndef _SH_MALLOC_H
#define _SH_MALLOC_H

extern void * sh_malloc(size_t, const char *, int);
extern void * sh_realloc(void *, size_t, const char *, int);
extern void sh_free(void *, const char *, int);

extern void * sh_memalign(size_t, size_t, const char *, int);

extern void * sh_calloc(size_t, size_t, const char *, int);
extern void sh_cfree(void *, const char *, int);

extern void * sh_valloc(size_t, const char *, int);

/* trace.c */
extern int malloc_set_trace(int);
extern void malloc_set_tracefp(); /* full prototype requires stdio.h */
extern void malloc_set_tracefn(char *, char *);

/* table.c */
extern void mregister_dump_table(void);
extern void mregister_table_init(void);
extern int malloc_set_register(int);

/* stats.c */
extern void print_malloc_stats(char *);
extern void fprint_malloc_stats(); /* full prototype requires stdio.h */
extern void trace_malloc_stats(char *, char *);

#endif
