/* arrayfunc.h -- declarations for miscellaneous array functions in arrayfunc.c
 */


#if !defined(_ARRAYFUNC_H_)
#define _ARRAYFUNC_H_

/* Must include variables.h before including this file. */

#if defined(ARRAY_VARS)

/* Flags for array_value_internal and callers array_value/get_array_value */
#define AV_ALLOWALL 0x001
#define AV_QUOTED 0x002
#define AV_USEIND 0x004
#define AV_USEVAL 0x008 /* XXX - should move this */

extern SHELL_VAR *convert_var_to_array(SHELL_VAR *);
extern SHELL_VAR *convert_var_to_assoc(SHELL_VAR *);

extern char *make_array_variable_value(SHELL_VAR *, arrayind_t, char *, char *,
                                       int);

extern SHELL_VAR *bind_array_variable(char *, arrayind_t, char *, int);
extern SHELL_VAR *bind_array_element(SHELL_VAR *, arrayind_t, char *, int);
extern SHELL_VAR *assign_array_element(char *, char *, int);

extern SHELL_VAR *bind_assoc_variable(SHELL_VAR *, char *, char *, char *, int);

extern SHELL_VAR *find_or_make_array_variable(char *, int);

extern SHELL_VAR *assign_array_from_string(char *, char *, int);
extern SHELL_VAR *assign_array_var_from_word_list(SHELL_VAR *, WORD_LIST *,
                                                  int);

extern WORD_LIST *expand_compound_array_assignment(SHELL_VAR *, char *, int);
extern void assign_compound_array_list(SHELL_VAR *, WORD_LIST *, int);
extern SHELL_VAR *assign_array_var_from_string(SHELL_VAR *, char *, int);

extern int unbind_array_element(SHELL_VAR *, char *);
extern int skipsubscript(const char *, int, int);

extern void print_array_assignment(SHELL_VAR *, int);
extern void print_assoc_assignment(SHELL_VAR *, int);

extern arrayind_t array_expand_index(SHELL_VAR *, char *, int);
extern int valid_array_reference(char *, int);
extern char *array_value(char *, int, int, int *, arrayind_t *);
extern char *get_array_value(char *, int, int *, arrayind_t *);

extern char *array_keys(char *, int);

extern char *array_variable_name(char *, char **, int *);
extern SHELL_VAR *array_variable_part(char *, char **, int *);

#else

#define AV_ALLOWALL 0
#define AV_QUOTED 0
#define AV_USEIND 0

#endif

#endif /* !_ARRAYFUNC_H_ */
