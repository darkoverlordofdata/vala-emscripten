#ifndef _GLIB_STRING_H_
#define _GLIB_STRING_H_

/* For vsnprintf(3) */
#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 200112L
#endif /* _POSIX_C_SOURCE */

#include <stdarg.h>

/** @return a pointer to the next unicode point in a _valid_ unicode string or null if s points to the last character. */
static inline const gchar* g_utf8_next_char (const gchar *s) {
	unsigned char ch = *s;
	if (ch == '\0') return NULL;
	if (ch < 0x80) return s+1;
	if (ch < 0xE0) return s + 2;
	if (ch < 0xF0) return s + 3;
	if (ch < 0xF5) return s + 4;
	return NULL;
}

static inline guint g_str_hash(const gpointer v) {
	const char *str = v;
	guint hash = 5381;
	gchar c;

	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;

	return hash;
}

static inline char *g_strdup_printf(const char *fmt, ...) {
	unsigned int length;
	char *buf = NULL;
	va_list ap;
	va_start (ap, fmt);
	/* Get the length of the result */
	length = (unsigned int)vsnprintf(buf, 0, fmt, ap);
	/* Must include space for the NULL-terminating byte. */
	buf = calloc(length + 1, sizeof(char));
	/* Actually create string, copies NULL byte too */
	vsnprintf(buf, length + 1, fmt, ap);
	va_end (ap);
	return buf;
}

static inline char *g_strconcat(const char *str, ...) {
	int plen, olen;
	const char *p;
	char *out;
	va_list ap;

	va_start (ap, str);
	out = strdup (str);
	olen = strlen (out);
	for (;;) {
        	p = va_arg (ap, char*);
		if (!p) break;
		plen = strlen (p);
		out = realloc (out, plen + olen+1);
		strcpy (out+olen, p);
		olen += plen;
	}
	va_end (ap);
	return out;
}

/**
 * g_strcmp0:
 * @str1: (nullable): a C string or %NULL
 * @str2: (nullable): another C string or %NULL
 *
 * Compares @str1 and @str2 like strcmp(). Handles %NULL
 * gracefully by sorting it before non-%NULL strings.
 * Comparing two %NULL pointers returns 0.
 *
 * Returns: an integer less than, equal to, or greater than zero, if @str1 is <, == or > than @str2.
 *
 * Since: 2.16
 */
static inline int g_strcmp0 (const char *str1, const char *str2)
{
  if (!str1)
    return -(str1 != str2);
  if (!str2)
    return str1 != str2;
  return strcmp (str1, str2);
}

/**
 * g_strndup:
 * @str: the string to duplicate
 * @n: the maximum number of bytes to copy from @str
 *
 * Duplicates the first @n bytes of a string, returning a newly-allocated
 * buffer @n + 1 bytes long which will always be nul-terminated. If @str
 * is less than @n bytes long the buffer is padded with nuls. If @str is
 * %NULL it returns %NULL. The returned value should be freed when no longer
 * needed.
 *
 * To copy a number of characters from a UTF-8 encoded string,
 * use g_utf8_strncpy() instead.
 *
 * Returns: a newly-allocated buffer containing the first @n bytes
 *     of @str, nul-terminated
 */
static inline gchar *g_strndup (const gchar *str, gsize n)
{
  gchar *new_str;

  if (str)
    {
      new_str = g_new (gchar, n + 1);
      strncpy (new_str, str, n);
      new_str[n] = '\0';
    }
  else
    new_str = NULL;

  return new_str;
}

/**
 * g_ascii_tolower:
 * @c: any character
 *
 * Convert a character to ASCII lower case.
 *
 * Unlike the standard C library tolower() function, this only
 * recognizes standard ASCII letters and ignores the locale, returning
 * all non-ASCII characters unchanged, even if they are lower case
 * letters in a particular character set. Also unlike the standard
 * library function, this takes and returns a char, not an int, so
 * don't call it on %EOF but no need to worry about casting to #guchar
 * before passing a possibly non-ASCII character in.
 *
 * Returns: the result of converting @c to lower case. If @c is
 *     not an ASCII upper case letter, @c is returned unchanged.
 */
static inline gchar g_ascii_tolower (gchar c)
{
	return (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
}
/**
 * g_ascii_toupper:
 * @c: any character
 *
 * Convert a character to ASCII upper case.
 *
 * Unlike the standard C library toupper() function, this only
 * recognizes standard ASCII letters and ignores the locale, returning
 * all non-ASCII characters unchanged, even if they are upper case
 * letters in a particular character set. Also unlike the standard
 * library function, this takes and returns a char, not an int, so
 * don't call it on %EOF but no need to worry about casting to #guchar
 * before passing a possibly non-ASCII character in.
 *
 * Returns: the result of converting @c to upper case. If @c is not
 *    an ASCII lower case letter, @c is returned unchanged.
 */
static inline gchar g_ascii_toupper (gchar c)
{
	  return (c >= 'a' && c <= 'z') ? c - 'a' + 'A' : c;
}

/**
 * g_ascii_strup:
 * @str: a string
 * @len: length of @str in bytes, or -1 if @str is nul-terminated
 *
 * Converts all lower case ASCII letters to upper case ASCII letters.
 *
 * Returns: a newly allocated string, with all the lower case
 *     characters in @str converted to upper case, with semantics that
 *     exactly match g_ascii_toupper(). (Note that this is unlike the
 *     old g_strup(), which modified the string in place.)
 */
static inline gchar *g_utf8_strup (const gchar *str, gssize len)
{
  gchar *result, *s;

  g_return_val_if_fail (str != NULL, NULL);

  if (len < 0)
    len = strlen (str);

  result = g_strndup (str, len);
  for (s = result; *s; s++) 
    *s = g_ascii_toupper (*s);
  

  return result;
}

/**
 * g_ascii_strdown:
 * @str: a string
 * @len: length of @str in bytes, or -1 if @str is nul-terminated
 *
 * Converts all upper case ASCII letters to lower case ASCII letters.
 *
 * Returns: a newly-allocated string, with all the upper case
 *     characters in @str converted to lower case, with semantics that
 *     exactly match g_ascii_tolower(). (Note that this is unlike the
 *     old g_strdown(), which modified the string in place.)
 */
static inline gchar *g_utf8_strdown (const gchar *str, gssize len)
{
  gchar *result, *s;

  g_return_val_if_fail (str != NULL, NULL);

  if (len < 0)
    len = strlen (str);

  result = g_strndup (str, len);
  for (s = result; *s; s++)
    *s = g_ascii_tolower (*s);

  return result;
}

/**
 * g_strreverse:
 * @string: the string to reverse
 *
 * Reverses all of the bytes in a string. For example,
 * `g_strreverse ("abcdef")` will result in "fedcba".
 *
 * Note that g_strreverse() doesn't work on UTF-8 strings
 * containing multibyte characters. For that purpose, use
 * g_utf8_strreverse().
 *
 * Returns: the same pointer passed in as @string
 */
static inline gchar *g_utf8_strreverse (const gchar *str, gssize len)
{
  	gchar *result, *s, *t;

  	g_return_val_if_fail (str != NULL, NULL);

  	if (len < 0)
    	len = strlen (str);
  	result = g_strndup (str, len);
	s = result;
	t = result + strlen (result) - 1;

    while (s < t)
    {
          gchar c;

          c = *s;
          *s = *t;
          s++;
          *t = c;
          t--;
        
    }

  return result;
}

#endif /* _GLIB_STRING_H_ */

