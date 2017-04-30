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

static inline void g_list_free(GList *list) {
	GList *current, *tmp;
	current = list;
	while (current) {
		tmp = current->next;
		free(current);
		current = tmp;
	}
}

static inline GList* g_list_last (GList *list) {
	if (list)
		while (list->next)
			list = list->next;
	return list;
}

static inline GList* g_list_append (GList *list, gpointer data) {
	GList *new_list = _g_list_alloc ();
	GList *last;
	if (!new_list) return NULL;
	new_list->data = data;
	new_list->next = NULL;
	if (list) {
		last = g_list_last (list);
		last->next = new_list;
		new_list->prev = last;
		return list;
	}
	new_list->prev = NULL;
	return new_list;
}

static inline GList* g_list_prepend (GList *list, gpointer data) {
	GList *new_list = _g_list_alloc ();
	new_list->data = data;
	new_list->next = list;
	if (list) {
		new_list->prev = list->prev;
		if (list->prev)
			list->prev->next = new_list;
		list->prev = new_list;
	} else new_list->prev = NULL;
	return new_list;
}

static inline void g_list_foreach (GList *list, GFunc func, gpointer user_data) {
	while (list) {
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
        printf ("corrupted double-linked list detected");
    }
  if (link->next)
    {
      if (link->next->prev == link)
        link->next->prev = link->prev;
      else
        printf ("corrupted double-linked list detected");
    }

  if (link == list)
    list = list->next;

  link->next = NULL;
  link->prev = NULL;

  return list;
}
//#define _g_slist_free1(slist)   g_slice_free (GSList, slist)
/* delegate to system malloc */
//     memset ((slist), 0, sizeof (GSList));
//   free ((slist));

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
			memset ((tmp), 0, sizeof (GList));
			free ((tmp));
        //   _g_list_free1 (tmp);

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


/* slist */
#define GSList GList
#define g_slist_append g_list_append
#define g_slist_prepend g_list_prepend
#define g_slist_foreach g_list_foreach
#define g_slist_free g_list_free

#endif /* _GLIB_LIST_H_ */
