/* unwind_prot.h - Macros and functions for hacking unwind protection. */

#if !defined(_UNWIND_PROT_H)
#define _UNWIND_PROT_H

extern void uwp_init(void);

/* Run a function without interrupts. */
extern void begin_unwind_frame(char *);
extern void discard_unwind_frame(char *);
extern void run_unwind_frame(char *);
extern void add_unwind_protect(); /* Not portable to arbitrary C99 hosts.  */
extern void remove_unwind_protect(void);
extern void run_unwind_protects(void);
extern void clear_unwind_protect_list(int);
extern int have_unwind_protects(void);
extern int unwind_protect_tag_on_stack(const char *);
extern void uwp_init(void);

/* Define for people who like their code to look a certain way. */
#define end_unwind_frame()

/* How to protect a variable.  */
#define unwind_protect_var(X) unwind_protect_mem((char *) & (X), sizeof(X))
extern void unwind_protect_mem(char *, int);

/* Backwards compatibility */
#define unwind_protect_int unwind_protect_var
#define unwind_protect_short unwind_protect_var
#define unwind_protect_string unwind_protect_var
#define unwind_protect_pointer unwind_protect_var
#define unwind_protect_jmp_buf unwind_protect_var

#endif /* _UNWIND_PROT_H */
