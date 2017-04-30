/* LGPL3 - posixvala glib replacement - 2013 - pancake@nopcode.org */

#ifndef _GLIB_H_
#define _GLIB_H_

#ifdef __cplusplus
 #define G_BEGIN_DECLS	extern "C" {
 #define G_END_DECLS	}
#else
 #define G_BEGIN_DECLS
 #define G_END_DECLS
#endif /* __cplusplus */

#define emscripten_eval(x) eval(x)

G_BEGIN_DECLS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>


#define GTypeInterface void*
#define GQuark uintptr_t
#define g_quark_from_static_string(x) ((GQuark)(size_t)(x))
#define gfloat float
#define gdouble double
#define gchar char
#define uchar unsigned char
#define guchar unsigned char
#define ushort unsigned short
#define gushort unsigned short
#define ulong unsigned long
#define gulong unsigned long
#define gpointer void*
#define gboolean int
#define gint8 char
#define guint8 unsigned char
#define gint int
#define gint16 short
#define guint16 unsigned short
#define guint unsigned int
#define gint32 int
#define guint32 unsigned int
#define gint64 long long
#define guint64 unsigned long long
#define gunichar guint32
#define glong long
#define gdouble double
#define gsize size_t
#define gssize ssize_t
#define g_new0(x,y) (x*)calloc (y, sizeof(x));
#define g_new(x, y)	(x*)malloc (sizeof(x)*y);	

#define g_slice_new0(x) (x*)calloc (1, sizeof(x));
#define g_return_if_fail(x) if(!(x)) return;
#define g_return_val_if_fail(x,y) if (!(x)) return y;
#define g_slice_free(x,y) free(y)
#define g_enum_register_static(x,y) 0

#define g_critical printf
#define TRUE 1
#define FALSE 0
#define G_GNUC_CONST
#define GType int

/* Define min and max constants for the fixed size numerical types */

#define G_MININT8	((gint8) -0x80)
#define G_MAXINT8	((gint8)  0x7f)
#define G_MAXUINT8	((guint8) 0xff)

#define G_MININT16	((gint16) -0x8000)
#define G_MAXINT16	((gint16)  0x7fff)
#define G_MAXUINT16	((guint16) 0xffff)

#define G_MININT32	((gint32) -0x80000000)
#define G_MAXINT32	((gint32)  0x7fffffff)
#define G_MAXUINT32	((guint32) 0xffffffff)

#define G_MININT64	((gint64) G_GINT64_CONSTANT(-0x8000000000000000))
#define G_MAXINT64	G_GINT64_CONSTANT(0x7fffffffffffffff)
// #define G_MAXUINT64	G_GUINT64_CONSTANT(0xffffffffffffffff)
#define G_MAXUINT64	0xffffffffffffffff

#define G_MAXSIZE	G_MAXUINT64

#define G_LIKELY(expr) (expr)
#define G_UNLIKELY(expr) (expr)
#define SIZE_OVERFLOWS(a,b) (G_UNLIKELY ((b) > 0 && (a) > G_MAXSIZE / (b)))
#define G_LOG_DOMAIN "ERROR"
#define G_STRFUNC __func__
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
typedef gpointer (*GBoxedCopyFunc)(gpointer s);
typedef void (*GBoxedFreeFunc)(gpointer s);
typedef void (*GFunc)(gpointer data, gpointer user_data);
typedef void (*GDestroyNotify)(gpointer data);

//typedef const void *gconstpointer;
typedef void *gconstpointer; // define without 'const' becase valac uses this for non-const values... why?
typedef signed long gintptr;

#define G_STRINGIFY(macro_or_string)	G_STRINGIFY_ARG (macro_or_string)
#define	G_STRINGIFY_ARG(contents)	#contents

/* Provide a string identifying the current code position */
#if defined(__GNUC__) && (__GNUC__ < 3) && !defined(__cplusplus)
#define G_STRLOC	__FILE__ ":" G_STRINGIFY (__LINE__) ":" __PRETTY_FUNCTION__ "()"
#else
#define G_STRLOC	__FILE__ ":" G_STRINGIFY (__LINE__)
#endif

//gpointer g_memdup (gconstpointer mem, guint byte_size);
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

#include "glib-string.h"
#include "glib-list.h"
#include "glib-error.h"

G_END_DECLS

#endif /* _GLIB_H_ */
