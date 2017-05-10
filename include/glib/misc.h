// #define GTypeInterface void*
#define GQuark uintptr_t
#define g_quark_from_static_string(x) ((GQuark)(size_t)(x))


typedef signed char gint8;
typedef unsigned char guint8;
typedef signed short gint16;
typedef unsigned short guint16;
typedef signed int gint32;
typedef unsigned int guint32;
typedef signed long long gint64;
typedef unsigned long long guint64;
typedef guint32 gunichar;
typedef signed long gintptr;

#define g_new0(x,y) (x*)calloc (y, sizeof(x));
#define g_new(x, y)	(x*)malloc (sizeof(x)*y);	
#define g_renew(x,m,y) (x*)realloc (m, sizeof(x)*y); 
#define g_slice_new(x) (x*)calloc (1, sizeof(x));
#define g_slice_new0(x) (x*)calloc (1, sizeof(x));
#define g_return_if_fail(x) if(!(x)) return;
#define g_return_val_if_fail(x,y) if (!(x)) return y;
#define g_slice_free(x,y) free(y)
#define g_enum_register_static(x,y) 0
#define g_critical printf
#define g_warning printf
#define GType int
#define SIZE_OVERFLOWS(a,b) (G_UNLIKELY ((b) > 0 && (a) > G_MAXSIZE / (b)))
#define G_LOG_DOMAIN "ERROR"
#define g_assertion_message_expr(domain,file,line,func,expr)		\
do {									\
	if (!expr) {							\
		fprintf(stderr, "**\n%s:%s:%d:%s: %s\n",		\
			domain, file, line, func,			\
			"code should not be reached");			\
	} else {							\
		fprintf(stderr, "**\n%s:%s:%d:%s: "			\
				"assertion failed: (%s)\n",		\
				domain, file, line, func, expr);	\
	}								\
	abort();							\
} while (0)

#define g_print printf
#define g_strdup strdup
#define g_free free
typedef struct {
	int x;
	const char *n;
	const char *m;
} GEnumValue;

#define g_once_init_enter(x) ((*(x) == 0) ? TRUE : FALSE)
#define g_once_init_leave(x,y) (*(x) = y)
#define g_boxed_type_register_static(x, y, z) g_str_hash(x)


static inline void g_type_init() {}
static inline void g_boxed() {}
typedef gpointer        (*GBoxedCopyFunc)       (gpointer s);
typedef void            (*GBoxedFreeFunc)       (gpointer s);
typedef gpointer	      (*GCopyFunc)            (gconstpointer  src, gpointer       data);



/**
 * g_malloc:
 * @n_bytes: the number of bytes to allocate
 * 
 * Allocates @n_bytes bytes of memory.
 * If @n_bytes is 0 it returns %NULL.
 * 
 * Returns: a pointer to the allocated memory
 */
static inline gpointer g_malloc (gsize n_bytes)
{
  if (G_LIKELY (n_bytes))
    {
      gpointer mem;

      mem = malloc (n_bytes);
    //   TRACE (GLIB_MEM_ALLOC((void*) mem, (unsigned int) n_bytes, 0, 0));
      if (mem)
	return mem;

      printf ("%s: failed to allocate %u bytes", G_STRLOC, n_bytes);
    }

//   TRACE(GLIB_MEM_ALLOC((void*) NULL, (int) n_bytes, 0, 0));

  return NULL;
}

/**
 * g_memdup:
 * @mem: the memory to copy.
 * @byte_size: the number of bytes to copy.
 *
 * Allocates @byte_size bytes of memory, and copies @byte_size bytes into it
 * from @mem. If @mem is %NULL it returns %NULL.
 *
 * Returns: a pointer to the newly-allocated copy of the memory, or %NULL if @mem
 *  is %NULL.
 */
static inline gpointer g_memdup (gconstpointer mem, guint byte_size)
{
  gpointer new_mem;

  if (mem && byte_size != 0)
    {
      new_mem = g_malloc (byte_size);
      memcpy (new_mem, mem, byte_size);
    }
  else
    new_mem = NULL;

  return new_mem;
}

/**
 * g_malloc_n:
 * @n_blocks: the number of blocks to allocate
 * @n_block_bytes: the size of each block in bytes
 * 
 * This function is similar to g_malloc(), allocating (@n_blocks * @n_block_bytes) bytes,
 * but care is taken to detect possible overflow during multiplication.
 * 
 * Since: 2.24
 * Returns: a pointer to the allocated memory
 */
static inline gpointer g_malloc_n (gsize n_blocks, gsize n_block_bytes)
{
  if (SIZE_OVERFLOWS (n_blocks, n_block_bytes))
    {
      printf ("%s: overflow allocating %u*%u bytes", G_STRLOC, n_blocks, n_block_bytes);
    }

  return g_malloc (n_blocks * n_block_bytes);
}

#define GLIB_CHECK_VERSION(m,n,o) TRUE

