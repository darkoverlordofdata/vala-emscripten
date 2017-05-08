/* TODO */

#ifndef _GLIB_HASH_H_
#define _GLIB_HASH_H_

#define HASH_TABLE_MIN_SHIFT 3  /* 1 << 3 == 8 buckets */
#define UNUSED_HASH_VALUE 0
#define TOMBSTONE_HASH_VALUE 1
#define HASH_IS_UNUSED(h_) ((h_) == UNUSED_HASH_VALUE)
#define HASH_IS_TOMBSTONE(h_) ((h_) == TOMBSTONE_HASH_VALUE)
#define HASH_IS_REAL(h_) ((h_) >= 2)

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

/* Each table size has an associated prime modulo (the first prime
 * lower than the table size) used to find the initial bucket. Probing
 * then works modulo 2^n. The prime modulo is necessary to get a
 * good distribution with poor hash functions.
 */
static const gint prime_mod [] =
{
  1,          /* For 1 << 0 */
  2,
  3,
  7,
  13,
  31,
  61,
  127,
  251,
  509,
  1021,
  2039,
  4093,
  8191,
  16381,
  32749,
  65521,      /* For 1 << 16 */
  131071,
  262139,
  524287,
  1048573,
  2097143,
  4194301,
  8388593,
  16777213,
  33554393,
  67108859,
  134217689,
  268435399,
  536870909,
  1073741789,
  2147483647  /* For 1 << 31 */
};


static inline gint
g_hash_table_find_closest_shift (gint n)
{
  gint i;

  for (i = 0; n; i++)
    n >>= 1;

  return i;
}



static inline void g_hash_table_set_shift (GHashTable *hash_table, gint shift)
{
  gint i;
  guint mask = 0;

  hash_table->size = 1 << shift;
  hash_table->mod  = prime_mod [shift];

  for (i = 0; i < shift; i++)
    {
      mask <<= 1;
      mask |= 1;
    }

  hash_table->mask = mask;
}

static inline void
g_hash_table_set_shift_from_size (GHashTable *hash_table, gint size)
{
  gint shift;

  shift = g_hash_table_find_closest_shift (size);
  shift = MAX (shift, HASH_TABLE_MIN_SHIFT);

  g_hash_table_set_shift (hash_table, shift);
}

/**
 * g_direct_hash:
 * @v: (nullable): a #gpointer key
 *
 * Converts a gpointer to a hash value.
 * It can be passed to g_hash_table_new() as the @hash_func parameter,
 * when using opaque pointers compared by pointer value as keys in a
 * #GHashTable.
 *
 * This hash function is also appropriate for keys that are integers
 * stored in pointers, such as `GINT_TO_POINTER (n)`.
 *
 * Returns: a hash value corresponding to the key.
 */
static inline guint g_direct_hash (gconstpointer v)
{
  return GPOINTER_TO_UINT (v);
}

/*
 * g_hash_table_resize:
 * @hash_table: our #GHashTable
 *
 * Resizes the hash table to the optimal size based on the number of
 * nodes currently held. If you call this function then a resize will
 * occur, even if one does not need to occur.
 * Use g_hash_table_maybe_resize() instead.
 *
 * This function may "resize" the hash table to its current size, with
 * the side effect of cleaning up tombstones and otherwise optimizing
 * the probe sequences.
 */
static inline void
g_hash_table_resize (GHashTable *hash_table)
{
  gpointer *new_keys;
  gpointer *new_values;
  guint *new_hashes;
  gint old_size;
  gint i;

  old_size = hash_table->size;
  g_hash_table_set_shift_from_size (hash_table, hash_table->nnodes * 2);

  new_keys = g_new0 (gpointer, hash_table->size);
  if (hash_table->keys == hash_table->values)
    new_values = new_keys;
  else
    new_values = g_new0 (gpointer, hash_table->size);
  new_hashes = g_new0 (guint, hash_table->size);

  for (i = 0; i < old_size; i++)
    {
      guint node_hash = hash_table->hashes[i];
      guint hash_val;
      guint step = 0;

      if (!HASH_IS_REAL (node_hash))
        continue;

      hash_val = node_hash % hash_table->mod;

      while (!HASH_IS_UNUSED (new_hashes[hash_val]))
        {
          step++;
          hash_val += step;
          hash_val &= hash_table->mask;
        }

      new_hashes[hash_val] = hash_table->hashes[i];
      new_keys[hash_val] = hash_table->keys[i];
      new_values[hash_val] = hash_table->values[i];
    }

  if (hash_table->keys != hash_table->values)
    g_free (hash_table->values);

  g_free (hash_table->keys);
  g_free (hash_table->hashes);

  hash_table->keys = new_keys;
  hash_table->values = new_values;
  hash_table->hashes = new_hashes;

  hash_table->noccupied = hash_table->nnodes;
}
/*
 * g_hash_table_maybe_resize:
 * @hash_table: our #GHashTable
 *
 * Resizes the hash table, if needed.
 *
 * Essentially, calls g_hash_table_resize() if the table has strayed
 * too far from its ideal size for its number of nodes.
 */
static inline void
g_hash_table_maybe_resize (GHashTable *hash_table)
{
  gint noccupied = hash_table->noccupied;
  gint size = hash_table->size;

  if ((size > hash_table->nnodes * 4 && size > 1 << HASH_TABLE_MIN_SHIFT) ||
      (size <= noccupied + (noccupied / 16)))
    g_hash_table_resize (hash_table);
}

/*
 * g_hash_table_lookup_node:
 * @hash_table: our #GHashTable
 * @key: the key to lookup against
 * @hash_return: key hash return location
 *
 * Performs a lookup in the hash table, preserving extra information
 * usually needed for insertion.
 *
 * This function first computes the hash value of the key using the
 * user's hash function.
 *
 * If an entry in the table matching @key is found then this function
 * returns the index of that entry in the table, and if not, the
 * index of an unused node (empty or tombstone) where the key can be
 * inserted.
 *
 * The computed hash value is returned in the variable pointed to
 * by @hash_return. This is to save insertions from having to compute
 * the hash record again for the new record.
 *
 * Returns: index of the described node
 */
static inline guint
g_hash_table_lookup_node (GHashTable    *hash_table,
                          gconstpointer  key,
                          guint         *hash_return)
{
  guint node_index;
  guint node_hash;
  guint hash_value;
  guint first_tombstone = 0;
  gboolean have_tombstone = FALSE;
  guint step = 0;

  /* If this happens, then the application is probably doing too much work
   * from a destroy notifier. The alternative would be to crash any second
   * (as keys, etc. will be NULL).
   * Applications need to either use g_hash_table_destroy, or ensure the hash
   * table is empty prior to removing the last reference using g_hash_table_unref(). */
  assert (hash_table->ref_count > 0);

  hash_value = hash_table->hash_func (key);
  if (G_UNLIKELY (!HASH_IS_REAL (hash_value)))
    hash_value = 2;

  *hash_return = hash_value;

  node_index = hash_value % hash_table->mod;
  node_hash = hash_table->hashes[node_index];

  while (!HASH_IS_UNUSED (node_hash))
    {
      /* We first check if our full hash values
       * are equal so we can avoid calling the full-blown
       * key equality function in most cases.
       */
      if (node_hash == hash_value)
        {
          gpointer node_key = hash_table->keys[node_index];

          if (hash_table->key_equal_func)
            {
              if (hash_table->key_equal_func (node_key, key))
                return node_index;
            }
          else if (node_key == key)
            {
              return node_index;
            }
        }
      else if (HASH_IS_TOMBSTONE (node_hash) && !have_tombstone)
        {
          first_tombstone = node_index;
          have_tombstone = TRUE;
        }

      step++;
      node_index += step;
      node_index &= hash_table->mask;
      node_hash = hash_table->hashes[node_index];
    }

  if (have_tombstone)
    return first_tombstone;

  return node_index;
}

/**
 * g_hash_table_new_full:
 * @hash_func: a function to create a hash value from a key
 * @key_equal_func: a function to check two keys for equality
 * @key_destroy_func: (nullable): a function to free the memory allocated for the key
 *     used when removing the entry from the #GHashTable, or %NULL
 *     if you don't want to supply such a function.
 * @value_destroy_func: (nullable): a function to free the memory allocated for the
 *     value used when removing the entry from the #GHashTable, or %NULL
 *     if you don't want to supply such a function.
 *
 * Creates a new #GHashTable like g_hash_table_new() with a reference
 * count of 1 and allows to specify functions to free the memory
 * allocated for the key and value that get called when removing the
 * entry from the #GHashTable.
 *
 * Since version 2.42 it is permissible for destroy notify functions to
 * recursively remove further items from the hash table. This is only
 * permissible if the application still holds a reference to the hash table.
 * This means that you may need to ensure that the hash table is empty by
 * calling g_hash_table_remove_all() before releasing the last reference using
 * g_hash_table_unref().
 *
 * Returns: a new #GHashTable
 */
static inline GHashTable *
g_hash_table_new_full (GHashFunc      hash_func,
                       GEqualFunc     key_equal_func,
                       GDestroyNotify key_destroy_func,
                       GDestroyNotify value_destroy_func)
{
	GHashTable *hash_table;

	hash_table = g_slice_new (GHashTable);
	g_hash_table_set_shift (hash_table, HASH_TABLE_MIN_SHIFT);
	hash_table->nnodes             = 0;
	hash_table->noccupied          = 0;
  	hash_table->hash_func          = hash_func ? hash_func : g_direct_hash;
 	hash_table->key_equal_func     = key_equal_func;
  	hash_table->ref_count          = 1;
#ifndef G_DISABLE_ASSERT
  	hash_table->version            = 0;
#endif
  	hash_table->key_destroy_func   = key_destroy_func;
	hash_table->value_destroy_func = value_destroy_func;
	hash_table->keys               = g_new0 (gpointer, hash_table->size);
	hash_table->values             = hash_table->keys;
	hash_table->hashes             = g_new0 (guint, hash_table->size);

  return hash_table;
}
/*
 * g_hash_table_insert_node:
 * @hash_table: our #GHashTable
 * @node_index: pointer to node to insert/replace
 * @key_hash: key hash
 * @key: (nullable): key to replace with, or %NULL
 * @value: value to replace with
 * @keep_new_key: whether to replace the key in the node with @key
 * @reusing_key: whether @key was taken out of the existing node
 *
 * Inserts a value at @node_index in the hash table and updates it.
 *
 * If @key has been taken out of the existing node (ie it is not
 * passed in via a g_hash_table_insert/replace) call, then @reusing_key
 * should be %TRUE.
 *
 * Returns: %TRUE if the key did not exist yet
 */
static inline gboolean
g_hash_table_insert_node (GHashTable *hash_table,
                          guint       node_index,
                          guint       key_hash,
                          gpointer    new_key,
                          gpointer    new_value,
                          gboolean    keep_new_key,
                          gboolean    reusing_key)
{
  gboolean already_exists;
  guint old_hash;
  gpointer key_to_free = NULL;
  gpointer value_to_free = NULL;

  old_hash = hash_table->hashes[node_index];
  already_exists = HASH_IS_REAL (old_hash);

  /* Proceed in three steps.  First, deal with the key because it is the
   * most complicated.  Then consider if we need to split the table in
   * two (because writing the value will result in the set invariant
   * becoming broken).  Then deal with the value.
   *
   * There are three cases for the key:
   *
   *  - entry already exists in table, reusing key:
   *    free the just-passed-in new_key and use the existing value
   *
   *  - entry already exists in table, not reusing key:
   *    free the entry in the table, use the new key
   *
   *  - entry not already in table:
   *    use the new key, free nothing
   *
   * We update the hash at the same time...
   */
  if (already_exists)
    {
      /* Note: we must record the old value before writing the new key
       * because we might change the value in the event that the two
       * arrays are shared.
       */
      value_to_free = hash_table->values[node_index];

      if (keep_new_key)
        {
          key_to_free = hash_table->keys[node_index];
          hash_table->keys[node_index] = new_key;
        }
      else
        key_to_free = new_key;
    }
  else
    {
      hash_table->hashes[node_index] = key_hash;
      hash_table->keys[node_index] = new_key;
    }

  /* Step two: check if the value that we are about to write to the
   * table is the same as the key in the same position.  If it's not,
   * split the table.
   */
  if (G_UNLIKELY (hash_table->keys == hash_table->values && hash_table->keys[node_index] != new_value))
    hash_table->values = g_memdup (hash_table->keys, sizeof (gpointer) * hash_table->size);

  /* Step 3: Actually do the write */
  hash_table->values[node_index] = new_value;

  /* Now, the bookkeeping... */
  if (!already_exists)
    {
      hash_table->nnodes++;

      if (HASH_IS_UNUSED (old_hash))
        {
          /* We replaced an empty node, and not a tombstone */
          hash_table->noccupied++;
          g_hash_table_maybe_resize (hash_table);
        }

#ifndef G_DISABLE_ASSERT
      hash_table->version++;
#endif
    }

  if (already_exists)
    {
      if (hash_table->key_destroy_func && !reusing_key)
        (* hash_table->key_destroy_func) (key_to_free);
      if (hash_table->value_destroy_func)
        (* hash_table->value_destroy_func) (value_to_free);
    }

  return !already_exists;
}

/*
 * g_hash_table_insert_internal:
 * @hash_table: our #GHashTable
 * @key: the key to insert
 * @value: the value to insert
 * @keep_new_key: if %TRUE and this key already exists in the table
 *   then call the destroy notify function on the old key.  If %FALSE
 *   then call the destroy notify function on the new key.
 *
 * Implements the common logic for the g_hash_table_insert() and
 * g_hash_table_replace() functions.
 *
 * Do a lookup of @key. If it is found, replace it with the new
 * @value (and perhaps the new @key). If it is not found, create
 * a new node.
 *
 * Returns: %TRUE if the key did not exist yet
 */
static inline gboolean
g_hash_table_insert_internal (GHashTable *hash_table,
                              gpointer    key,
                              gpointer    value,
                              gboolean    keep_new_key)
{
  guint key_hash;
  guint node_index;

  g_return_val_if_fail (hash_table != NULL, FALSE);

  node_index = g_hash_table_lookup_node (hash_table, key, &key_hash);

  return g_hash_table_insert_node (hash_table, node_index, key_hash, key, value, keep_new_key, FALSE);
}
/**
 * g_hash_table_insert:
 * @hash_table: a #GHashTable
 * @key: a key to insert
 * @value: the value to associate with the key
 *
 * Inserts a new key and value into a #GHashTable.
 *
 * If the key already exists in the #GHashTable its current
 * value is replaced with the new value. If you supplied a
 * @value_destroy_func when creating the #GHashTable, the old
 * value is freed using that function. If you supplied a
 * @key_destroy_func when creating the #GHashTable, the passed
 * key is freed using that function.
 *
 * Returns: %TRUE if the key did not exist yet
 */
static inline gboolean
g_hash_table_insert (GHashTable *hash_table,
                     gpointer    key,
                     gpointer    value)
{
  return g_hash_table_insert_internal (hash_table, key, value, FALSE);
}


/*
 * g_hash_table_remove_all_nodes:
 * @hash_table: our #GHashTable
 * @notify: %TRUE if the destroy notify handlers are to be called
 *
 * Removes all nodes from the table.  Since this may be a precursor to
 * freeing the table entirely, no resize is performed.
 *
 * If @notify is %TRUE then the destroy notify functions are called
 * for the key and value of the hash node.
 */
static inline void g_hash_table_remove_all_nodes (GHashTable *hash_table,
                               gboolean    notify,
                               gboolean    destruction)
{
  int i;
  gpointer key;
  gpointer value;
  gint old_size;
  gpointer *old_keys;
  gpointer *old_values;
  guint    *old_hashes;

  /* If the hash table is already empty, there is nothing to be done. */
  if (hash_table->nnodes == 0)
    return;

  hash_table->nnodes = 0;
  hash_table->noccupied = 0;

  if (!notify ||
      (hash_table->key_destroy_func == NULL &&
       hash_table->value_destroy_func == NULL))
    {
      if (!destruction)
        {
          memset (hash_table->hashes, 0, hash_table->size * sizeof (guint));
          memset (hash_table->keys, 0, hash_table->size * sizeof (gpointer));
          memset (hash_table->values, 0, hash_table->size * sizeof (gpointer));
        }

      return;
    }

  /* Keep the old storage space around to iterate over it. */
  old_size = hash_table->size;
  old_keys   = hash_table->keys;
  old_values = hash_table->values;
  old_hashes = hash_table->hashes;

  /* Now create a new storage space; If the table is destroyed we can use the
   * shortcut of not creating a new storage. This saves the allocation at the
   * cost of not allowing any recursive access.
   * However, the application doesn't own any reference anymore, so access
   * is not allowed. If accesses are done, then either an assert or crash
   * *will* happen. */
  g_hash_table_set_shift (hash_table, HASH_TABLE_MIN_SHIFT);
  if (!destruction)
    {
      hash_table->keys   = g_new0 (gpointer, hash_table->size);
      hash_table->values = hash_table->keys;
      hash_table->hashes = g_new0 (guint, hash_table->size);
    }
  else
    {
      hash_table->keys   = NULL;
      hash_table->values = NULL;
      hash_table->hashes = NULL;
    }

  for (i = 0; i < old_size; i++)
    {
      if (HASH_IS_REAL (old_hashes[i]))
        {
          key = old_keys[i];
          value = old_values[i];

          old_hashes[i] = UNUSED_HASH_VALUE;
          old_keys[i] = NULL;
          old_values[i] = NULL;

          if (hash_table->key_destroy_func != NULL)
            hash_table->key_destroy_func (key);

          if (hash_table->value_destroy_func != NULL)
            hash_table->value_destroy_func (value);
        }
    }

  /* Destroy old storage space. */
  if (old_keys != old_values)
    g_free (old_values);

  g_free (old_keys);
  g_free (old_hashes);
}

/**
 * g_hash_table_unref:
 * @hash_table: a valid #GHashTable
 *
 * Atomically decrements the reference count of @hash_table by one.
 * If the reference count drops to 0, all keys and values will be
 * destroyed, and all memory allocated by the hash table is released.
 * This function is MT-safe and may be called from any thread.
 *
 * Since: 2.10
 */
static inline void g_hash_table_unref (GHashTable *hash_table)
{
  g_return_if_fail (hash_table != NULL);

  if (g_atomic_int_dec_and_test (&hash_table->ref_count))
    {
      g_hash_table_remove_all_nodes (hash_table, TRUE, TRUE);
      if (hash_table->keys != hash_table->values)
        g_free (hash_table->values);
      g_free (hash_table->keys);
      g_free (hash_table->hashes);
      g_slice_free (GHashTable, hash_table);
    }
}


/**
 * g_hash_table_lookup:
 * @hash_table: a #GHashTable
 * @key: the key to look up
 *
 * Looks up a key in a #GHashTable. Note that this function cannot
 * distinguish between a key that is not present and one which is present
 * and has the value %NULL. If you need this distinction, use
 * g_hash_table_lookup_extended().
 *
 * Returns: (nullable): the associated value, or %NULL if the key is not found
 */
static inline gpointer
g_hash_table_lookup (GHashTable    *hash_table,
                     gconstpointer  key)
{
  guint node_index;
  guint node_hash;

  g_return_val_if_fail (hash_table != NULL, NULL);

  node_index = g_hash_table_lookup_node (hash_table, key, &node_hash);

  return HASH_IS_REAL (hash_table->hashes[node_index])
    ? hash_table->values[node_index]
    : NULL;
}
/**
 * g_hash_table_get_keys:
 * @hash_table: a #GHashTable
 *
 * Retrieves every key inside @hash_table. The returned data is valid
 * until changes to the hash release those keys.
 *
 * This iterates over every entry in the hash table to build its return value.
 * To iterate over the entries in a #GHashTable more efficiently, use a
 * #GHashTableIter.
 *
 * Returns: (transfer container): a #GList containing all the keys
 *     inside the hash table. The content of the list is owned by the
 *     hash table and should not be modified or freed. Use g_list_free()
 *     when done using the list.
 *
 * Since: 2.14
 */
static inline GList *
g_hash_table_get_keys (GHashTable *hash_table)
{
  gint i;
  GList *retval;

  g_return_val_if_fail (hash_table != NULL, NULL);

  retval = NULL;
  for (i = 0; i < hash_table->size; i++)
    {
      if (HASH_IS_REAL (hash_table->hashes[i]))
        retval = g_list_prepend (retval, hash_table->keys[i]);
    }

  return retval;
}

/**
 * g_hash_table_get_keys_as_array:
 * @hash_table: a #GHashTable
 * @length: (out): the length of the returned array
 *
 * Retrieves every key inside @hash_table, as an array.
 *
 * The returned array is %NULL-terminated but may contain %NULL as a
 * key.  Use @length to determine the true length if it's possible that
 * %NULL was used as the value for a key.
 *
 * Note: in the common case of a string-keyed #GHashTable, the return
 * value of this function can be conveniently cast to (const gchar **).
 *
 * This iterates over every entry in the hash table to build its return value.
 * To iterate over the entries in a #GHashTable more efficiently, use a
 * #GHashTableIter.
 *
 * You should always free the return result with g_free().  In the
 * above-mentioned case of a string-keyed hash table, it may be
 * appropriate to use g_strfreev() if you call g_hash_table_steal_all()
 * first to transfer ownership of the keys.
 *
 * Returns: (array length=length) (transfer container): a
 *   %NULL-terminated array containing each key from the table.
 *
 * Since: 2.40
 **/
static inline gpointer *
g_hash_table_get_keys_as_array (GHashTable *hash_table,
                                guint      *length)
{
  gpointer *result;
  guint i, j = 0;

  result = g_new (gpointer, hash_table->nnodes + 1);
  for (i = 0; i < hash_table->size; i++)
    {
      if (HASH_IS_REAL (hash_table->hashes[i]))
        result[j++] = hash_table->keys[i];
    }
  assert(j == hash_table->nnodes);
  result[j] = NULL;

  if (length)
    *length = j;

  return result;
}


/* Hash functions.
 */

/**
 * g_str_equal:
 * @v1: (not nullable): a key
 * @v2: (not nullable): a key to compare with @v1
 *
 * Compares two strings for byte-by-byte equality and returns %TRUE
 * if they are equal. It can be passed to g_hash_table_new() as the
 * @key_equal_func parameter, when using non-%NULL strings as keys in a
 * #GHashTable.
 *
 * Note that this function is primarily meant as a hash table comparison
 * function. For a general-purpose, %NULL-safe string comparison function,
 * see g_strcmp0().
 *
 * Returns: %TRUE if the two keys match
 */
static inline gboolean
g_str_equal (gconstpointer v1,
             gconstpointer v2)
{
  const gchar *string1 = v1;
  const gchar *string2 = v2;

  return strcmp (string1, string2) == 0;
}

/**
 * g_hash_table_foreach:
 * @hash_table: a #GHashTable
 * @func: the function to call for each key/value pair
 * @user_data: user data to pass to the function
 *
 * Calls the given function for each of the key/value pairs in the
 * #GHashTable.  The function is passed the key and value of each
 * pair, and the given @user_data parameter.  The hash table may not
 * be modified while iterating over it (you can't add/remove
 * items). To remove all items matching a predicate, use
 * g_hash_table_foreach_remove().
 *
 * See g_hash_table_find() for performance caveats for linear
 * order searches in contrast to g_hash_table_lookup().
 */
static inline void
g_hash_table_foreach (GHashTable *hash_table,
                      GHFunc      func,
                      gpointer    user_data)
{
  gint i;
#ifndef G_DISABLE_ASSERT
  gint version;
#endif

  g_return_if_fail (hash_table != NULL);
  g_return_if_fail (func != NULL);

#ifndef G_DISABLE_ASSERT
  version = hash_table->version;
#endif

  for (i = 0; i < hash_table->size; i++)
    {
      guint node_hash = hash_table->hashes[i];
      gpointer node_key = hash_table->keys[i];
      gpointer node_value = hash_table->values[i];

      if (HASH_IS_REAL (node_hash))
        (* func) (node_key, node_value, user_data);

#ifndef G_DISABLE_ASSERT
      g_return_if_fail (version == hash_table->version);
#endif
    }
}


#endif /* _GLIB_HASH_H_ */
