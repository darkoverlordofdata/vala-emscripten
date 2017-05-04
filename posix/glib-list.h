/* TODO */

#ifndef _GLIB_LIST_H_
#define _GLIB_LIST_H_

typedef struct _GList GList;
struct _GList {
	gpointer data;
	GList *next;
	GList *prev;
};

#define _g_list_alloc() calloc(1, sizeof(GList))
/**
 * g_list_alloc:
 *
 * Allocates space for one #GList element. It is called by
 * g_list_append(), g_list_prepend(), g_list_insert() and
 * g_list_insert_sorted() and so is rarely used on its own.
 *
 * Returns: a pointer to the newly-allocated #GList element
 **/
static inline GList *g_list_alloc (void)
{
  return _g_list_alloc ();
}

static inline void g_list_free(GList *list) {
	GList *current, *tmp;
	current = list;
	while (current) {
		tmp = current->next;
		free(current);
		current = tmp;
	}
}

/**
 * g_list_last:
 * @list: any #GList element
 *
 * Gets the last element in a #GList.
 *
 * Returns: the last element in the #GList,
 *     or %NULL if the #GList has no elements
 */
static inline GList *g_list_last (GList *list)
{
  if (list)
    {
      while (list->next)
        list = list->next;
    }
  
  return list;
}

/**
 * g_list_append:
 * @list: a pointer to a #GList
 * @data: the data for the new element
 *
 * Adds a new element on to the end of the list.
 *
 * Note that the return value is the new start of the list,
 * if @list was empty; make sure you store the new value.
 *
 * g_list_append() has to traverse the entire list to find the end,
 * which is inefficient when adding multiple elements. A common idiom
 * to avoid the inefficiency is to use g_list_prepend() and reverse
 * the list with g_list_reverse() when all elements have been added.
 *
 * |[<!-- language="C" -->
 * // Notice that these are initialized to the empty list.
 * GList *string_list = NULL, *number_list = NULL;
 *
 * // This is a list of strings.
 * string_list = g_list_append (string_list, "first");
 * string_list = g_list_append (string_list, "second");
 * 
 * // This is a list of integers.
 * number_list = g_list_append (number_list, GINT_TO_POINTER (27));
 * number_list = g_list_append (number_list, GINT_TO_POINTER (14));
 * ]|
 *
 * Returns: either @list or the new start of the #GList if @list was %NULL
 */
static inline GList *g_list_append (GList *list, gpointer  data)
{
  GList *new_list;
  GList *last;
  
  new_list = _g_list_alloc ();
  new_list->data = data;
  new_list->next = NULL;
  
  if (list)
    {
      last = g_list_last (list);
      /* g_assert (last != NULL); */
      last->next = new_list;
      new_list->prev = last;

      return list;
    }
  else
    {
      new_list->prev = NULL;
      return new_list;
    }
}

/**
 * g_list_prepend:
 * @list: a pointer to a #GList, this must point to the top of the list
 * @data: the data for the new element
 *
 * Prepends a new element on to the start of the list.
 *
 * Note that the return value is the new start of the list,
 * which will have changed, so make sure you store the new value. 
 *
 * |[<!-- language="C" -->
 * // Notice that it is initialized to the empty list.
 * GList *list = NULL;
 *
 * list = g_list_prepend (list, "last");
 * list = g_list_prepend (list, "first");
 * ]|
 *
 * Do not use this function to prepend a new element to a different
 * element than the start of the list. Use g_list_insert_before() instead.
 *
 * Returns: a pointer to the newly prepended element, which is the new 
 *     start of the #GList
 */
static inline GList *g_list_prepend (GList *list, gpointer  data)
{
  GList *new_list;
  
  new_list = _g_list_alloc ();
  new_list->data = data;
  new_list->next = list;
  
  if (list)
    {
      new_list->prev = list->prev;
      if (list->prev)
        list->prev->next = new_list;
      list->prev = new_list;
    }
  else
    new_list->prev = NULL;
  
  return new_list;
}

/**
 * g_list_foreach:
 * @list: a #GList, this must point to the top of the list
 * @func: the function to call with each element's data
 * @user_data: user data to pass to the function
 *
 * Calls a function for each element of a #GList.
 */
/**
 * GFunc:
 * @data: the element's data
 * @user_data: user data passed to g_list_foreach() or g_slist_foreach()
 *
 * Specifies the type of functions passed to g_list_foreach() and
 * g_slist_foreach().
 */
static inline void
g_list_foreach (GList    *list,
                GFunc     func,
                gpointer  user_data)
{
  while (list)
    {
      GList *next = list->next;
      (*func) (list->data, user_data);
      list = next;
    }
}


static inline GList *_g_list_remove_link (GList *list, GList *link)
{
  if (link == NULL)
    return list;

  if (link->prev)
    {
      if (link->prev->next == link)
        link->prev->next = link->next;
      else
        g_warning ("corrupted double-linked list detected");
    }
  if (link->next)
    {
      if (link->next->prev == link)
        link->next->prev = link->prev;
      else
        g_warning ("corrupted double-linked list detected");
    }

  if (link == list)
    list = list->next;

  link->next = NULL;
  link->prev = NULL;

  return list;
}

/**
 * g_list_remove:
 * @list: a #GList, this must point to the top of the list
 * @data: the data of the element to remove
 *
 * Removes an element from a #GList.
 * If two elements contain the same data, only the first is removed.
 * If none of the elements contain the data, the #GList is unchanged.
 *
 * Returns: the (possibly changed) start of the #GList
 */
static inline GList *g_list_remove (GList *list, gconstpointer  data)
{
  GList *tmp;

  tmp = list;
  while (tmp)
    {
      if (tmp->data != data)
        tmp = tmp->next;
      else
        {
          list = _g_list_remove_link (list, tmp);
          //_g_list_free1 (tmp);
          free(tmp);

          break;
        }
    }
  return list;
}

/**
 * g_list_find:
 * @list: a #GList, this must point to the top of the list
 * @data: the element data to find
 *
 * Finds the element in a #GList which contains the given data.
 *
 * Returns: the found #GList element, or %NULL if it is not found
 */
static inline GList *g_list_find (GList *list, gconstpointer  data)
{
  while (list)
    {
      if (list->data == data)
        break;
      list = list->next;
    }
  
  return list;
}

/**
 * g_list_first:
 * @list: any #GList element
 *
 * Gets the first element in a #GList.
 *
 * Returns: the first element in the #GList, 
 *     or %NULL if the #GList has no elements
 */
static inline GList *g_list_first (GList *list)
{
  if (list)
    {
      while (list->prev)
        list = list->prev;
    }
  
  return list;
}


/**
 * g_list_length:
 * @list: a #GList, this must point to the top of the list
 *
 * Gets the number of elements in a #GList.
 *
 * This function iterates over the whole list to count its elements.
 * Use a #GQueue instead of a GList if you regularly need the number
 * of items. To check whether the list is non-empty, it is faster to check
 * @list against %NULL.
 *
 * Returns: the number of elements in the #GList
 */
static inline guint g_list_length (GList *list)
{
  guint length;
  
  length = 0;
  while (list)
    {
      length++;
      list = list->next;
    }
  
  return length;
}

/**
 * g_list_nth:
 * @list: a #GList, this must point to the top of the list
 * @n: the position of the element, counting from 0
 *
 * Gets the element at the given position in a #GList.
 *
 * This iterates over the list until it reaches the @n-th position. If you
 * intend to iterate over every element, it is better to use a for-loop as
 * described in the #GList introduction.
 *
 * Returns: the element, or %NULL if the position is off 
 *     the end of the #GList
 */
static inline GList *g_list_nth (GList *list, guint  n)
{
  while ((n-- > 0) && list)
    list = list->next;
  
  return list;
}
/**
 * g_list_nth_data:
 * @list: a #GList, this must point to the top of the list
 * @n: the position of the element
 *
 * Gets the data of the element at the given position.
 *
 * This iterates over the list until it reaches the @n-th position. If you
 * intend to iterate over every element, it is better to use a for-loop as
 * described in the #GList introduction.
 *
 * Returns: the element's data, or %NULL if the position 
 *     is off the end of the #GList
 */
static inline gpointer g_list_nth_data (GList *list, guint  n)
{
  while ((n-- > 0) && list)
    list = list->next;
  
  return list ? list->data : NULL;
}

/**
 * g_list_remove_link:
 * @list: a #GList, this must point to the top of the list
 * @llink: an element in the #GList
 *
 * Removes an element from a #GList, without freeing the element.
 * The removed element's prev and next links are set to %NULL, so 
 * that it becomes a self-contained list with one element.
 *
 * This function is for example used to move an element in the list
 * (see the example for g_list_concat()) or to remove an element in
 * the list before freeing its data:
 * |[<!-- language="C" --> 
 * list = g_list_remove_link (list, llink);
 * free_some_data_that_may_access_the_list_again (llink->data);
 * g_list_free (llink);
 * ]|
 *
 * Returns: the (possibly changed) start of the #GList
 */
static inline GList *g_list_remove_link (GList *list, GList *llink)
{
  return _g_list_remove_link (list, llink);
}


/**
 * g_list_insert:
 * @list: a pointer to a #GList, this must point to the top of the list
 * @data: the data for the new element
 * @position: the position to insert the element. If this is 
 *     negative, or is larger than the number of elements in the 
 *     list, the new element is added on to the end of the list.
 * 
 * Inserts a new element into the list at the given position.
 *
 * Returns: the (possibly changed) start of the #GList
 */
static inline GList *
g_list_insert (GList    *list,
               gpointer  data,
               gint      position)
{
  GList *new_list;
  GList *tmp_list;

  if (position < 0)
    return g_list_append (list, data);
  else if (position == 0)
    return g_list_prepend (list, data);

  tmp_list = g_list_nth (list, position);
  if (!tmp_list)
    return g_list_append (list, data);

  new_list = _g_list_alloc ();
  new_list->data = data;
  new_list->prev = tmp_list->prev;
  tmp_list->prev->next = new_list;
  new_list->next = tmp_list;
  tmp_list->prev = new_list;

  return list;
}


/* slist */
#define GSList GList
#define g_slist_append g_list_append
#define g_slist_prepend g_list_prepend
#define g_slist_foreach g_list_foreach
#define g_slist_free g_list_free

#endif /* _GLIB_LIST_H_ */
