/* fmtullong.c - convert `long long int' to string */

#include <config.h>

#ifdef HAVE_LONG_LONG

#define LONG long long
#define UNSIGNED_LONG unsigned long long
#define fmtulong fmtullong

#include "fmtulong.c"

#endif
