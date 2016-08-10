/* assoc.h -- definitions for the interface exported by assoc.c that allows
   the rest of the shell to manipulate associative array variables. */

#ifndef _ASSOC_H_
#define _ASSOC_H_

#include "stdc.h"
#include "hashlib.h"

#define assoc_empty(h) ((h)->nentries == 0)
#define assoc_num_elements(h) ((h)->nentries)

#define assoc_create(n) (hash_create((n)))

#define assoc_copy(h) (hash_copy((h), 0))

#define assoc_walk(h, f)	(hash_walk((h), (f))

extern void assoc_dispose(HASH_TABLE *);
extern void assoc_flush(HASH_TABLE *);

extern int assoc_insert(HASH_TABLE *, char *, char *);
extern void *assoc_replace(HASH_TABLE *, char *, char *);
extern void assoc_remove(HASH_TABLE *, char *);

extern char *assoc_reference(HASH_TABLE *, char *);

extern char *assoc_subrange(HASH_TABLE *, arrayind_t, arrayind_t, int, int);
extern char *assoc_patsub(HASH_TABLE *, char *, char *, int);
extern char *assoc_modcase(HASH_TABLE *, char *, int, int);

extern HASH_TABLE *assoc_quote(HASH_TABLE *);
extern HASH_TABLE *assoc_quote_escapes(HASH_TABLE *);
extern HASH_TABLE *assoc_dequote(HASH_TABLE *);
extern HASH_TABLE *assoc_dequote_escapes(HASH_TABLE *);
extern HASH_TABLE *assoc_remove_quoted_nulls(HASH_TABLE *);

extern char *assoc_to_assign(HASH_TABLE *, int);

extern WORD_LIST *assoc_to_word_list(HASH_TABLE *);
extern WORD_LIST *assoc_keys_to_word_list(HASH_TABLE *);

extern char *assoc_to_string(HASH_TABLE *, char *, int);
#endif /* _ASSOC_H_ */
