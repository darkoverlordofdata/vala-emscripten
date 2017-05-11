/* CollisionSystem.c generated by valac 0.34.8, the Vala compiler
 * generated from CollisionSystem.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <float.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL_rect.h>


#define SYSTEMS_TYPE_COLLISION_SYSTEM (systems_collision_system_get_type ())
#define SYSTEMS_COLLISION_SYSTEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SYSTEMS_TYPE_COLLISION_SYSTEM, systemsCollisionSystem))
#define SYSTEMS_COLLISION_SYSTEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SYSTEMS_TYPE_COLLISION_SYSTEM, systemsCollisionSystemClass))
#define SYSTEMS_IS_COLLISION_SYSTEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SYSTEMS_TYPE_COLLISION_SYSTEM))
#define SYSTEMS_IS_COLLISION_SYSTEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SYSTEMS_TYPE_COLLISION_SYSTEM))
#define SYSTEMS_COLLISION_SYSTEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SYSTEMS_TYPE_COLLISION_SYSTEM, systemsCollisionSystemClass))

typedef struct _systemsCollisionSystem systemsCollisionSystem;
typedef struct _systemsCollisionSystemClass systemsCollisionSystemClass;
typedef struct _systemsCollisionSystemPrivate systemsCollisionSystemPrivate;

#define TYPE_GAME (game_get_type ())
#define GAME(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_GAME, Game))
#define GAME_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_GAME, GameClass))
#define IS_GAME(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_GAME))
#define IS_GAME_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_GAME))
#define GAME_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_GAME, GameClass))

typedef struct _Game Game;
typedef struct _GameClass GameClass;

#define ENTITAS_TYPE_WORLD (entitas_world_get_type ())
#define ENTITAS_WORLD(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), ENTITAS_TYPE_WORLD, entitasWorld))
#define ENTITAS_WORLD_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), ENTITAS_TYPE_WORLD, entitasWorldClass))
#define ENTITAS_IS_WORLD(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ENTITAS_TYPE_WORLD))
#define ENTITAS_IS_WORLD_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), ENTITAS_TYPE_WORLD))
#define ENTITAS_WORLD_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), ENTITAS_TYPE_WORLD, entitasWorldClass))

typedef struct _entitasWorld entitasWorld;
typedef struct _entitasWorldClass entitasWorldClass;

#define TYPE_FACTORY (factory_get_type ())
#define FACTORY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_FACTORY, Factory))
#define FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_FACTORY, FactoryClass))
#define IS_FACTORY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_FACTORY))
#define IS_FACTORY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_FACTORY))
#define FACTORY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_FACTORY, FactoryClass))

typedef struct _Factory Factory;
typedef struct _FactoryClass FactoryClass;

#define ENTITAS_TYPE_GROUP (entitas_group_get_type ())
#define ENTITAS_GROUP(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), ENTITAS_TYPE_GROUP, entitasGroup))
#define ENTITAS_GROUP_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), ENTITAS_TYPE_GROUP, entitasGroupClass))
#define ENTITAS_IS_GROUP(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ENTITAS_TYPE_GROUP))
#define ENTITAS_IS_GROUP_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), ENTITAS_TYPE_GROUP))
#define ENTITAS_GROUP_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), ENTITAS_TYPE_GROUP, entitasGroupClass))

typedef struct _entitasGroup entitasGroup;
typedef struct _entitasGroupClass entitasGroupClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define ENTITAS_TYPE_MATCHER (entitas_matcher_get_type ())
#define ENTITAS_MATCHER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), ENTITAS_TYPE_MATCHER, entitasMatcher))
#define ENTITAS_MATCHER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), ENTITAS_TYPE_MATCHER, entitasMatcherClass))
#define ENTITAS_IS_MATCHER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ENTITAS_TYPE_MATCHER))
#define ENTITAS_IS_MATCHER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), ENTITAS_TYPE_MATCHER))
#define ENTITAS_MATCHER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), ENTITAS_TYPE_MATCHER, entitasMatcherClass))

typedef struct _entitasMatcher entitasMatcher;
typedef struct _entitasMatcherClass entitasMatcherClass;

#define ENTITAS_TYPE_COMPONENTS (entitas_components_get_type ())
typedef struct _entitasGroupPrivate entitasGroupPrivate;

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

#define ENTITAS_TYPE_ISYSTEM (entitas_isystem_get_type ())
typedef struct _entitasISystem entitasISystem;

struct _systemsCollisionSystem {
	GObject parent_instance;
	systemsCollisionSystemPrivate * priv;
	Game* game;
	Factory* world;
	entitasGroup* bullets;
	entitasGroup* enemies;
};

struct _systemsCollisionSystemClass {
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

struct _entitasGroup {
	GObject parent_instance;
	entitasGroupPrivate * priv;
	entitasMatcher* matcher;
	GList* entities;
};

struct _entitasGroupClass {
	GObjectClass parent_class;
};

typedef void (*entitasSystemInitialize) (void* user_data);
typedef void (*entitasSystemExecute) (gdouble delta, void* user_data);
struct _entitasISystem {
	entitasSystemInitialize initialize;
	gpointer initialize_target;
	entitasSystemExecute execute;
	gpointer execute_target;
};


static gpointer systems_collision_system_parent_class = NULL;

GType systems_collision_system_get_type (void) G_GNUC_CONST;
GType game_get_type (void) G_GNUC_CONST;
GType entitas_world_get_type (void) G_GNUC_CONST;
GType factory_get_type (void) G_GNUC_CONST;
GType entitas_group_get_type (void) G_GNUC_CONST;
enum  {
	SYSTEMS_COLLISION_SYSTEM_DUMMY_PROPERTY
};
systemsCollisionSystem* systems_collision_system_new (Game* game, Factory* world);
systemsCollisionSystem* systems_collision_system_construct (GType object_type, Game* game, Factory* world);
void systems_collision_system_initialize (systemsCollisionSystem* self);
GType entitas_matcher_get_type (void) G_GNUC_CONST;
entitasGroup* entitas_world_getGroup (entitasWorld* self, entitasMatcher* matcher);
entitasMatcher* entitas_matcher_AllOf (gint* args, int args_length1);
GType entitas_components_get_type (void) G_GNUC_CONST;
entitasMatcher* entitas_matcher_AnyOf (gint* args, int args_length1);
void systems_collision_system_execute (systemsCollisionSystem* self, gdouble delta);
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
gboolean entitas_entity_isActive (entitasEntity *self);
entitasEntity* factory_bang (Factory* self, gint x, gint y);
void entitas_world_deleteEntity (entitasWorld* self, entitasEntity* entity);
entitasEntity* factory_particle (Factory* self, gint x, gint y);
entitasEntity* factory_explosion (Factory* self, gint x, gint y);
GType entitas_isystem_get_type (void) G_GNUC_CONST;
entitasISystem* entitas_isystem_dup (const entitasISystem* self);
void entitas_isystem_free (entitasISystem* self);
entitasISystem systems_collision_system_get__ISystem (systemsCollisionSystem* self);
static void _systems_collision_system_initialize_entitas_system_initialize (gpointer self);
static void _systems_collision_system_execute_entitas_system_execute (gdouble delta, gpointer self);
static void systems_collision_system_finalize (GObject* obj);
static void _vala_systems_collision_system_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


systemsCollisionSystem* systems_collision_system_construct (GType object_type, Game* game, Factory* world) {
	systemsCollisionSystem * self = NULL;
	Game* _tmp0_ = NULL;
	Game* _tmp1_ = NULL;
	Factory* _tmp2_ = NULL;
	Factory* _tmp3_ = NULL;
	g_return_val_if_fail (game != NULL, NULL);
	g_return_val_if_fail (world != NULL, NULL);
	self = (systemsCollisionSystem*) g_object_new (object_type, NULL);
	_tmp0_ = game;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->game);
	self->game = _tmp1_;
	_tmp2_ = world;
	_tmp3_ = _g_object_ref0 (_tmp2_);
	_g_object_unref0 (self->world);
	self->world = _tmp3_;
	return self;
}


systemsCollisionSystem* systems_collision_system_new (Game* game, Factory* world) {
	return systems_collision_system_construct (SYSTEMS_TYPE_COLLISION_SYSTEM, game, world);
}


void systems_collision_system_initialize (systemsCollisionSystem* self) {
	Factory* _tmp0_ = NULL;
	gint* _tmp1_ = NULL;
	gint* _tmp2_ = NULL;
	gint _tmp2__length1 = 0;
	entitasMatcher* _tmp3_ = NULL;
	entitasMatcher* _tmp4_ = NULL;
	entitasGroup* _tmp5_ = NULL;
	Factory* _tmp6_ = NULL;
	gint* _tmp7_ = NULL;
	gint* _tmp8_ = NULL;
	gint _tmp8__length1 = 0;
	entitasMatcher* _tmp9_ = NULL;
	entitasMatcher* _tmp10_ = NULL;
	entitasGroup* _tmp11_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->world;
	_tmp1_ = g_new0 (gint, 1);
	_tmp1_[0] = (gint) ENTITAS_COMPONENTS_BulletComponent;
	_tmp2_ = _tmp1_;
	_tmp2__length1 = 1;
	_tmp3_ = entitas_matcher_AllOf (_tmp2_, 1);
	_tmp4_ = _tmp3_;
	_tmp5_ = entitas_world_getGroup ((entitasWorld*) _tmp0_, _tmp4_);
	_g_object_unref0 (self->bullets);
	self->bullets = _tmp5_;
	_g_object_unref0 (_tmp4_);
	_tmp2_ = (g_free (_tmp2_), NULL);
	_tmp6_ = self->world;
	_tmp7_ = g_new0 (gint, 3);
	_tmp7_[0] = (gint) ENTITAS_COMPONENTS_Enemy1Component;
	_tmp7_[1] = (gint) ENTITAS_COMPONENTS_Enemy2Component;
	_tmp7_[2] = (gint) ENTITAS_COMPONENTS_Enemy3Component;
	_tmp8_ = _tmp7_;
	_tmp8__length1 = 3;
	_tmp9_ = entitas_matcher_AnyOf (_tmp8_, 3);
	_tmp10_ = _tmp9_;
	_tmp11_ = entitas_world_getGroup ((entitasWorld*) _tmp6_, _tmp10_);
	_g_object_unref0 (self->enemies);
	self->enemies = _tmp11_;
	_g_object_unref0 (_tmp10_);
	_tmp8_ = (g_free (_tmp8_), NULL);
}


/**
* physics system
* model movement
*/
void systems_collision_system_execute (systemsCollisionSystem* self, gdouble delta) {
	entitasGroup* _tmp0_ = NULL;
	GList* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->enemies;
	_tmp1_ = _tmp0_->entities;
	{
		GList* enemy_collection = NULL;
		GList* enemy_it = NULL;
		enemy_collection = _tmp1_;
		for (enemy_it = enemy_collection; enemy_it != NULL; enemy_it = enemy_it->next) {
			entitasEntity* enemy = NULL;
			enemy = enemy_it->data;
			{
				gboolean _tmp2_ = FALSE;
				_tmp2_ = entitas_entity_isActive (enemy);
				if (_tmp2_) {
					entitasGroup* _tmp3_ = NULL;
					GList* _tmp4_ = NULL;
					_tmp3_ = self->bullets;
					_tmp4_ = _tmp3_->entities;
					{
						GList* bullet_collection = NULL;
						GList* bullet_it = NULL;
						bullet_collection = _tmp4_;
						for (bullet_it = bullet_collection; bullet_it != NULL; bullet_it = bullet_it->next) {
							entitasEntity* bullet = NULL;
							bullet = bullet_it->data;
							{
								gboolean _tmp5_ = FALSE;
								_tmp5_ = entitas_entity_isActive (bullet);
								if (_tmp5_) {
									entitasEntity* _tmp6_ = NULL;
									SDL_Rect* _tmp7_ = NULL;
									entitasEntity* _tmp8_ = NULL;
									SDL_Rect* _tmp9_ = NULL;
									SDL_Rect _tmp10_ = {0};
									gboolean _tmp11_ = FALSE;
									_tmp6_ = bullet;
									_tmp7_ = (*_tmp6_).bounds;
									_tmp8_ = enemy;
									_tmp9_ = (*_tmp8_).bounds;
									_tmp10_ = *_tmp9_;
									_tmp11_ = SDL_HasIntersection (_tmp7_, &_tmp10_);
									if (_tmp11_) {
										gint x = 0;
										entitasEntity* _tmp12_ = NULL;
										entitasPosition* _tmp13_ = NULL;
										gdouble _tmp14_ = 0.0;
										gint y = 0;
										entitasEntity* _tmp15_ = NULL;
										entitasPosition* _tmp16_ = NULL;
										gdouble _tmp17_ = 0.0;
										Factory* _tmp18_ = NULL;
										gint _tmp19_ = 0;
										gint _tmp20_ = 0;
										Factory* _tmp21_ = NULL;
										entitasEntity* _tmp22_ = NULL;
										entitasEntity* _tmp29_ = NULL;
										entitasHealth* _tmp30_ = NULL;
										_tmp12_ = bullet;
										_tmp13_ = (*_tmp12_).position;
										_tmp14_ = (*_tmp13_).x;
										x = (gint) ((gdouble) _tmp14_);
										_tmp15_ = bullet;
										_tmp16_ = (*_tmp15_).position;
										_tmp17_ = (*_tmp16_).y;
										y = (gint) ((gdouble) _tmp17_);
										_tmp18_ = self->world;
										_tmp19_ = x;
										_tmp20_ = y;
										factory_bang (_tmp18_, _tmp19_, _tmp20_);
										_tmp21_ = self->world;
										_tmp22_ = bullet;
										entitas_world_deleteEntity ((entitasWorld*) _tmp21_, _tmp22_);
										{
											gint i = 0;
											i = 0;
											{
												gboolean _tmp23_ = FALSE;
												_tmp23_ = TRUE;
												while (TRUE) {
													gint _tmp25_ = 0;
													Factory* _tmp26_ = NULL;
													gint _tmp27_ = 0;
													gint _tmp28_ = 0;
													if (!_tmp23_) {
														gint _tmp24_ = 0;
														_tmp24_ = i;
														i = _tmp24_ + 1;
													}
													_tmp23_ = FALSE;
													_tmp25_ = i;
													if (!(_tmp25_ < 3)) {
														break;
													}
													_tmp26_ = self->world;
													_tmp27_ = x;
													_tmp28_ = y;
													factory_particle (_tmp26_, _tmp27_, _tmp28_);
												}
											}
										}
										_tmp29_ = enemy;
										_tmp30_ = (*_tmp29_).health;
										if (_tmp30_ != NULL) {
											gdouble current = 0.0;
											entitasEntity* _tmp31_ = NULL;
											entitasHealth* _tmp32_ = NULL;
											gdouble _tmp33_ = 0.0;
											gdouble _tmp34_ = 0.0;
											_tmp31_ = enemy;
											_tmp32_ = (*_tmp31_).health;
											_tmp33_ = (*_tmp32_).current;
											current = _tmp33_ - 2;
											_tmp34_ = current;
											if (_tmp34_ < ((gdouble) 0)) {
												Factory* _tmp35_ = NULL;
												gint _tmp36_ = 0;
												gint _tmp37_ = 0;
												Factory* _tmp38_ = NULL;
												entitasEntity* _tmp39_ = NULL;
												_tmp35_ = self->world;
												_tmp36_ = x;
												_tmp37_ = y;
												factory_explosion (_tmp35_, _tmp36_, _tmp37_);
												_tmp38_ = self->world;
												_tmp39_ = enemy;
												entitas_world_deleteEntity ((entitasWorld*) _tmp38_, _tmp39_);
											} else {
												entitasEntity* _tmp40_ = NULL;
												entitasHealth* _tmp41_ = NULL;
												gdouble _tmp42_ = 0.0;
												_tmp40_ = enemy;
												_tmp41_ = (*_tmp40_).health;
												_tmp42_ = current;
												(*_tmp41_).current = _tmp42_;
											}
										}
										return;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


static void _systems_collision_system_initialize_entitas_system_initialize (gpointer self) {
	systems_collision_system_initialize ((systemsCollisionSystem*) self);
}


static void _systems_collision_system_execute_entitas_system_execute (gdouble delta, gpointer self) {
	systems_collision_system_execute ((systemsCollisionSystem*) self, delta);
}


entitasISystem systems_collision_system_get__ISystem (systemsCollisionSystem* self) {
	entitasISystem result;
	entitasISystem _tmp0_ = {0};
	_tmp0_.initialize = _systems_collision_system_initialize_entitas_system_initialize;
	_tmp0_.initialize_target = self;
	_tmp0_.execute = _systems_collision_system_execute_entitas_system_execute;
	_tmp0_.execute_target = self;
	result = _tmp0_;
	return result;
}


static void systems_collision_system_class_init (systemsCollisionSystemClass * klass) {
	systems_collision_system_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->get_property = _vala_systems_collision_system_get_property;
	G_OBJECT_CLASS (klass)->finalize = systems_collision_system_finalize;
}


static void systems_collision_system_instance_init (systemsCollisionSystem * self) {
}


static void systems_collision_system_finalize (GObject* obj) {
	systemsCollisionSystem * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, SYSTEMS_TYPE_COLLISION_SYSTEM, systemsCollisionSystem);
	_g_object_unref0 (self->game);
	_g_object_unref0 (self->world);
	_g_object_unref0 (self->bullets);
	_g_object_unref0 (self->enemies);
	G_OBJECT_CLASS (systems_collision_system_parent_class)->finalize (obj);
}


/**
* game systems
*/
GType systems_collision_system_get_type (void) {
	static volatile gsize systems_collision_system_type_id__volatile = 0;
	if (g_once_init_enter (&systems_collision_system_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (systemsCollisionSystemClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) systems_collision_system_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (systemsCollisionSystem), 0, (GInstanceInitFunc) systems_collision_system_instance_init, NULL };
		GType systems_collision_system_type_id;
		systems_collision_system_type_id = g_type_register_static (G_TYPE_OBJECT, "systemsCollisionSystem", &g_define_type_info, 0);
		g_once_init_leave (&systems_collision_system_type_id__volatile, systems_collision_system_type_id);
	}
	return systems_collision_system_type_id__volatile;
}


static void _vala_systems_collision_system_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	systemsCollisionSystem * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, SYSTEMS_TYPE_COLLISION_SYSTEM, systemsCollisionSystem);
	switch (property_id) {
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



