static inline gint (g_atomic_int_add) (volatile gint *atomic, gint val)
{
  gint oldval;

  oldval = *atomic;
  *atomic = oldval + val;

  return oldval;
}
static inline void (g_atomic_int_inc) (volatile gint *atomic)
{
  (*atomic)++;
}

static inline gboolean (g_atomic_int_dec_and_test) (volatile gint *atomic)
{
  gboolean is_zero;
  is_zero = --(*atomic) == 0;
  return is_zero;
}


