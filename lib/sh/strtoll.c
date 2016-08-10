/* strtoll - convert string representation of a number into a long long value.
 */

#include <config.h>

#if defined(HAVE_LONG_LONG) && !defined(HAVE_STRTOLL)

#define QUAD 1
#undef HAVE_STRTOL

#include "strtol.c"

#endif /* HAVE_LONG_LONG && !HAVE_STRTOLL */
