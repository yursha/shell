/* fmtumax.c -- Convert uintmax_t to string.  */


#include <config.h>

#define LONG intmax_t
#define UNSIGNED_LONG uintmax_t
#define fmtulong fmtumax

#include "fmtulong.c"
