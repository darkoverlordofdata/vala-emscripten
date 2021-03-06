/* Font.c generated by valac 0.34.8, the Vala compiler
 * generated from Font.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <SDL_ttf.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_surface.h>


#define SDX_TYPE_FONT (sdx_font_get_type ())
#define SDX_FONT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_TYPE_FONT, sdxFont))
#define SDX_FONT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SDX_TYPE_FONT, sdxFontClass))
#define SDX_IS_FONT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_TYPE_FONT))
#define SDX_IS_FONT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SDX_TYPE_FONT))
#define SDX_FONT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SDX_TYPE_FONT, sdxFontClass))

typedef struct _sdxFont sdxFont;
typedef struct _sdxFontClass sdxFontClass;
typedef struct _sdxFontPrivate sdxFontPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _TTF_CloseFont0(var) ((var == NULL) ? NULL : (var = (TTF_CloseFont (var), NULL)))

struct _sdxFont {
	GObject parent_instance;
	sdxFontPrivate * priv;
	gint id;
	gchar* path;
	gint size;
	TTF_Font* innerFont;
};

struct _sdxFontClass {
	GObjectClass parent_class;
};


static gpointer sdx_font_parent_class = NULL;
extern gint sdx_font_uniqueId;
gint sdx_font_uniqueId = 0;

GType sdx_font_get_type (void) G_GNUC_CONST;
enum  {
	SDX_FONT_DUMMY_PROPERTY
};
sdxFont* sdx_font_new (const gchar* path, gint size);
sdxFont* sdx_font_construct (GType object_type, const gchar* path, gint size);
SDL_Surface* sdx_font_render (sdxFont* self, const gchar* text, SDL_Color color);
static void sdx_font_finalize (GObject* obj);


sdxFont* sdx_font_construct (GType object_type, const gchar* path, gint size) {
	sdxFont * self = NULL;
	const gchar* _tmp0_ = NULL;
	gint _tmp1_ = 0;
	TTF_Font* _tmp2_ = NULL;
	const gchar* _tmp3_ = NULL;
	gchar* _tmp4_ = NULL;
	gint _tmp5_ = 0;
	g_return_val_if_fail (path != NULL, NULL);
	self = (sdxFont*) g_object_new (object_type, NULL);
	_tmp0_ = path;
	_tmp1_ = size;
	_tmp2_ = TTF_OpenFont (_tmp0_, _tmp1_);
	_TTF_CloseFont0 (self->innerFont);
	self->innerFont = _tmp2_;
	_tmp3_ = path;
	_tmp4_ = g_strdup (_tmp3_);
	_g_free0 (self->path);
	self->path = _tmp4_;
	_tmp5_ = size;
	self->size = _tmp5_;
	return self;
}


sdxFont* sdx_font_new (const gchar* path, gint size) {
	return sdx_font_construct (SDX_TYPE_FONT, path, size);
}


/**
 *  Render text for Sprite.fromRenderedText
 *
 * @param text to generate surface from
 * @param color foreground color of text
 * @return new Surface
 */
SDL_Surface* sdx_font_render (sdxFont* self, const gchar* text, SDL_Color color) {
	SDL_Surface* result = NULL;
	TTF_Font* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	SDL_Color _tmp2_ = {0};
	SDL_Surface* _tmp3_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (text != NULL, NULL);
	_tmp0_ = self->innerFont;
	_tmp1_ = text;
	_tmp2_ = color;
	_tmp3_ = TTF_RenderUTF8_Solid (_tmp0_, _tmp1_, _tmp2_);
	result = _tmp3_;
	return result;
}


static void sdx_font_class_init (sdxFontClass * klass) {
	sdx_font_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->finalize = sdx_font_finalize;
}


static void sdx_font_instance_init (sdxFont * self) {
	gint _tmp0_ = 0;
	gint _tmp1_ = 0;
	_tmp0_ = sdx_font_uniqueId;
	sdx_font_uniqueId = _tmp0_ + 1;
	_tmp1_ = sdx_font_uniqueId;
	self->id = _tmp1_;
}


static void sdx_font_finalize (GObject* obj) {
	sdxFont * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, SDX_TYPE_FONT, sdxFont);
	_g_free0 (self->path);
	_TTF_CloseFont0 (self->innerFont);
	G_OBJECT_CLASS (sdx_font_parent_class)->finalize (obj);
}


GType sdx_font_get_type (void) {
	static volatile gsize sdx_font_type_id__volatile = 0;
	if (g_once_init_enter (&sdx_font_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (sdxFontClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) sdx_font_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (sdxFont), 0, (GInstanceInitFunc) sdx_font_instance_init, NULL };
		GType sdx_font_type_id;
		sdx_font_type_id = g_type_register_static (G_TYPE_OBJECT, "sdxFont", &g_define_type_info, 0);
		g_once_init_leave (&sdx_font_type_id__volatile, sdx_font_type_id);
	}
	return sdx_font_type_id__volatile;
}



