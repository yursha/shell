/* alias.h -- structure definitions. */

#if !defined(_ALIAS_H_)
#define _ALIAS_H_

#include "stdc.h"

#include "hashlib.h"

typedef struct alias {
  char *name;
  char *value;
  char flags;
} alias_t;

/* Values for `flags' member of struct alias. */
#define AL_EXPANDNEXT 0x1
#define AL_BEINGEXPANDED 0x2

/* The list of known aliases. */
extern HASH_TABLE *aliases;

extern void initialize_aliases(void);

/* Scan the list of aliases looking for one with NAME.  Return NULL
   if the alias doesn't exist, else a pointer to the alias. */
extern alias_t *find_alias(char *);

/* Return the value of the alias for NAME, or NULL if there is none. */
extern char *get_alias_value(char *);

/* Make a new alias from NAME and VALUE.  If NAME can be found,
   then replace its value. */
extern void add_alias(char *, char *);

/* Remove the alias with name NAME from the alias list.  Returns
   the index of the removed alias, or -1 if the alias didn't exist. */
extern int remove_alias(char *);

/* Remove all aliases. */
extern void delete_all_aliases(void);

/* Return an array of all defined aliases. */
extern alias_t **all_aliases(void);

/* Expand a single word for aliases. */
extern char *alias_expand_word(char *);

/* Return a new line, with any aliases expanded. */
extern char *alias_expand(char *);

#endif /* _ALIAS_H_ */
