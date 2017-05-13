/* Cache.c generated by valac 0.34.8, the Vala compiler
 * generated from Cache.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL_rect.h>
#include <float.h>
#include <math.h>
#include <stdio.h>


#define ENTITAS_TYPE_CACHE (entitas_cache_get_type ())
#define ENTITAS_CACHE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), ENTITAS_TYPE_CACHE, entitasCache))
#define ENTITAS_CACHE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), ENTITAS_TYPE_CACHE, entitasCacheClass))
#define ENTITAS_IS_CACHE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ENTITAS_TYPE_CACHE))
#define ENTITAS_IS_CACHE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), ENTITAS_TYPE_CACHE))
#define ENTITAS_CACHE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), ENTITAS_TYPE_CACHE, entitasCacheClass))

typedef struct _entitasCache entitasCache;
typedef struct _entitasCacheClass entitasCacheClass;
typedef struct _entitasCachePrivate entitasCachePrivate;

#define ENTITAS_TYPE_ENTITY (entitas_entity_get_type ())

#define ENTITAS_TYPE_BACKGROUND (entitas_background_get_type ())
typedef struct _entitasBackground entitasBackground;

#define ENTITAS_TYPE_BULLET (entitas_bullet_get_type ())
typedef struct _entitasBullet entitasBullet;

#define ENTITAS_TYPE_ENEMY1 (entitas_enemy1_get_type ())
typedef struct _entitasEnemy1 entitasEnemy1;

#define ENTITAS_TYPE_ENEMY2 (entitas_enemy2_get_type ())
typedef struct _entitasEnemy2 entitasEnemy2;

#define ENTITAS_TYPE_ENEMY3 (entitas_enemy3_get_type ())
typedef struct _entitasEnemy3 entitasEnemy3;

#define ENTITAS_TYPE_EXPIRES (entitas_expires_get_type ())
typedef struct _entitasExpires entitasExpires;

#define ENTITAS_TYPE_HEALTH (entitas_health_get_type ())
typedef struct _entitasHealth entitasHealth;

#define ENTITAS_TYPE_HUD (entitas_hud_get_type ())
typedef struct _entitasHud entitasHud;

#define ENTITAS_TYPE_INDEX (entitas_index_get_type ())
typedef struct _entitasIndex entitasIndex;

#define ENTITAS_TYPE_LAYER (entitas_layer_get_type ())
typedef struct _entitasLayer entitasLayer;

#define ENTITAS_TYPE_POSITION (entitas_position_get_type ())
typedef struct _entitasPosition entitasPosition;

#define ENTITAS_TYPE_SCALE (entitas_scale_get_type ())
typedef struct _entitasScale entitasScale;

#define ENTITAS_TYPE_SPRITE (entitas_sprite_get_type ())

#define SDX_GRAPHICS_TYPE_SPRITE (sdx_graphics_sprite_get_type ())
#define SDX_GRAPHICS_SPRITE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDX_GRAPHICS_TYPE_SPRITE, sdxgraphicsSprite))
#define SDX_GRAPHICS_SPRITE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SDX_GRAPHICS_TYPE_SPRITE, sdxgraphicsSpriteClass))
#define SDX_GRAPHICS_IS_SPRITE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDX_GRAPHICS_TYPE_SPRITE))
#define SDX_GRAPHICS_IS_SPRITE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SDX_GRAPHICS_TYPE_SPRITE))
#define SDX_GRAPHICS_SPRITE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SDX_GRAPHICS_TYPE_SPRITE, sdxgraphicsSpriteClass))

typedef struct _sdxgraphicsSprite sdxgraphicsSprite;
typedef struct _sdxgraphicsSpriteClass sdxgraphicsSpriteClass;
typedef struct _entitasSprite entitasSprite;

#define ENTITAS_TYPE_TEXT (entitas_text_get_type ())
typedef struct _entitasText entitasText;

#define ENTITAS_TYPE_TINT (entitas_tint_get_type ())
typedef struct _entitasTint entitasTint;

#define ENTITAS_TYPE_TWEEN (entitas_tween_get_type ())
typedef struct _entitasTween entitasTween;

#define ENTITAS_TYPE_VELOCITY (entitas_velocity_get_type ())
typedef struct _entitasVelocity entitasVelocity;
typedef struct _entitasEntity entitasEntity;
#define _g_list_free0(var) ((var == NULL) ? NULL : (var = (g_list_free (var), NULL)))

struct _entitasBackground {
	gboolean active;
};

struct _entitasBullet {
	gboolean active;
};

struct _entitasEnemy1 {
	gboolean active;
};

struct _entitasEnemy2 {
	gboolean active;
};

struct _entitasEnemy3 {
	gboolean active;
};

struct _entitasExpires {
	gdouble value;
};

struct _entitasHealth {
	gdouble current;
	gdouble maximum;
};

struct _entitasHud {
	gboolean active;
};

struct _entitasIndex {
	gint value;
	gint limit;
	gboolean vertical;
};

struct _entitasLayer {
	gint value;
};

struct _entitasPosition {
	gdouble x;
	gdouble y;
};

struct _entitasScale {
	gdouble x;
	gdouble y;
};

struct _entitasSprite {
	sdxgraphicsSprite* sprite;
	gint width;
	gint height;
};

struct _entitasText {
	gchar* text;
	sdxgraphicsSprite* sprite;
};

struct _entitasTint {
	gint r;
	gint g;
	gint b;
	gint a;
};

struct _entitasTween {
	gdouble min;
	gdouble max;
	gdouble speed;
	gboolean repeat;
	gboolean active;
};

struct _entitasVelocity {
	gdouble x;
	gdouble y;
};

struct _entitasEntity {
	gint id;
	gchar* name;
	gint pool;
	guint64 mask;
	entitasBackground* background;
	SDL_Rect* bounds;
	entitasBullet* bullet;
	entitasEnemy1* enemy1;
	entitasEnemy2* enemy2;
	entitasEnemy3* enemy3;
	entitasExpires* expires;
	entitasHealth* health;
	entitasHud* hud;
	entitasIndex* index;
	entitasLayer* layer;
	entitasPosition* position;
	entitasScale* scale;
	entitasSprite* sprite;
	entitasText* text;
	entitasTint* tint;
	entitasTween* tween;
	entitasVelocity* velocity;
};

struct _entitasCache {
	GObject parent_instance;
	entitasCachePrivate * priv;
	entitasEntity** items;
	gint items_length1;
	gint size;
};

struct _entitasCacheClass {
	GObjectClass parent_class;
};


static gpointer entitas_cache_parent_class = NULL;

GType entitas_cache_get_type (void) G_GNUC_CONST;
GType entitas_entity_get_type (void) G_GNUC_CONST;
GType entitas_background_get_type (void) G_GNUC_CONST;
entitasBackground* entitas_background_dup (const entitasBackground* self);
void entitas_background_free (entitasBackground* self);
GType entitas_bullet_get_type (void) G_GNUC_CONST;
entitasBullet* entitas_bullet_dup (const entitasBullet* self);
void entitas_bullet_free (entitasBullet* self);
GType entitas_enemy1_get_type (void) G_GNUC_CONST;
entitasEnemy1* entitas_enemy1_dup (const entitasEnemy1* self);
void entitas_enemy1_free (entitasEnemy1* self);
GType entitas_enemy2_get_type (void) G_GNUC_CONST;
entitasEnemy2* entitas_enemy2_dup (const entitasEnemy2* self);
void entitas_enemy2_free (entitasEnemy2* self);
GType entitas_enemy3_get_type (void) G_GNUC_CONST;
entitasEnemy3* entitas_enemy3_dup (const entitasEnemy3* self);
void entitas_enemy3_free (entitasEnemy3* self);
GType entitas_expires_get_type (void) G_GNUC_CONST;
entitasExpires* entitas_expires_dup (const entitasExpires* self);
void entitas_expires_free (entitasExpires* self);
GType entitas_health_get_type (void) G_GNUC_CONST;
entitasHealth* entitas_health_dup (const entitasHealth* self);
void entitas_health_free (entitasHealth* self);
GType entitas_hud_get_type (void) G_GNUC_CONST;
entitasHud* entitas_hud_dup (const entitasHud* self);
void entitas_hud_free (entitasHud* self);
GType entitas_index_get_type (void) G_GNUC_CONST;
entitasIndex* entitas_index_dup (const entitasIndex* self);
void entitas_index_free (entitasIndex* self);
GType entitas_layer_get_type (void) G_GNUC_CONST;
entitasLayer* entitas_layer_dup (const entitasLayer* self);
void entitas_layer_free (entitasLayer* self);
GType entitas_position_get_type (void) G_GNUC_CONST;
entitasPosition* entitas_position_dup (const entitasPosition* self);
void entitas_position_free (entitasPosition* self);
GType entitas_scale_get_type (void) G_GNUC_CONST;
entitasScale* entitas_scale_dup (const entitasScale* self);
void entitas_scale_free (entitasScale* self);
GType entitas_sprite_get_type (void) G_GNUC_CONST;
GType sdx_graphics_sprite_get_type (void) G_GNUC_CONST;
entitasSprite* entitas_sprite_dup (const entitasSprite* self);
void entitas_sprite_free (entitasSprite* self);
void entitas_sprite_copy (const entitasSprite* self, entitasSprite* dest);
void entitas_sprite_destroy (entitasSprite* self);
GType entitas_text_get_type (void) G_GNUC_CONST;
entitasText* entitas_text_dup (const entitasText* self);
void entitas_text_free (entitasText* self);
void entitas_text_copy (const entitasText* self, entitasText* dest);
void entitas_text_destroy (entitasText* self);
GType entitas_tint_get_type (void) G_GNUC_CONST;
entitasTint* entitas_tint_dup (const entitasTint* self);
void entitas_tint_free (entitasTint* self);
GType entitas_tween_get_type (void) G_GNUC_CONST;
entitasTween* entitas_tween_dup (const entitasTween* self);
void entitas_tween_free (entitasTween* self);
GType entitas_velocity_get_type (void) G_GNUC_CONST;
entitasVelocity* entitas_velocity_dup (const entitasVelocity* self);
void entitas_velocity_free (entitasVelocity* self);
entitasEntity* entitas_entity_dup (const entitasEntity* self);
void entitas_entity_free (entitasEntity* self);
void entitas_entity_copy (const entitasEntity* self, entitasEntity* dest);
void entitas_entity_destroy (entitasEntity* self);
enum  {
	ENTITAS_CACHE_DUMMY_PROPERTY
};
entitasCache* entitas_cache_new (gint capacity);
entitasCache* entitas_cache_construct (GType object_type, gint capacity);
gboolean entitas_cache_isEmpty (entitasCache* self);
entitasEntity* entitas_cache_get (entitasCache* self, gint index);
void entitas_cache_put (entitasCache* self, gint index, entitasEntity* entity);
void entitas_cache_enque (entitasCache* self, entitasEntity* entity);
void entitas_cache_grow (entitasCache* self, gint newSize);
entitasEntity* entitas_cache_deque (entitasCache* self);
static void entitas_cache_finalize (GObject* obj);


entitasCache* entitas_cache_construct (GType object_type, gint capacity) {
	entitasCache * self = NULL;
	gint _tmp0_ = 0;
	entitasEntity** _tmp1_ = NULL;
	self = (entitasCache*) g_object_new (object_type, NULL);
	_tmp0_ = capacity;
	_tmp1_ = g_new0 (entitasEntity*, _tmp0_);
	self->items = (g_free (self->items), NULL);
	self->items = _tmp1_;
	self->items_length1 = _tmp0_;
	self->size = 0;
	return self;
}


entitasCache* entitas_cache_new (gint capacity) {
	return entitas_cache_construct (ENTITAS_TYPE_CACHE, capacity);
}


gboolean entitas_cache_isEmpty (entitasCache* self) {
	gboolean result = FALSE;
	gint _tmp0_ = 0;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->size;
	result = _tmp0_ == 0;
	return result;
}


entitasEntity* entitas_cache_get (entitasCache* self, gint index) {
	entitasEntity* result = NULL;
	gboolean _tmp0_ = FALSE;
	gint _tmp1_ = 0;
	entitasEntity** _tmp6_ = NULL;
	gint _tmp6__length1 = 0;
	gint _tmp7_ = 0;
	entitasEntity* _tmp8_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp1_ = index;
	if (_tmp1_ < 0) {
		_tmp0_ = TRUE;
	} else {
		gint _tmp2_ = 0;
		gint _tmp3_ = 0;
		_tmp2_ = index;
		_tmp3_ = self->size;
		_tmp0_ = _tmp2_ > _tmp3_;
	}
	if (_tmp0_) {
		FILE* _tmp4_ = NULL;
		gint _tmp5_ = 0;
		_tmp4_ = stdout;
		_tmp5_ = index;
		fprintf (_tmp4_, "Can't get cache at %d\n", _tmp5_);
		result = NULL;
		return result;
	}
	_tmp6_ = self->items;
	_tmp6__length1 = self->items_length1;
	_tmp7_ = index;
	_tmp8_ = _tmp6_[_tmp7_];
	result = _tmp8_;
	return result;
}


void entitas_cache_put (entitasCache* self, gint index, entitasEntity* entity) {
	gboolean _tmp0_ = FALSE;
	gint _tmp1_ = 0;
	entitasEntity** _tmp6_ = NULL;
	gint _tmp6__length1 = 0;
	gint _tmp7_ = 0;
	entitasEntity* _tmp8_ = NULL;
	entitasEntity* _tmp9_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp1_ = index;
	if (_tmp1_ < 0) {
		_tmp0_ = TRUE;
	} else {
		gint _tmp2_ = 0;
		gint _tmp3_ = 0;
		_tmp2_ = index;
		_tmp3_ = self->size;
		_tmp0_ = _tmp2_ >= _tmp3_;
	}
	if (_tmp0_) {
		FILE* _tmp4_ = NULL;
		gint _tmp5_ = 0;
		_tmp4_ = stdout;
		_tmp5_ = index;
		fprintf (_tmp4_, "Can't put cache at %d\n", _tmp5_);
		return;
	}
	_tmp6_ = self->items;
	_tmp6__length1 = self->items_length1;
	_tmp7_ = index;
	_tmp8_ = entity;
	_tmp6_[_tmp7_] = _tmp8_;
	_tmp9_ = _tmp6_[_tmp7_];
}


void entitas_cache_enque (entitasCache* self, entitasEntity* entity) {
	gint _tmp0_ = 0;
	entitasEntity** _tmp1_ = NULL;
	gint _tmp1__length1 = 0;
	entitasEntity** _tmp3_ = NULL;
	gint _tmp3__length1 = 0;
	gint _tmp4_ = 0;
	entitasEntity* _tmp5_ = NULL;
	entitasEntity* _tmp6_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->size;
	_tmp1_ = self->items;
	_tmp1__length1 = self->items_length1;
	if (_tmp0_ >= _tmp1__length1) {
		entitasEntity** _tmp2_ = NULL;
		gint _tmp2__length1 = 0;
		_tmp2_ = self->items;
		_tmp2__length1 = self->items_length1;
		entitas_cache_grow (self, _tmp2__length1 * 2);
	}
	_tmp3_ = self->items;
	_tmp3__length1 = self->items_length1;
	_tmp4_ = self->size;
	self->size = _tmp4_ + 1;
	_tmp5_ = entity;
	_tmp3_[_tmp4_] = _tmp5_;
	_tmp6_ = _tmp3_[_tmp4_];
}


entitasEntity* entitas_cache_deque (entitasCache* self) {
	entitasEntity* result = NULL;
	gint _tmp0_ = 0;
	entitasEntity** _tmp2_ = NULL;
	gint _tmp2__length1 = 0;
	gint _tmp3_ = 0;
	gint _tmp4_ = 0;
	entitasEntity* _tmp5_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->size;
	if (_tmp0_ <= 0) {
		FILE* _tmp1_ = NULL;
		_tmp1_ = stdout;
		fprintf (_tmp1_, "Unable to pop from queue\n");
		result = NULL;
		return result;
	}
	_tmp2_ = self->items;
	_tmp2__length1 = self->items_length1;
	_tmp3_ = self->size;
	self->size = _tmp3_ - 1;
	_tmp4_ = self->size;
	_tmp5_ = _tmp2_[_tmp4_];
	result = _tmp5_;
	return result;
}


void entitas_cache_grow (entitasCache* self, gint newSize) {
	GList* temp = NULL;
	entitasEntity** _tmp0_ = NULL;
	gint _tmp0__length1 = 0;
	gint _tmp2_ = 0;
	entitasEntity** _tmp3_ = NULL;
	gint i = 0;
	GList* _tmp4_ = NULL;
	g_return_if_fail (self != NULL);
	temp = NULL;
	_tmp0_ = self->items;
	_tmp0__length1 = self->items_length1;
	{
		entitasEntity** item_collection = NULL;
		gint item_collection_length1 = 0;
		gint _item_collection_size_ = 0;
		gint item_it = 0;
		item_collection = _tmp0_;
		item_collection_length1 = _tmp0__length1;
		for (item_it = 0; item_it < _tmp0__length1; item_it = item_it + 1) {
			entitasEntity* item = NULL;
			item = item_collection[item_it];
			{
				entitasEntity* _tmp1_ = NULL;
				_tmp1_ = item;
				temp = g_list_prepend (temp, _tmp1_);
			}
		}
	}
	_tmp2_ = newSize;
	_tmp3_ = g_new0 (entitasEntity*, _tmp2_);
	self->items = (g_free (self->items), NULL);
	self->items = _tmp3_;
	self->items_length1 = _tmp2_;
	i = 0;
	_tmp4_ = temp;
	{
		GList* item_collection = NULL;
		GList* item_it = NULL;
		item_collection = _tmp4_;
		for (item_it = item_collection; item_it != NULL; item_it = item_it->next) {
			entitasEntity* item = NULL;
			item = item_it->data;
			{
				entitasEntity** _tmp5_ = NULL;
				gint _tmp5__length1 = 0;
				gint _tmp6_ = 0;
				entitasEntity* _tmp7_ = NULL;
				entitasEntity* _tmp8_ = NULL;
				_tmp5_ = self->items;
				_tmp5__length1 = self->items_length1;
				_tmp6_ = i;
				i = _tmp6_ + 1;
				_tmp7_ = item;
				_tmp5_[_tmp6_] = _tmp7_;
				_tmp8_ = _tmp5_[_tmp6_];
			}
		}
	}
	_g_list_free0 (temp);
}


static void entitas_cache_class_init (entitasCacheClass * klass) {
	entitas_cache_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->finalize = entitas_cache_finalize;
}


static void entitas_cache_instance_init (entitasCache * self) {
}


static void entitas_cache_finalize (GObject* obj) {
	entitasCache * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, ENTITAS_TYPE_CACHE, entitasCache);
	self->items = (g_free (self->items), NULL);
	G_OBJECT_CLASS (entitas_cache_parent_class)->finalize (obj);
}


GType entitas_cache_get_type (void) {
	static volatile gsize entitas_cache_type_id__volatile = 0;
	if (g_once_init_enter (&entitas_cache_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (entitasCacheClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) entitas_cache_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (entitasCache), 0, (GInstanceInitFunc) entitas_cache_instance_init, NULL };
		GType entitas_cache_type_id;
		entitas_cache_type_id = g_type_register_static (G_TYPE_OBJECT, "entitasCache", &g_define_type_info, 0);
		g_once_init_leave (&entitas_cache_type_id__volatile, entitas_cache_type_id);
	}
	return entitas_cache_type_id__volatile;
}



