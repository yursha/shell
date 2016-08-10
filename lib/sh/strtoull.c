/* strtoull - convert string representation of a number into an unsigned long
 * long value. */


#include <config.h>

#if defined(HAVE_LONG_LONG) && !defined(HAVE_STRTOULL)

#define QUAD 1
#define UNSIGNED 1
#undef HAVE_STRTOL

#include "strtol.c"

#endif /* HAVE_LONG_LONG && !HAVE_STRTOULL */
