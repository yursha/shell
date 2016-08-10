/* mailcheck.h -- variables and function declarations for mail checking. */


#if !defined(_MAILCHECK_H_)
#define _MAILCHECK_H_

/* Functions from mailcheck.c */
extern int time_to_check_mail(void);
extern void reset_mail_timer(void);
extern void reset_mail_files(void);
extern void free_mail_files(void);
extern char *make_default_mailpath(void);
extern void remember_mail_dates(void);
extern void init_mail_dates(void);
extern void check_mail(void);

#endif /* _MAILCHECK_H */
