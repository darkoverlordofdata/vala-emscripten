/* Expire.c generated by valac 0.34.7, the Vala compiler
 * generated from Expire.gs, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <float.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>

typedef struct _systemsExpire systemsExpire;
typedef struct _Game Game;
typedef struct _entitasWorld entitasWorld;
typedef entitasWorld Factory;
typedef struct _entitasGroup entitasGroup;
void game_release (Game* self);
void game_free (Game* self);
Game* game_addRef (Game* self);
#define _game_release0(var) ((var == NULL) ? NULL : (var = (game_release (var), NULL)))
void entitas_world_release (entitasWorld* self);
void entitas_world_free (entitasWorld* self);
entitasWorld* entitas_world_addRef (entitasWorld* self);
#define _entitas_world_release0(var) ((var == NULL) ? NULL : (var = (entitas_world_release (var), NULL)))
void entitas_group_release (entitasGroup* self);
void entitas_group_free (entitasGroup* self);
entitasGroup* entitas_group_addRef (entitasGroup* self);
#define _entitas_group_release0(var) ((var == NULL) ? NULL : (var = (entitas_group_release (var), NULL)))
typedef struct _entitasMatcher entitasMatcher;

#define ENTITAS_TYPE_COMPONENTS (entitas_components_get_type ())
void entitas_matcher_release (entitasMatcher* self);
void entitas_matcher_free (entitasMatcher* self);
entitasMatcher* entitas_matcher_addRef (entitasMatcher* self);
#define _entitas_matcher_release0(var) ((var == NULL) ? NULL : (var = (entitas_matcher_release (var), NULL)))

#define ENTITAS_TYPE_ENTITY (entitas_entity_get_type ())

#define ENTITAS_TYPE_BACKGROUND (entitas_background_get_type ())
typedef struct _entitasBackground entitasBackground;

#define ENTITAS_TYPE_BOUNDS (entitas_bounds_get_type ())
typedef struct _entitasBounds entitasBounds;

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

struct _systemsExpire {
	gint refCount;
	Game* game;
	Factory* factory;
	entitasGroup* expiring;
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

struct _entitasBackground {
	gboolean active;
};

struct _entitasBounds {
	gint x;
	gint y;
	gint w;
	gint h;
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
	SDL_Surface* surface;
};

struct _entitasText {
	gchar* text;
	SDL_Surface* surface;
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
	entitasBounds* bounds;
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

struct _entitasGroup {
	gint refCount;
	entitasMatcher* matcher;
	GList* entities;
};



void systems_expire_free (systemsExpire* self);
void game_free (Game* self);
void entitas_world_free (entitasWorld* self);
void entitas_group_free (entitasGroup* self);
static void systems_expire_instance_init (systemsExpire * self);
systemsExpire* systems_expire_addRef (systemsExpire* self);
void systems_expire_release (systemsExpire* self);
void systems_expire_free (systemsExpire* self);
systemsExpire* systems_expire_new (Game* game, Factory* factory);
void systems_expire_initialize (systemsExpire* self);
void entitas_matcher_free (entitasMatcher* self);
entitasGroup* entitas_world_getGroup (entitasWorld* self, entitasMatcher* matcher);
entitasMatcher* entitas_matcher_AllOf (gint* args, int args_length1);
GType entitas_components_get_type (void) G_GNUC_CONST;
void systems_expire_execute (systemsExpire* self, gdouble delta);
GType entitas_entity_get_type (void) G_GNUC_CONST;
GType entitas_background_get_type (void) G_GNUC_CONST;
entitasBackground* entitas_background_dup (const entitasBackground* self);
void entitas_background_free (entitasBackground* self);
GType entitas_bounds_get_type (void) G_GNUC_CONST;
entitasBounds* entitas_bounds_dup (const entitasBounds* self);
void entitas_bounds_free (entitasBounds* self);
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
entitasSprite* entitas_sprite_dup (const entitasSprite* self);
void entitas_sprite_free (entitasSprite* self);
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
gboolean entitas_entity_isActive (entitasEntity *self);
void entitas_world_deleteEntity (entitasWorld* self, entitasEntity* entity);


systemsExpire* systems_expire_addRef (systemsExpire* self) {
	systemsExpire* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_atomic_int_add ((volatile gint *) (&self->refCount), 1);
	result = self;
	return result;
}


void systems_expire_release (systemsExpire* self) {
	gboolean _tmp0_ = FALSE;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_atomic_int_dec_and_test ((volatile gint *) (&self->refCount));
	if (_tmp0_) {
		systems_expire_free (self);
	}
}


static gpointer _game_addRef0 (gpointer self) {
	return self ? game_addRef (self) : NULL;
}


static gpointer _entitas_world_addRef0 (gpointer self) {
	return self ? entitas_world_addRef (self) : NULL;
}


systemsExpire* systems_expire_new (Game* game, Factory* factory) {
	systemsExpire* self;
	Game* _tmp0_ = NULL;
	Game* _tmp1_ = NULL;
	Factory* _tmp2_ = NULL;
	Factory* _tmp3_ = NULL;
	g_return_val_if_fail (game != NULL, NULL);
	g_return_val_if_fail (factory != NULL, NULL);
	self = g_slice_new0 (systemsExpire);
	systems_expire_instance_init (self);
	_tmp0_ = game;
	_tmp1_ = _game_addRef0 (_tmp0_);
	_game_release0 (self->game);
	self->game = _tmp1_;
	_tmp2_ = factory;
	_tmp3_ = _entitas_world_addRef0 (_tmp2_);
	_entitas_world_release0 (self->factory);
	self->factory = _tmp3_;
	return self;
}


void systems_expire_initialize (systemsExpire* self) {
	Factory* _tmp0_ = NULL;
	gint* _tmp1_ = NULL;
	gint* _tmp2_ = NULL;
	gint _tmp2__length1 = 0;
	entitasMatcher* _tmp3_ = NULL;
	entitasMatcher* _tmp4_ = NULL;
	entitasGroup* _tmp5_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->factory;
	_tmp1_ = g_new0 (gint, 1);
	_tmp1_[0] = (gint) ENTITAS_COMPONENTS_ExpiresComponent;
	_tmp2_ = _tmp1_;
	_tmp2__length1 = 1;
	_tmp3_ = entitas_matcher_AllOf (_tmp2_, 1);
	_tmp4_ = _tmp3_;
	_tmp5_ = entitas_world_getGroup ((entitasWorld*) _tmp0_, _tmp4_);
	_entitas_group_release0 (self->expiring);
	self->expiring = _tmp5_;
	_entitas_matcher_release0 (_tmp4_);
	_tmp2_ = (g_free (_tmp2_), NULL);
}


/**
 * Remove exired entities
 */
void systems_expire_execute (systemsExpire* self, gdouble delta) {
	entitasGroup* _tmp0_ = NULL;
	GList* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->expiring;
	_tmp1_ = _tmp0_->entities;
	{
		GList* entity_collection = NULL;
		GList* entity_it = NULL;
		entity_collection = _tmp1_;
		for (entity_it = entity_collection; entity_it != NULL; entity_it = entity_it->next) {
			entitasEntity* entity = NULL;
			entity = entity_it->data;
			{
				gboolean _tmp2_ = FALSE;
				_tmp2_ = entitas_entity_isActive (entity);
				if (_tmp2_) {
					gdouble exp = 0.0;
					entitasEntity* _tmp3_ = NULL;
					entitasExpires* _tmp4_ = NULL;
					gdouble _tmp5_ = 0.0;
					gdouble _tmp6_ = 0.0;
					entitasEntity* _tmp7_ = NULL;
					entitasExpires* _tmp8_ = NULL;
					gdouble _tmp9_ = 0.0;
					entitasEntity* _tmp10_ = NULL;
					entitasExpires* _tmp11_ = NULL;
					gdouble _tmp12_ = 0.0;
					_tmp3_ = entity;
					_tmp4_ = (*_tmp3_).expires;
					_tmp5_ = (*_tmp4_).value;
					_tmp6_ = delta;
					exp = _tmp5_ - _tmp6_;
					_tmp7_ = entity;
					_tmp8_ = (*_tmp7_).expires;
					_tmp9_ = exp;
					(*_tmp8_).value = _tmp9_;
					_tmp10_ = entity;
					_tmp11_ = (*_tmp10_).expires;
					_tmp12_ = (*_tmp11_).value;
					if (_tmp12_ < ((gdouble) 0)) {
						Factory* _tmp13_ = NULL;
						entitasEntity* _tmp14_ = NULL;
						_tmp13_ = self->factory;
						_tmp14_ = entity;
						entitas_world_deleteEntity ((entitasWorld*) _tmp13_, _tmp14_);
					}
				}
			}
		}
	}
}


static void systems_expire_instance_init (systemsExpire * self) {
	self->refCount = 1;
}


void systems_expire_free (systemsExpire* self) {
	_game_release0 (self->game);
	_entitas_world_release0 (self->factory);
	_entitas_group_release0 (self->expiring);
	g_slice_free (systemsExpire, self);
}


