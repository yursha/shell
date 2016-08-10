/* hashcmd.h - Common defines for hashing filenames. */


#include "stdc.h"
#include "hashlib.h"

#define FILENAME_HASH_BUCKETS 64 /* must be power of two */

extern HASH_TABLE *hashed_filenames;

typedef struct _pathdata {
  char *path; /* The full pathname of the file. */
  int flags;
} PATH_DATA;

#define HASH_RELPATH 0x01 /* this filename is a relative pathname. */
#define HASH_CHKDOT 0x02  /* check `.' since it was earlier in $PATH */

#define pathdata(x) ((PATH_DATA *)(x)->data)

extern void phash_create(void);
extern void phash_flush(void);

extern void phash_insert(char *, char *, int, int);
extern int phash_remove(const char *);
extern char *phash_search(const char *);
