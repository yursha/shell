/* patchlevel.h -- current bash patch level */


#if !defined(_PATCHLEVEL_H_)
#define _PATCHLEVEL_H_

/* It's important that there be no other strings in this file that match the
   regexp `^#define[ 	]*PATCHLEVEL', since that's what support/mkversion.sh
   looks for to find the patch level (for the sccs version string). */

#define PATCHLEVEL 0

#endif /* _PATCHLEVEL_H_ */
