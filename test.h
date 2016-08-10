/* test.h -- external interface to the conditional command code. */


#ifndef _TEST_H_
#define _TEST_H_

#include "stdc.h"

/* Values for the flags argument to binary_test */
#define TEST_PATMATCH 0x01
#define TEST_ARITHEXP 0x02
#define TEST_LOCALE 0x04

extern int test_unop(char *);
extern int test_binop(char *);

extern int unary_test(char *, char *);
extern int binary_test(char *, char *, char *, int);

extern int test_command(int, char **);

#endif /* _TEST_H_ */
