/* pathexp.h -- The shell interface to the globbing library. */


#if !defined(_PATHEXP_H_)
#define _PATHEXP_H_

#if defined(USE_POSIX_GLOB_LIBRARY)
#define GLOB_FAILED(glist) !(glist)
#else /* !USE_POSIX_GLOB_LIBRARY */
#define GLOB_FAILED(glist) (glist) == (char **) & glob_error_return
extern int noglob_dot_filenames;
extern char *glob_error_return;
#endif /* !USE_POSIX_GLOB_LIBRARY */

/* Flag values for quote_string_for_globbing */
#define QGLOB_CVTNULL 0x01  /* convert QUOTED_NULL strings to '\0' */
#define QGLOB_FILENAME 0x02 /* do correct quoting for matching filenames */
#define QGLOB_REGEXP 0x04   /* quote an ERE for regcomp/regexec */

#if defined(EXTENDED_GLOB)
/* Flags to OR with other flag args to strmatch() to enabled the extended
   pattern matching. */
#define FNMATCH_EXTFLAG (extended_glob ? FNM_EXTMATCH : 0)
#else
#define FNMATCH_EXTFLAG 0
#endif /* !EXTENDED_GLOB */

#define FNMATCH_IGNCASE (match_ignore_case ? FNM_CASEFOLD : 0)
#define FNMATCH_NOCASEGLOB (glob_ignore_case ? FNM_CASEFOLD : 0)

extern int glob_dot_filenames;
extern int extended_glob;
extern int glob_star;
extern int match_ignore_case; /* doesn't really belong here */

extern int unquoted_glob_pattern_p(char *);

/* PATHNAME can contain characters prefixed by CTLESC; this indicates
   that the character is to be quoted.  We quote it here in the style
   that the glob library recognizes.  If flags includes QGLOB_CVTNULL,
   we change quoted null strings (pathname[0] == CTLNUL) into empty
   strings (pathname[0] == 0).  If this is called after quote removal
   is performed, (flags & QGLOB_CVTNULL) should be 0; if called when quote
   removal has not been done (for example, before attempting to match a
   pattern while executing a case statement), flags should include
   QGLOB_CVTNULL.  If flags includes QGLOB_FILENAME, appropriate quoting
   to match a filename should be performed. */
extern char *quote_string_for_globbing(const char *, int);

extern int glob_char_p(const char *);
extern char *quote_globbing_chars(const char *);

/* Call the glob library to do globbing on PATHNAME. */
extern char **shell_glob_filename(const char *);

/* Filename completion ignore.  Used to implement the "fignore" facility of
   tcsh, GLOBIGNORE (like ksh-93 FIGNORE), and EXECIGNORE.

   It is passed a NULL-terminated array of (char *)'s that must be
   free()'d if they are deleted.  The first element (names[0]) is the
   least-common-denominator string of the matching patterns (i.e.
   u<TAB> produces names[0] = "und", names[1] = "under.c", names[2] =
   "undun.c", name[3] = NULL).  */

struct ign {
  char *val;
  int len, flags;
};

typedef int sh_iv_item_func_t(struct ign *);

struct ignorevar {
  char *varname;        /* FIGNORE, GLOBIGNORE, or EXECIGNORE */
  struct ign *ignores;  /* Store the ignore strings here */
  int num_ignores;      /* How many are there? */
  char *last_ignoreval; /* Last value of variable - cached for speed */
  sh_iv_item_func_t
      *item_func; /* Called when each item is parsed from $`varname' */
};

extern void setup_ignore_patterns(struct ignorevar *);

extern void setup_glob_ignore(char *);
extern int should_ignore_glob_matches(void);
extern void ignore_glob_matches(char **);

#endif
