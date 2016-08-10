/* list.c - Functions for manipulating linked lists of objects. */


#include "config.h"

#if defined(HAVE_UNISTD_H)
#include <unistd.h>
#endif

#include "shell.h"

/* A global variable which acts as a sentinel for an `error' list return. */
GENERIC_LIST global_error_list;

#ifdef INCLUDE_UNUSED
/* Call FUNCTION on every member of LIST, a generic list. */
void list_walk(list, function) GENERIC_LIST *list;
sh_glist_func_t *function;
{
  for (; list; list = list->next)
    if ((*function)(list) < 0) return;
}

/* Call FUNCTION on every string in WORDS. */
void wlist_walk(words, function) WORD_LIST *words;
sh_icpfunc_t *function;
{
  for (; words; words = words->next)
    if ((*function)(words->word->word) < 0) return;
}
#endif /* INCLUDE_UNUSED */

/* Reverse the chain of structures in LIST.  Output the new head
   of the chain.  You should always assign the output value of this
   function to something, or you will lose the chain. */
GENERIC_LIST *list_reverse(list) GENERIC_LIST *list;
{
  register GENERIC_LIST *next, *prev;

  for (prev = (GENERIC_LIST *)NULL; list;) {
    next = list->next;
    list->next = prev;
    prev = list;
    list = next;
  }
  return (prev);
}

/* Return the number of elements in LIST, a generic list. */
int list_length(list) GENERIC_LIST *list;
{
  register int i;

  for (i = 0; list; list = list->next, i++)
    ;
  return (i);
}

/* Append TAIL to HEAD.  Return the header of the list. */
GENERIC_LIST *list_append(head, tail) GENERIC_LIST *head, *tail;
{
  register GENERIC_LIST *t_head;

  if (head == 0) return (tail);

  for (t_head = head; t_head->next; t_head = t_head->next)
    ;
  t_head->next = tail;
  return (head);
}

#ifdef INCLUDE_UNUSED
/* Delete the element of LIST which satisfies the predicate function COMPARER.
   Returns the element that was deleted, so you can dispose of it, or -1 if
   the element wasn't found.  COMPARER is called with the list element and
   then ARG.  Note that LIST contains the address of a variable which points
   to the list.  You might call this function like this:

   SHELL_VAR *elt = list_remove (&variable_list, check_var_has_name, "foo");
   dispose_variable (elt);
*/
GENERIC_LIST *list_remove(list, comparer, arg) GENERIC_LIST **list;
Function *comparer;
char *arg;
{
  register GENERIC_LIST *prev, *temp;

  for (prev = (GENERIC_LIST *)NULL, temp = *list; temp;
       prev = temp, temp = temp->next) {
    if ((*comparer)(temp, arg)) {
      if (prev)
        prev->next = temp->next;
      else
        *list = temp->next;
      return (temp);
    }
  }
  return ((GENERIC_LIST *)&global_error_list);
}
#endif
