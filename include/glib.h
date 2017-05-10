/* GLIB - Library of useful routines for C programming
 * Copyright (C) 1995-1997  Peter Mattis, Spencer Kimball and Josh MacDonald
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

/*
 * Modified by the GLib Team and others 1997-2000.  See the AUTHORS
 * file for a list of people on the GLib Team.  See the ChangeLog
 * files for a list of changes.  These files are distributed with
 * GLib at ftp://ftp.gtk.org/pub/gtk/.
 */

/*
 * Modifications by bruce davidson, 2017.
 * re jiggered as a static inline module to replace GLib 
 * when compiling vala standalone, for example when 
 * targeting Emscripten or Android
 * LGPL3 - the dark vala - 2017 - darkoverlordofdata 
 */

/* LGPL3 - posixvala glib replacement - 2013 - pancake@nopcode.org */
/* LGPL3 - additions - 2017 - darkoverlordofdata */

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

// glib.config.h.emscripten:


#define G_MINFLOAT	FLT_MIN
#define G_MAXFLOAT	FLT_MAX
#define G_MINDOUBLE	DBL_MIN
#define G_MAXDOUBLE	DBL_MAX
#define G_MINSHORT	SHRT_MIN
#define G_MAXSHORT	SHRT_MAX
#define G_MAXUSHORT	USHRT_MAX
#define G_MININT	INT_MIN
#define G_MAXINT	INT_MAX
#define G_MAXUINT	UINT_MAX
#define G_MINLONG	LONG_MIN
#define G_MAXLONG	LONG_MAX
#define G_MAXULONG	ULONG_MAX
#define G_MAXSIZE	G_MAXUINT64
#define GPOINTER_TO_INT(p)	((gint)   (p))
#define GPOINTER_TO_UINT(p)	((guint)  (p))
#define GINT_TO_POINTER(i)	((gpointer)  (i))
#define GUINT_TO_POINTER(u)	((gpointer)  (u))

#define gsize size_t
#define gssize ssize_t

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <assert.h>
#include <time.h>

#include <glib/gmacros.h>
#include <glib/gversionmacros.h>
#include <glib/gtypes.h>
#include <glib/gatomic.h>
#include <glib/misc.h>
#include <glib/glist.h>
#include <glib/gslist.h>
#include <glib/gstring.h>
#include <glib/gerror.h>
#include <glib/ghash.h>
#include <glib/gque.h>

G_END_DECLS

#endif /* _GLIB_H_ */
