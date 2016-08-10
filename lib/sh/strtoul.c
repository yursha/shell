/* strtoul - convert string representation of a number into an unsigned long
 * value. */


#include <config.h>

#ifndef HAVE_STRTOUL

#define UNSIGNED 1
#undef HAVE_STRTOL

#include <strtol.c>

#endif /* !HAVE_STRTOUL */
