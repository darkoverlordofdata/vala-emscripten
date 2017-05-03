/* Spawn.c generated by valac 0.34.7, the Vala compiler
 * generated from Spawn.gs, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <float.h>
#include <math.h>
#include <emscripten.h>
#include <SDL.h>
#include <stdlib.h>
#include <string.h>

typedef struct _systemsSpawn systemsSpawn;
typedef struct _Game Game;
typedef struct _entitasWorld entitasWorld;
typedef entitasWorld Factory;
void game_release (Game* self);
void game_free (Game* self);
Game* game_addRef (Game* self);
#define _game_release0(var) ((var == NULL) ? NULL : (var = (game_release (var), NULL)))
void entitas_world_release (entitasWorld* self);
void entitas_world_free (entitasWorld* self);
entitasWorld* entitas_world_addRef (entitasWorld* self);
#define _entitas_world_release0(var) ((var == NULL) ? NULL : (var = (entitas_world_release (var), NULL)))
typedef struct _Systems Systems;

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

struct _systemsSpawn {
	gint refCount;
	Game* game;
	Factory* factory;
	gdouble enemyT1;
	gdouble enemyT2;
	gdouble enemyT3;
};

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

struct _Game {
	gint refCount;
	gint width;
	gint height;
	gdouble mark1;
	gdouble mark2;
	gdouble delta;
	gdouble mouseX;
	gdouble mouseY;
	gboolean mouseDown;
	gboolean running;
	guint8 keys[256];
	SDL_Event evt;
	SDL_Surface* surface;
	Factory* factory;
	Systems* systems;
	GList* sprites;
	gint k;
	gdouble t;
	gdouble t1;
	gdouble t2;
	gdouble t3;
	entitasEntity* player;
};



void systems_spawn_free (systemsSpawn* self);
void game_free (Game* self);
void entitas_world_free (entitasWorld* self);
static void systems_spawn_instance_init (systemsSpawn * self);
systemsSpawn* systems_spawn_addRef (systemsSpawn* self);
void systems_spawn_release (systemsSpawn* self);
void systems_spawn_free (systemsSpawn* self);
systemsSpawn* systems_spawn_new (Game* game, Factory* factory);
void systems_spawn_initialize (systemsSpawn* self);
void systems_spawn_execute (systemsSpawn* self, gdouble delta);
gdouble systems_spawn_spawnEnemy (systemsSpawn* self, gdouble delta, gdouble t, gint enemy);
void systems_free (Systems* self);
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
void factory_newEnemy1 (Factory* self, gint x, gint y);
void factory_newEnemy2 (Factory* self, gint x, gint y);
void factory_newEnemy3 (Factory* self, gint x, gint y);


systemsSpawn* systems_spawn_addRef (systemsSpawn* self) {
	systemsSpawn* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_atomic_int_add ((volatile gint *) (&self->refCount), 1);
	result = self;
	return result;
}


void systems_spawn_release (systemsSpawn* self) {
	gboolean _tmp0_ = FALSE;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_atomic_int_dec_and_test ((volatile gint *) (&self->refCount));
	if (_tmp0_) {
		systems_spawn_free (self);
	}
}


static gpointer _game_addRef0 (gpointer self) {
	return self ? game_addRef (self) : NULL;
}


static gpointer _entitas_world_addRef0 (gpointer self) {
	return self ? entitas_world_addRef (self) : NULL;
}


systemsSpawn* systems_spawn_new (Game* game, Factory* factory) {
	systemsSpawn* self;
	Game* _tmp0_ = NULL;
	Game* _tmp1_ = NULL;
	Factory* _tmp2_ = NULL;
	Factory* _tmp3_ = NULL;
	g_return_val_if_fail (game != NULL, NULL);
	g_return_val_if_fail (factory != NULL, NULL);
	self = g_slice_new0 (systemsSpawn);
	systems_spawn_instance_init (self);
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


void systems_spawn_initialize (systemsSpawn* self) {
	g_return_if_fail (self != NULL);
}


/**
 * Spawn enemy ships
 */
void systems_spawn_execute (systemsSpawn* self, gdouble delta) {
	gdouble _tmp0_ = 0.0;
	gdouble _tmp1_ = 0.0;
	gdouble _tmp2_ = 0.0;
	gdouble _tmp3_ = 0.0;
	gdouble _tmp4_ = 0.0;
	gdouble _tmp5_ = 0.0;
	gdouble _tmp6_ = 0.0;
	gdouble _tmp7_ = 0.0;
	gdouble _tmp8_ = 0.0;
	g_return_if_fail (self != NULL);
	_tmp0_ = delta;
	_tmp1_ = self->enemyT1;
	_tmp2_ = systems_spawn_spawnEnemy (self, _tmp0_, _tmp1_, 1);
	self->enemyT1 = _tmp2_;
	_tmp3_ = delta;
	_tmp4_ = self->enemyT2;
	_tmp5_ = systems_spawn_spawnEnemy (self, _tmp3_, _tmp4_, 2);
	self->enemyT2 = _tmp5_;
	_tmp6_ = delta;
	_tmp7_ = self->enemyT3;
	_tmp8_ = systems_spawn_spawnEnemy (self, _tmp6_, _tmp7_, 3);
	self->enemyT3 = _tmp8_;
}


gdouble systems_spawn_spawnEnemy (systemsSpawn* self, gdouble delta, gdouble t, gint enemy) {
	gdouble result = 0.0;
	gdouble d1 = 0.0;
	gdouble _tmp0_ = 0.0;
	gdouble _tmp1_ = 0.0;
	gdouble _tmp2_ = 0.0;
	g_return_val_if_fail (self != NULL, 0.0);
	_tmp0_ = t;
	_tmp1_ = delta;
	d1 = _tmp0_ - _tmp1_;
	_tmp2_ = d1;
	if (_tmp2_ < 0.0) {
		gint _tmp3_ = 0;
		_tmp3_ = enemy;
		switch (_tmp3_) {
			case 1:
			{
				{
					gint x = 0;
					gfloat _tmp4_ = 0.0F;
					Game* _tmp5_ = NULL;
					gint _tmp6_ = 0;
					Factory* _tmp7_ = NULL;
					gint _tmp8_ = 0;
					_tmp4_ = emscripten_random ();
					_tmp5_ = self->game;
					_tmp6_ = _tmp5_->width;
					x = ((gint) (_tmp4_ * (_tmp6_ - 70))) + 35;
					_tmp7_ = self->factory;
					_tmp8_ = x;
					factory_newEnemy1 (_tmp7_, _tmp8_, -35);
					result = 1.0;
					return result;
				}
				break;
			}
			case 2:
			{
				{
					gint x = 0;
					gfloat _tmp9_ = 0.0F;
					Game* _tmp10_ = NULL;
					gint _tmp11_ = 0;
					Factory* _tmp12_ = NULL;
					gint _tmp13_ = 0;
					_tmp9_ = emscripten_random ();
					_tmp10_ = self->game;
					_tmp11_ = _tmp10_->width;
					x = ((gint) (_tmp9_ * (_tmp11_ - 172))) + 85;
					_tmp12_ = self->factory;
					_tmp13_ = x;
					factory_newEnemy2 (_tmp12_, _tmp13_, -85);
					result = 4.0;
					return result;
				}
				break;
			}
			case 3:
			{
				{
					gint x = 0;
					gfloat _tmp14_ = 0.0F;
					Game* _tmp15_ = NULL;
					gint _tmp16_ = 0;
					Factory* _tmp17_ = NULL;
					gint _tmp18_ = 0;
					_tmp14_ = emscripten_random ();
					_tmp15_ = self->game;
					_tmp16_ = _tmp15_->width;
					x = ((gint) (_tmp14_ * (_tmp16_ - 320))) + 160;
					_tmp17_ = self->factory;
					_tmp18_ = x;
					factory_newEnemy3 (_tmp17_, _tmp18_, -160);
					result = 6.0;
					return result;
				}
				break;
			}
			default:
			{
				{
					result = 0.0;
					return result;
				}
				break;
			}
		}
	} else {
		result = d1;
		return result;
	}
}


static void systems_spawn_instance_init (systemsSpawn * self) {
	self->refCount = 1;
	self->enemyT1 = 1.0;
	self->enemyT2 = 4.0;
	self->enemyT3 = 6.0;
}


void systems_spawn_free (systemsSpawn* self) {
	_game_release0 (self->game);
	_entitas_world_release0 (self->factory);
	g_slice_free (systemsSpawn, self);
}



