/* TODO */

#ifndef _GLIB_HASH_H_
#define _GLIB_HASH_H_

typedef struct _GHashTable GHashTable;
struct _GHashTable {
  gint             size;
  gint             mod;
  guint            mask;
  gint             nnodes;
  gint             noccupied;  /* nnodes + tombstones */

  gpointer        *keys;
  guint           *hashes;
  gpointer        *values;

  GHashFunc        hash_func;
  GEqualFunc       key_equal_func;
  gint             ref_count;
#ifndef G_DISABLE_ASSERT
  /*
   * Tracks the structure of the hash table, not its contents: is only
   * incremented when a node is added or removed (is not incremented
   * when the key or data of a node is modified).
   */
  int              version;
#endif
  GDestroyNotify   key_destroy_func;
  GDestroyNotify   value_destroy_func;
};

#define _g_list_alloc() calloc(1, sizeof(GHashTable))

static inline void g_list_free(GHashTable *list) {
	GHashTable *current, *tmp;
	current = list;
	while (current) {
		tmp = current->next;
		free(current);
		current = tmp;
	}
}

static inline GHashTable* g_list_last (GHashTable *list) {
	if (list)
		while (list->next)
			list = list->next;
	return list;
}

static inline GHashTable* g_list_append (GHashTable *list, gpointer data) {
	GHashTable *new_list = _g_list_alloc ();
	GHashTable *last;
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

static inline GHashTable* g_list_prepend (GHashTable *list, gpointer data) {
	GHashTable *new_list = _g_list_alloc ();
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

static inline void g_list_foreach (GHashTable *list, GFunc func, gpointer user_data) {
	while (list) {
		GHashTable *next = list->next;
		(*func) (list->data, user_data);
		list = next;
	}
}

/* slist */
#define GSList GHashTable
#define g_slist_append g_list_append
#define g_slist_prepend g_list_prepend
#define g_slist_foreach g_list_foreach
#define g_slist_free g_list_free

#endif /* _GLIB_HASH_H_ */
