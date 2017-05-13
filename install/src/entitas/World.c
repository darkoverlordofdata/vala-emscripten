/* World.c generated by valac 0.34.8, the Vala compiler
 * generated from World.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL_rect.h>
#include <float.h>
#include <math.h>


#define ENTITAS_TYPE_WORLD (entitas_world_get_type ())
#define ENTITAS_WORLD(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), ENTITAS_TYPE_WORLD, entitasWorld))
#define ENTITAS_WORLD_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), ENTITAS_TYPE_WORLD, entitasWorldClass))
#define ENTITAS_IS_WORLD(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ENTITAS_TYPE_WORLD))
#define ENTITAS_IS_WORLD_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), ENTITAS_TYPE_WORLD))
#define ENTITAS_WORLD_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), ENTITAS_TYPE_WORLD, entitasWorldClass))

typedef struct _entitasWorld entitasWorld;
typedef struct _entitasWorldClass entitasWorldClass;
typedef struct _entitasWorldPrivate entitasWorldPrivate;

#define ENTITAS_TYPE_GROUP (entitas_group_get_type ())
#define ENTITAS_GROUP(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), ENTITAS_TYPE_GROUP, entitasGroup))
#define ENTITAS_GROUP_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), ENTITAS_TYPE_GROUP, entitasGroupClass))
#define ENTITAS_IS_GROUP(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ENTITAS_TYPE_GROUP))
#define ENTITAS_IS_GROUP_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), ENTITAS_TYPE_GROUP))
#define ENTITAS_GROUP_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), ENTITAS_TYPE_GROUP, entitasGroupClass))

typedef struct _entitasGroup entitasGroup;
typedef struct _entitasGroupClass entitasGroupClass;

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

#define ENTITAS_TYPE_CACHE (entitas_cache_get_type ())
#define ENTITAS_CACHE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), ENTITAS_TYPE_CACHE, entitasCache))
#define ENTITAS_CACHE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), ENTITAS_TYPE_CACHE, entitasCacheClass))
#define ENTITAS_IS_CACHE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ENTITAS_TYPE_CACHE))
#define ENTITAS_IS_CACHE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), ENTITAS_TYPE_CACHE))
#define ENTITAS_CACHE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), ENTITAS_TYPE_CACHE, entitasCacheClass))

typedef struct _entitasCache entitasCache;
typedef struct _entitasCacheClass entitasCacheClass;

#define ENTITAS_TYPE_ISYSTEM (entitas_isystem_get_type ())
typedef struct _entitasISystem entitasISystem;
#define __g_list_free__g_object_unref0_0(var) ((var == NULL) ? NULL : (var = (_g_list_free__g_object_unref0_ (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define ENTITAS_TYPE_COMPONENTS (entitas_components_get_type ())

#define ENTITAS_TYPE_BUFFER (entitas_buffer_get_type ())
typedef struct _entitasBuffer entitasBuffer;
#define _entitas_isystem_free0(var) ((var == NULL) ? NULL : (var = (entitas_isystem_free (var), NULL)))

#define ENTITAS_TYPE_MATCHER (entitas_matcher_get_type ())
#define ENTITAS_MATCHER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), ENTITAS_TYPE_MATCHER, entitasMatcher))
#define ENTITAS_MATCHER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), ENTITAS_TYPE_MATCHER, entitasMatcherClass))
#define ENTITAS_IS_MATCHER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ENTITAS_TYPE_MATCHER))
#define ENTITAS_IS_MATCHER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), ENTITAS_TYPE_MATCHER))
#define ENTITAS_MATCHER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), ENTITAS_TYPE_MATCHER, entitasMatcherClass))

typedef struct _entitasMatcher entitasMatcher;
typedef struct _entitasMatcherClass entitasMatcherClass;
typedef struct _entitasMatcherPrivate entitasMatcherPrivate;

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

typedef void (*entitasSystemInitialize) (void* user_data);
typedef void (*entitasSystemExecute) (gdouble delta, void* user_data);
struct _entitasISystem {
	entitasSystemInitialize initialize;
	gpointer initialize_target;
	entitasSystemExecute execute;
	gpointer execute_target;
};

typedef entitasEntity* (*entitasEntityRemovedListener) (entitasEntity* e, void* user_data);
struct _entitasWorld {
	GObject parent_instance;
	entitasWorldPrivate * priv;
	GList* groups;
	entitasEntity* pool;
	gint pool_length1;
	entitasCache** cache;
	gint cache_length1;
	gint id;
	entitasISystem** systems;
	gint systems_length1;
	gint count;
	entitasEntityRemovedListener entityRemoved;
	gpointer entityRemoved_target;
	GDestroyNotify entityRemoved_target_destroy_notify;
};

struct _entitasWorldClass {
	GObjectClass parent_class;
};

typedef enum  {
	ENTITAS_COMPONENTS_BackgroundComponent = 1,
	ENTITAS_COMPONENTS_BoundsComponent,
	ENTITAS_COMPONENTS_BulletComponent,
	ENTITAS_COMPONENTS_Enemy1Component,
	ENTITAS_COMPONENTS_Enemy2Component,
	ENTITAS_COMPONENTS_Enemy3Component,
	ENTITAS_COMPONENTS_ExpiresComponent,
	ENTITAS_COMPONENTS_HealthComponent,
	ENTITAS_COMPONENTS_HudComponent,
	ENTITAS_COMPONENTS_IndexComponent,
	ENTITAS_COMPONENTS_LayerComponent,
	ENTITAS_COMPONENTS_PositionComponent,
	ENTITAS_COMPONENTS_ScaleComponent,
	ENTITAS_COMPONENTS_SoundComponent,
	ENTITAS_COMPONENTS_SpriteComponent,
	ENTITAS_COMPONENTS_TextComponent,
	ENTITAS_COMPONENTS_TintComponent,
	ENTITAS_COMPONENTS_TweenComponent,
	ENTITAS_COMPONENTS_VelocityComponent,
	ENTITAS_COMPONENTS_COUNT = 19
} entitasComponents;

typedef entitasEntity* (*entitasFactory) (void* user_data);
struct _entitasBuffer {
	gint pool;
	gint size;
	entitasFactory factory;
	gpointer factory_target;
	GDestroyNotify factory_target_destroy_notify;
};

struct _entitasMatcher {
	GObject parent_instance;
	entitasMatcherPrivate * priv;
	gint id;
	gint* allOfIndices;
	gint allOfIndices_length1;
	guint64 allOfMask;
	gint* anyOfIndices;
	gint anyOfIndices_length1;
	guint64 anyOfMask;
	gint* noneOfIndices;
	gint noneOfIndices_length1;
	guint64 noneOfMask;
	gint* indices;
	gint indices_length1;
	gchar* toStringCache;
};

struct _entitasMatcherClass {
	GObjectClass parent_class;
};


static gpointer entitas_world_parent_class = NULL;
extern entitasWorld* entitas_world_instance;
entitasWorld* entitas_world_instance = NULL;

GType entitas_world_get_type (void) G_GNUC_CONST;
GType entitas_group_get_type (void) G_GNUC_CONST;
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
GType entitas_cache_get_type (void) G_GNUC_CONST;
GType entitas_isystem_get_type (void) G_GNUC_CONST;
entitasISystem* entitas_isystem_dup (const entitasISystem* self);
void entitas_isystem_free (entitasISystem* self);
enum  {
	ENTITAS_WORLD_DUMMY_PROPERTY
};
static void _g_object_unref0_ (gpointer var);
static void _g_list_free__g_object_unref0_ (GList* self);
static void _vala_entitasEntity_array_free (entitasEntity* array, gint array_length);
entitasWorld* entitas_world_new (void);
entitasWorld* entitas_world_construct (GType object_type);
GType entitas_components_get_type (void) G_GNUC_CONST;
void entitas_world_onComponentAdded (entitasEntity* e, entitasComponents c);
void entitas_world_componentAddedOrRemoved (entitasWorld* self, entitasEntity* entity, entitasComponents component);
void entitas_world_onComponentRemoved (entitasEntity* e, entitasComponents c);
GType entitas_buffer_get_type (void) G_GNUC_CONST;
entitasBuffer* entitas_buffer_dup (const entitasBuffer* self);
void entitas_buffer_free (entitasBuffer* self);
void entitas_buffer_copy (const entitasBuffer* self, entitasBuffer* dest);
void entitas_buffer_destroy (entitasBuffer* self);
void entitas_world_setPool (entitasWorld* self, gint size, gint count, entitasBuffer* buffers, int buffers_length1);
entitasCache* entitas_cache_new (gint capacity);
entitasCache* entitas_cache_construct (GType object_type, gint capacity);
void entitas_cache_enque (entitasCache* self, entitasEntity* entity);
void entitas_world_addSystem (entitasWorld* self, entitasISystem iface);
void entitas_world_initialize (entitasWorld* self);
void entitas_world_execute (entitasWorld* self, gdouble delta);
void entitas_world_setEntityRemovedListener (entitasWorld* self, entitasEntityRemovedListener removed, void* removed_target);
void entitas_group_handleEntity (entitasGroup* self, entitasEntity* entity, entitasComponents index);
void entitas_world_deleteEntity (entitasWorld* self, entitasEntity* entity);
entitasEntity* entitas_entity_setActive (entitasEntity *self, gboolean active);
entitasEntity* entitas_world_createEntity (entitasWorld* self, const gchar* name, gint pool, gboolean active);
entitasEntity* entitas_entity_setId (entitasEntity *self, gint id);
entitasEntity* entitas_entity_setName (entitasEntity *self, const gchar* name);
entitasEntity* entitas_entity_setPool (entitasEntity *self, gint pool);
GType entitas_matcher_get_type (void) G_GNUC_CONST;
entitasGroup* entitas_world_getGroup (entitasWorld* self, entitasMatcher* matcher);
entitasGroup* entitas_group_new (entitasMatcher* matcher);
entitasGroup* entitas_group_construct (GType object_type, entitasMatcher* matcher);
void entitas_group_handleEntitySilently (entitasGroup* self, entitasEntity* entity);
static void entitas_world_finalize (GObject* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);


static void _g_object_unref0_ (gpointer var) {
	(var == NULL) ? NULL : (var = (g_object_unref (var), NULL));
}


static void _g_list_free__g_object_unref0_ (GList* self) {
	g_list_foreach (self, (GFunc) _g_object_unref0_, NULL);
	g_list_free (self);
}


static void _vala_entitasEntity_array_free (entitasEntity* array, gint array_length) {
	if (array != NULL) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			entitas_entity_destroy (&array[i]);
		}
	}
	g_free (array);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


entitasWorld* entitas_world_construct (GType object_type) {
	entitasWorld * self = NULL;
	entitasWorld* _tmp0_ = NULL;
	self = (entitasWorld*) g_object_new (object_type, NULL);
	_tmp0_ = _g_object_ref0 (self);
	_g_object_unref0 (entitas_world_instance);
	entitas_world_instance = _tmp0_;
	return self;
}


entitasWorld* entitas_world_new (void) {
	return entitas_world_construct (ENTITAS_TYPE_WORLD);
}


void entitas_world_onComponentAdded (entitasEntity* e, entitasComponents c) {
	entitasWorld* _tmp0_ = NULL;
	entitasEntity* _tmp1_ = NULL;
	entitasComponents _tmp2_ = 0;
	_tmp0_ = entitas_world_instance;
	_tmp1_ = e;
	_tmp2_ = c;
	entitas_world_componentAddedOrRemoved (_tmp0_, _tmp1_, _tmp2_);
}


void entitas_world_onComponentRemoved (entitasEntity* e, entitasComponents c) {
	entitasWorld* _tmp0_ = NULL;
	entitasEntity* _tmp1_ = NULL;
	entitasComponents _tmp2_ = 0;
	_tmp0_ = entitas_world_instance;
	_tmp1_ = e;
	_tmp2_ = c;
	entitas_world_componentAddedOrRemoved (_tmp0_, _tmp1_, _tmp2_);
}


void entitas_world_setPool (entitasWorld* self, gint size, gint count, entitasBuffer* buffers, int buffers_length1) {
	gint _tmp0_ = 0;
	entitasEntity* _tmp1_ = NULL;
	gint _tmp2_ = 0;
	entitasCache** _tmp3_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = size;
	_tmp1_ = g_new0 (entitasEntity, _tmp0_);
	self->pool = (_vala_entitasEntity_array_free (self->pool, self->pool_length1), NULL);
	self->pool = _tmp1_;
	self->pool_length1 = _tmp0_;
	_tmp2_ = count;
	_tmp3_ = g_new0 (entitasCache*, _tmp2_ + 1);
	self->cache = (_vala_array_free (self->cache, self->cache_length1, (GDestroyNotify) g_object_unref), NULL);
	self->cache = _tmp3_;
	self->cache_length1 = _tmp2_;
	{
		gint i = 0;
		i = 0;
		{
			gboolean _tmp4_ = FALSE;
			_tmp4_ = TRUE;
			while (TRUE) {
				gint _tmp6_ = 0;
				entitasBuffer* _tmp7_ = NULL;
				gint _tmp7__length1 = 0;
				gint iPool = 0;
				entitasBuffer* _tmp8_ = NULL;
				gint _tmp8__length1 = 0;
				gint _tmp9_ = 0;
				entitasBuffer _tmp10_ = {0};
				gint _tmp11_ = 0;
				gint iSize = 0;
				entitasBuffer* _tmp12_ = NULL;
				gint _tmp12__length1 = 0;
				gint _tmp13_ = 0;
				entitasBuffer _tmp14_ = {0};
				gint _tmp15_ = 0;
				entitasCache** _tmp16_ = NULL;
				gint _tmp16__length1 = 0;
				gint _tmp17_ = 0;
				entitasCache* _tmp18_ = NULL;
				entitasCache* _tmp19_ = NULL;
				if (!_tmp4_) {
					gint _tmp5_ = 0;
					_tmp5_ = i;
					i = _tmp5_ + 1;
				}
				_tmp4_ = FALSE;
				_tmp6_ = i;
				_tmp7_ = buffers;
				_tmp7__length1 = buffers_length1;
				if (!(_tmp6_ < _tmp7__length1)) {
					break;
				}
				_tmp8_ = buffers;
				_tmp8__length1 = buffers_length1;
				_tmp9_ = i;
				_tmp10_ = _tmp8_[_tmp9_];
				_tmp11_ = _tmp10_.pool;
				iPool = _tmp11_;
				_tmp12_ = buffers;
				_tmp12__length1 = buffers_length1;
				_tmp13_ = i;
				_tmp14_ = _tmp12_[_tmp13_];
				_tmp15_ = _tmp14_.size;
				iSize = _tmp15_;
				_tmp16_ = self->cache;
				_tmp16__length1 = self->cache_length1;
				_tmp17_ = iPool;
				_tmp18_ = entitas_cache_new (4);
				_g_object_unref0 (_tmp16_[_tmp17_]);
				_tmp16_[_tmp17_] = _tmp18_;
				_tmp19_ = _tmp16_[_tmp17_];
				{
					gint k = 0;
					k = 0;
					{
						gboolean _tmp20_ = FALSE;
						_tmp20_ = TRUE;
						while (TRUE) {
							gint _tmp22_ = 0;
							gint _tmp23_ = 0;
							entitasCache** _tmp24_ = NULL;
							gint _tmp24__length1 = 0;
							gint _tmp25_ = 0;
							entitasCache* _tmp26_ = NULL;
							entitasBuffer* _tmp27_ = NULL;
							gint _tmp27__length1 = 0;
							gint _tmp28_ = 0;
							entitasBuffer _tmp29_ = {0};
							entitasFactory _tmp30_ = NULL;
							void* _tmp30__target = NULL;
							entitasEntity* _tmp31_ = NULL;
							if (!_tmp20_) {
								gint _tmp21_ = 0;
								_tmp21_ = k;
								k = _tmp21_ + 1;
							}
							_tmp20_ = FALSE;
							_tmp22_ = k;
							_tmp23_ = iSize;
							if (!(_tmp22_ < _tmp23_)) {
								break;
							}
							_tmp24_ = self->cache;
							_tmp24__length1 = self->cache_length1;
							_tmp25_ = iPool;
							_tmp26_ = _tmp24_[_tmp25_];
							_tmp27_ = buffers;
							_tmp27__length1 = buffers_length1;
							_tmp28_ = i;
							_tmp29_ = _tmp27_[_tmp28_];
							_tmp30_ = _tmp29_.factory;
							_tmp30__target = _tmp29_.factory_target;
							_tmp31_ = _tmp30_ (_tmp30__target);
							entitas_cache_enque (_tmp26_, _tmp31_);
						}
					}
				}
			}
		}
	}
}


static gpointer _entitas_isystem_dup0 (gpointer self) {
	return self ? entitas_isystem_dup (self) : NULL;
}


void entitas_world_addSystem (entitasWorld* self, entitasISystem iface) {
	entitasISystem** _tmp0_ = NULL;
	gint _tmp0__length1 = 0;
	gint _tmp1_ = 0;
	entitasISystem _tmp2_ = {0};
	entitasISystem* _tmp3_ = NULL;
	entitasISystem* _tmp4_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->systems;
	_tmp0__length1 = self->systems_length1;
	_tmp1_ = self->count;
	self->count = _tmp1_ + 1;
	_tmp2_ = iface;
	_tmp3_ = _entitas_isystem_dup0 (&_tmp2_);
	_entitas_isystem_free0 (_tmp0_[_tmp1_]);
	_tmp0_[_tmp1_] = _tmp3_;
	_tmp4_ = _tmp0_[_tmp1_];
}


void entitas_world_initialize (entitasWorld* self) {
	g_return_if_fail (self != NULL);
	{
		gint i = 0;
		i = 0;
		{
			gboolean _tmp0_ = FALSE;
			_tmp0_ = TRUE;
			while (TRUE) {
				gint _tmp2_ = 0;
				gint _tmp3_ = 0;
				entitasISystem** _tmp4_ = NULL;
				gint _tmp4__length1 = 0;
				gint _tmp5_ = 0;
				entitasISystem* _tmp6_ = NULL;
				entitasSystemInitialize _tmp7_ = NULL;
				void* _tmp7__target = NULL;
				if (!_tmp0_) {
					gint _tmp1_ = 0;
					_tmp1_ = i;
					i = _tmp1_ + 1;
				}
				_tmp0_ = FALSE;
				_tmp2_ = i;
				_tmp3_ = self->count;
				if (!(_tmp2_ < _tmp3_)) {
					break;
				}
				_tmp4_ = self->systems;
				_tmp4__length1 = self->systems_length1;
				_tmp5_ = i;
				_tmp6_ = _tmp4_[_tmp5_];
				_tmp7_ = (*_tmp6_).initialize;
				_tmp7__target = (*_tmp6_).initialize_target;
				_tmp7_ (_tmp7__target);
			}
		}
	}
}


void entitas_world_execute (entitasWorld* self, gdouble delta) {
	g_return_if_fail (self != NULL);
	{
		gint i = 0;
		i = 0;
		{
			gboolean _tmp0_ = FALSE;
			_tmp0_ = TRUE;
			while (TRUE) {
				gint _tmp2_ = 0;
				gint _tmp3_ = 0;
				entitasISystem** _tmp4_ = NULL;
				gint _tmp4__length1 = 0;
				gint _tmp5_ = 0;
				entitasISystem* _tmp6_ = NULL;
				entitasSystemExecute _tmp7_ = NULL;
				void* _tmp7__target = NULL;
				gdouble _tmp8_ = 0.0;
				if (!_tmp0_) {
					gint _tmp1_ = 0;
					_tmp1_ = i;
					i = _tmp1_ + 1;
				}
				_tmp0_ = FALSE;
				_tmp2_ = i;
				_tmp3_ = self->count;
				if (!(_tmp2_ < _tmp3_)) {
					break;
				}
				_tmp4_ = self->systems;
				_tmp4__length1 = self->systems_length1;
				_tmp5_ = i;
				_tmp6_ = _tmp4_[_tmp5_];
				_tmp7_ = (*_tmp6_).execute;
				_tmp7__target = (*_tmp6_).execute_target;
				_tmp8_ = delta;
				_tmp7_ (_tmp8_, _tmp7__target);
			}
		}
	}
}


void entitas_world_setEntityRemovedListener (entitasWorld* self, entitasEntityRemovedListener removed, void* removed_target) {
	entitasEntityRemovedListener _tmp0_ = NULL;
	void* _tmp0__target = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = removed;
	_tmp0__target = removed_target;
	(self->entityRemoved_target_destroy_notify == NULL) ? NULL : (self->entityRemoved_target_destroy_notify (self->entityRemoved_target), NULL);
	self->entityRemoved = NULL;
	self->entityRemoved_target = NULL;
	self->entityRemoved_target_destroy_notify = NULL;
	self->entityRemoved = _tmp0_;
	self->entityRemoved_target = _tmp0__target;
	self->entityRemoved_target_destroy_notify = NULL;
}


void entitas_world_componentAddedOrRemoved (entitasWorld* self, entitasEntity* entity, entitasComponents component) {
	GList* _tmp0_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->groups;
	{
		GList* group_collection = NULL;
		GList* group_it = NULL;
		group_collection = _tmp0_;
		for (group_it = group_collection; group_it != NULL; group_it = group_it->next) {
			entitasGroup* _tmp1_ = NULL;
			entitasGroup* group = NULL;
			_tmp1_ = _g_object_ref0 ((entitasGroup*) group_it->data);
			group = _tmp1_;
			{
				entitasGroup* _tmp2_ = NULL;
				entitasEntity* _tmp3_ = NULL;
				entitasComponents _tmp4_ = 0;
				_tmp2_ = group;
				_tmp3_ = entity;
				_tmp4_ = component;
				entitas_group_handleEntity (_tmp2_, _tmp3_, _tmp4_);
				_g_object_unref0 (group);
			}
		}
	}
}


/**
* send antity back to it's pool
*/
void entitas_world_deleteEntity (entitasWorld* self, entitasEntity* entity) {
	entitasCache** _tmp0_ = NULL;
	gint _tmp0__length1 = 0;
	entitasEntity* _tmp1_ = NULL;
	gint _tmp2_ = 0;
	entitasCache* _tmp3_ = NULL;
	entitasEntity* _tmp4_ = NULL;
	entitasEntityRemovedListener _tmp5_ = NULL;
	void* _tmp5__target = NULL;
	entitasEntity* _tmp6_ = NULL;
	g_return_if_fail (self != NULL);
	entitas_entity_setActive (entity, FALSE);
	_tmp0_ = self->cache;
	_tmp0__length1 = self->cache_length1;
	_tmp1_ = entity;
	_tmp2_ = (*_tmp1_).pool;
	_tmp3_ = _tmp0_[_tmp2_];
	_tmp4_ = entity;
	entitas_cache_enque (_tmp3_, _tmp4_);
	_tmp5_ = self->entityRemoved;
	_tmp5__target = self->entityRemoved_target;
	_tmp6_ = entity;
	_tmp5_ (_tmp6_, _tmp5__target);
}


/**
* create an entity from the pool
*/
entitasEntity* entitas_world_createEntity (entitasWorld* self, const gchar* name, gint pool, gboolean active) {
	entitasEntity* result = NULL;
	gint id = 0;
	gint _tmp0_ = 0;
	entitasEntity* _tmp1_ = NULL;
	gint _tmp1__length1 = 0;
	entitasEntity* _tmp2_ = NULL;
	const gchar* _tmp3_ = NULL;
	entitasEntity* _tmp4_ = NULL;
	gint _tmp5_ = 0;
	entitasEntity* _tmp6_ = NULL;
	gboolean _tmp7_ = FALSE;
	entitasEntity* _tmp8_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (name != NULL, NULL);
	_tmp0_ = self->id;
	self->id = _tmp0_ + 1;
	id = _tmp0_;
	_tmp1_ = self->pool;
	_tmp1__length1 = self->pool_length1;
	_tmp2_ = entitas_entity_setId (&_tmp1_[id], id);
	_tmp3_ = name;
	_tmp4_ = entitas_entity_setName (_tmp2_, _tmp3_);
	_tmp5_ = pool;
	_tmp6_ = entitas_entity_setPool (_tmp4_, _tmp5_);
	_tmp7_ = active;
	_tmp8_ = entitas_entity_setActive (_tmp6_, _tmp7_);
	result = _tmp8_;
	return result;
}


entitasGroup* entitas_world_getGroup (entitasWorld* self, entitasMatcher* matcher) {
	entitasGroup* result = NULL;
	GList* _tmp0_ = NULL;
	guint _tmp1_ = 0U;
	entitasMatcher* _tmp2_ = NULL;
	gint _tmp3_ = 0;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (matcher != NULL, NULL);
	_tmp0_ = self->groups;
	_tmp1_ = g_list_length (_tmp0_);
	_tmp2_ = matcher;
	_tmp3_ = _tmp2_->id;
	if (_tmp1_ > ((guint) _tmp3_)) {
		GList* _tmp4_ = NULL;
		entitasMatcher* _tmp5_ = NULL;
		gint _tmp6_ = 0;
		gconstpointer _tmp7_ = NULL;
		entitasGroup* _tmp8_ = NULL;
		_tmp4_ = self->groups;
		_tmp5_ = matcher;
		_tmp6_ = _tmp5_->id;
		_tmp7_ = g_list_nth_data (_tmp4_, (guint) _tmp6_);
		_tmp8_ = _g_object_ref0 ((entitasGroup*) _tmp7_);
		result = _tmp8_;
		return result;
	} else {
		entitasMatcher* _tmp9_ = NULL;
		entitasGroup* _tmp10_ = NULL;
		GList* _tmp19_ = NULL;
		gconstpointer _tmp20_ = NULL;
		entitasGroup* _tmp21_ = NULL;
		_tmp9_ = matcher;
		_tmp10_ = entitas_group_new (_tmp9_);
		self->groups = g_list_prepend (self->groups, _tmp10_);
		{
			gint i = 0;
			i = 0;
			{
				gboolean _tmp11_ = FALSE;
				_tmp11_ = TRUE;
				while (TRUE) {
					gint _tmp13_ = 0;
					gint _tmp14_ = 0;
					GList* _tmp15_ = NULL;
					gconstpointer _tmp16_ = NULL;
					entitasEntity* _tmp17_ = NULL;
					gint _tmp17__length1 = 0;
					gint _tmp18_ = 0;
					if (!_tmp11_) {
						gint _tmp12_ = 0;
						_tmp12_ = i;
						i = _tmp12_ + 1;
					}
					_tmp11_ = FALSE;
					_tmp13_ = i;
					_tmp14_ = self->id;
					if (!(_tmp13_ < (_tmp14_ - 1))) {
						break;
					}
					_tmp15_ = self->groups;
					_tmp16_ = g_list_nth_data (_tmp15_, (guint) 0);
					_tmp17_ = self->pool;
					_tmp17__length1 = self->pool_length1;
					_tmp18_ = i;
					entitas_group_handleEntitySilently ((entitasGroup*) _tmp16_, &_tmp17_[_tmp18_]);
				}
			}
		}
		_tmp19_ = self->groups;
		_tmp20_ = g_list_nth_data (_tmp19_, (guint) 0);
		_tmp21_ = _g_object_ref0 ((entitasGroup*) _tmp20_);
		result = _tmp21_;
		return result;
	}
}


static void entitas_world_class_init (entitasWorldClass * klass) {
	entitas_world_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->finalize = entitas_world_finalize;
}


static void entitas_world_instance_init (entitasWorld * self) {
	entitasISystem** _tmp0_ = NULL;
	self->id = 0;
	_tmp0_ = g_new0 (entitasISystem*, 100);
	self->systems = _tmp0_;
	self->systems_length1 = 100;
	self->count = 0;
}


static void entitas_world_finalize (GObject* obj) {
	entitasWorld * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, ENTITAS_TYPE_WORLD, entitasWorld);
	__g_list_free__g_object_unref0_0 (self->groups);
	self->pool = (_vala_entitasEntity_array_free (self->pool, self->pool_length1), NULL);
	self->cache = (_vala_array_free (self->cache, self->cache_length1, (GDestroyNotify) g_object_unref), NULL);
	self->systems = (_vala_array_free (self->systems, self->systems_length1, (GDestroyNotify) entitas_isystem_free), NULL);
	(self->entityRemoved_target_destroy_notify == NULL) ? NULL : (self->entityRemoved_target_destroy_notify (self->entityRemoved_target), NULL);
	self->entityRemoved = NULL;
	self->entityRemoved_target = NULL;
	self->entityRemoved_target_destroy_notify = NULL;
	G_OBJECT_CLASS (entitas_world_parent_class)->finalize (obj);
}


GType entitas_world_get_type (void) {
	static volatile gsize entitas_world_type_id__volatile = 0;
	if (g_once_init_enter (&entitas_world_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (entitasWorldClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) entitas_world_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (entitasWorld), 0, (GInstanceInitFunc) entitas_world_instance_init, NULL };
		GType entitas_world_type_id;
		entitas_world_type_id = g_type_register_static (G_TYPE_OBJECT, "entitasWorld", &g_define_type_info, 0);
		g_once_init_leave (&entitas_world_type_id__volatile, entitas_world_type_id);
	}
	return entitas_world_type_id__volatile;
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}



