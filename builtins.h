/* builtins.h -- What a builtin looks like, and where to find them. */

#include "config.h"

#if defined(HAVE_UNISTD_H)
#include <unistd.h>
#endif

#include "command.h"
#include "general.h"

#if defined(ALIAS)
#include "alias.h"
#endif

/* Flags describing various things about a builtin. */
#define BUILTIN_ENABLED 0x01 /* This builtin is enabled. */
#define BUILTIN_DELETED 0x02 /* This has been deleted with enable -d. */
#define STATIC_BUILTIN 0x04  /* This builtin is not dynamically loaded. */
#define SPECIAL_BUILTIN 0x08 /* This is a Posix `special' builtin. */
#define ASSIGNMENT_BUILTIN                          \
  0x10 /* This builtin takes assignment statements. \
          */
#define POSIX_BUILTIN \
  0x20 /* This builtins is special in the Posix command search order. */
#define LOCALVAR_BUILTIN 0x40 /* This builtin creates local variables */

#define BASE_INDENT 4

/* The thing that we build the array of builtins out of. */
struct builtin {
  char *name;                  /* The name that the user types. */
  sh_builtin_func_t *function; /* The address of the invoked function. */
  int flags;                   /* One of the #defines above. */
  char *const *long_doc;       /* NULL terminated array of strings. */
  const char *short_doc;       /* Short version of documentation. */
  char *handle;                /* for future use */
};

/* Found in builtins.c, created by builtins/mkbuiltins. */
extern int num_shell_builtins; /* Number of shell builtins. */
extern struct builtin static_shell_builtins[];
extern struct builtin *shell_builtins;
extern struct builtin *current_builtin;
