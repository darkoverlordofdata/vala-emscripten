/* DisplaySystem.c generated by valac 0.34.8, the Vala compiler
 * generated from DisplaySystem.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL_rect.h>
#include <float.h>
#include <math.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_pixels.h>


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

#define SYSTEMS_TYPE_DISPLAY_SYSTEM (systems_display_system_get_type ())
#define SYSTEMS_DISPLAY_SYSTEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SYSTEMS_TYPE_DISPLAY_SYSTEM, systemsDisplaySystem))
#define SYSTEMS_DISPLAY_SYSTEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SYSTEMS_TYPE_DISPLAY_SYSTEM, systemsDisplaySystemClass))
#define SYSTEMS_IS_DISPLAY_SYSTEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SYSTEMS_TYPE_DISPLAY_SYSTEM))
#define SYSTEMS_IS_DISPLAY_SYSTEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SYSTEMS_TYPE_DISPLAY_SYSTEM))
#define SYSTEMS_DISPLAY_SYSTEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SYSTEMS_TYPE_DISPLAY_SYSTEM, systemsDisplaySystemClass))

typedef struct _systemsDisplaySystem systemsDisplaySystem;
typedef struct _systemsDisplaySystemClass systemsDisplaySystemClass;
typedef struct _systemsDisplaySystemPrivate systemsDisplaySystemPrivate;

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
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_list_free0(var) ((var == NULL) ? NULL : (var = (g_list_free (var), NULL)))
typedef struct _sdxgraphicsSpritePrivate sdxgraphicsSpritePrivate;

#define SDX_GRAPHICS_TYPE_SCALE (sdx_graphics_scale_get_type ())
typedef struct _sdxgraphicsScale sdxgraphicsScale;

#define ENTITAS_TYPE_ISYSTEM (entitas_isystem_get_type ())
typedef struct _entitasISystem entitasISystem;
#define _vala_assert(expr, msg) if G_LIKELY (expr) ; else g_assertion_message_expr (G_LOG_DOMAIN, __FILE__, __LINE__, G_STRFUNC, msg);
#define _vala_return_if_fail(expr, msg) if G_LIKELY (expr) ; else { g_return_if_fail_warning (G_LOG_DOMAIN, G_STRFUNC, msg); return; }
#define _vala_return_val_if_fail(expr, msg, val) if G_LIKELY (expr) ; else { g_return_if_fail_warning (G_LOG_DOMAIN, G_STRFUNC, msg); return val; }
#define _vala_warn_if_fail(expr, msg) if G_LIKELY (expr) ; else g_warn_message (G_LOG_DOMAIN, __FILE__, __LINE__, G_STRFUNC, msg);

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

struct _systemsDisplaySystem {
	GObject parent_instance;
	systemsDisplaySystemPrivate * priv;
	Game* game;
	Factory* world;
	GList* sprites;
};

struct _systemsDisplaySystemClass {
	GObjectClass parent_class;
};

struct _sdxgraphicsScale {
	gdouble x;
	gdouble y;
};

struct _sdxgraphicsSprite {
	GObject parent_instance;
	sdxgraphicsSpritePrivate * priv;
	SDL_Texture* texture;
	SDL_Surface* surface;
	gint width;
	gint height;
	gint x;
	gint y;
	sdxgraphicsScale scale;
	SDL_Color color;
	gboolean centered;
	gint layer;
	gint id;
	gchar* path;
	gboolean isText;
};

struct _sdxgraphicsSpriteClass {
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


extern systemsDisplaySystem* systems_display_system_instance;
static gpointer systems_display_system_parent_class = NULL;
systemsDisplaySystem* systems_display_system_instance = NULL;
extern SDL_Renderer* sdx_renderer;

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
entitasEntity* entityAdded (entitasEntity* e);
gboolean entitas_entity_hasSprite (entitasEntity *self);
GType systems_display_system_get_type (void) G_GNUC_CONST;
void systems_display_system_add (systemsDisplaySystem* self, entitasEntity* e);
entitasEntity* entityRemoved (entitasEntity* e);
void systems_display_system_remove (systemsDisplaySystem* self, entitasEntity* e);
GType game_get_type (void) G_GNUC_CONST;
GType entitas_world_get_type (void) G_GNUC_CONST;
GType factory_get_type (void) G_GNUC_CONST;
enum  {
	SYSTEMS_DISPLAY_SYSTEM_DUMMY_PROPERTY
};
systemsDisplaySystem* systems_display_system_new (Game* game, Factory* world);
systemsDisplaySystem* systems_display_system_construct (GType object_type, Game* game, Factory* world);
void systems_display_system_initialize (systemsDisplaySystem* self);
void systems_display_system_execute (systemsDisplaySystem* self, gdouble delta);
gboolean systems_display_system_draw (systemsDisplaySystem* self, entitasEntity* e);
gboolean entitas_entity_isBackground (entitasEntity *self);
gboolean entitas_entity_hasTint (entitasEntity *self);
GType sdx_graphics_scale_get_type (void) G_GNUC_CONST;
sdxgraphicsScale* sdx_graphics_scale_dup (const sdxgraphicsScale* self);
void sdx_graphics_scale_free (sdxgraphicsScale* self);
gboolean entitas_entity_hasText (entitasEntity *self);
GType entitas_isystem_get_type (void) G_GNUC_CONST;
entitasISystem* entitas_isystem_dup (const entitasISystem* self);
void entitas_isystem_free (entitasISystem* self);
entitasISystem systems_display_system_get__ISystem (systemsDisplaySystem* self);
static void _systems_display_system_initialize_entitas_system_initialize (gpointer self);
static void _systems_display_system_execute_entitas_system_execute (gdouble delta, gpointer self);
static void systems_display_system_finalize (GObject* obj);
static void _vala_systems_display_system_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);


/**
* add to sprites 
*/
entitasEntity* entityAdded (entitasEntity* e) {
	entitasEntity* result = NULL;
	gboolean _tmp0_ = FALSE;
	systemsDisplaySystem* _tmp2_ = NULL;
	entitasEntity* _tmp3_ = NULL;
	entitasEntity* _tmp4_ = NULL;
	_tmp0_ = entitas_entity_hasSprite (e);
	if (!_tmp0_) {
		entitasEntity* _tmp1_ = NULL;
		_tmp1_ = e;
		result = _tmp1_;
		return result;
	}
	_tmp2_ = systems_display_system_instance;
	_tmp3_ = e;
	systems_display_system_add (_tmp2_, _tmp3_);
	_tmp4_ = e;
	result = _tmp4_;
	return result;
}


/**
* remove from sprites
*/
entitasEntity* entityRemoved (entitasEntity* e) {
	entitasEntity* result = NULL;
	systemsDisplaySystem* _tmp0_ = NULL;
	entitasEntity* _tmp1_ = NULL;
	entitasEntity* _tmp2_ = NULL;
	_tmp0_ = systems_display_system_instance;
	_tmp1_ = e;
	systems_display_system_remove (_tmp0_, _tmp1_);
	_tmp2_ = e;
	result = _tmp2_;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


systemsDisplaySystem* systems_display_system_construct (GType object_type, Game* game, Factory* world) {
	systemsDisplaySystem * self = NULL;
	systemsDisplaySystem* _tmp0_ = NULL;
	Game* _tmp1_ = NULL;
	Game* _tmp2_ = NULL;
	Factory* _tmp3_ = NULL;
	Factory* _tmp4_ = NULL;
	g_return_val_if_fail (game != NULL, NULL);
	g_return_val_if_fail (world != NULL, NULL);
	self = (systemsDisplaySystem*) g_object_new (object_type, NULL);
	_tmp0_ = _g_object_ref0 (self);
	_g_object_unref0 (systems_display_system_instance);
	systems_display_system_instance = _tmp0_;
	_tmp1_ = game;
	_tmp2_ = _g_object_ref0 (_tmp1_);
	_g_object_unref0 (self->game);
	self->game = _tmp2_;
	_tmp3_ = world;
	_tmp4_ = _g_object_ref0 (_tmp3_);
	_g_object_unref0 (self->world);
	self->world = _tmp4_;
	return self;
}


systemsDisplaySystem* systems_display_system_new (Game* game, Factory* world) {
	return systems_display_system_construct (SYSTEMS_TYPE_DISPLAY_SYSTEM, game, world);
}


void systems_display_system_initialize (systemsDisplaySystem* self) {
	g_return_if_fail (self != NULL);
}


void systems_display_system_execute (systemsDisplaySystem* self, gdouble delta) {
	g_return_if_fail (self != NULL);
}


void systems_display_system_remove (systemsDisplaySystem* self, entitasEntity* e) {
	entitasEntity* _tmp0_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = e;
	self->sprites = g_list_remove (self->sprites, _tmp0_);
}


void systems_display_system_add (systemsDisplaySystem* self, entitasEntity* e) {
	gint layer = 0;
	entitasEntity* _tmp0_ = NULL;
	entitasLayer* _tmp1_ = NULL;
	gint _tmp2_ = 0;
	GList* _tmp3_ = NULL;
	guint _tmp4_ = 0U;
	g_return_if_fail (self != NULL);
	_tmp0_ = e;
	_tmp1_ = (*_tmp0_).layer;
	_tmp2_ = (*_tmp1_).value;
	layer = _tmp2_;
	_tmp3_ = self->sprites;
	_tmp4_ = g_list_length (_tmp3_);
	if (_tmp4_ == ((guint) 0)) {
		entitasEntity* _tmp5_ = NULL;
		_tmp5_ = e;
		self->sprites = g_list_append (self->sprites, _tmp5_);
	} else {
		gint i = 0;
		GList* _tmp6_ = NULL;
		entitasEntity* _tmp15_ = NULL;
		i = 0;
		_tmp6_ = self->sprites;
		{
			GList* s_collection = NULL;
			GList* s_it = NULL;
			s_collection = _tmp6_;
			for (s_it = s_collection; s_it != NULL; s_it = s_it->next) {
				entitasEntity* s = NULL;
				s = s_it->data;
				{
					entitasEntity* _tmp7_ = NULL;
					gint _tmp8_ = 0;
					entitasEntity* _tmp9_ = NULL;
					entitasLayer* _tmp10_ = NULL;
					gint _tmp11_ = 0;
					_tmp7_ = s;
					_vala_assert (_tmp7_ != NULL, "s != null");
					_tmp8_ = layer;
					_tmp9_ = s;
					_tmp10_ = (*_tmp9_).layer;
					_tmp11_ = (*_tmp10_).value;
					if (_tmp8_ <= _tmp11_) {
						entitasEntity* _tmp12_ = NULL;
						gint _tmp13_ = 0;
						_tmp12_ = e;
						_tmp13_ = i;
						self->sprites = g_list_insert (self->sprites, _tmp12_, _tmp13_);
						return;
					} else {
						gint _tmp14_ = 0;
						_tmp14_ = i;
						i = _tmp14_ + 1;
					}
				}
			}
		}
		_tmp15_ = e;
		self->sprites = g_list_append (self->sprites, _tmp15_);
	}
}


gboolean systems_display_system_draw (systemsDisplaySystem* self, entitasEntity* e) {
	gboolean result = FALSE;
	gboolean _tmp0_ = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = entitas_entity_hasSprite (e);
	if (_tmp0_) {
		entitasEntity* _tmp1_ = NULL;
		SDL_Rect* _tmp2_ = NULL;
		entitasEntity* _tmp3_ = NULL;
		entitasSprite* _tmp4_ = NULL;
		gint _tmp5_ = 0;
		entitasEntity* _tmp6_ = NULL;
		entitasScale* _tmp7_ = NULL;
		gdouble _tmp8_ = 0.0;
		entitasEntity* _tmp9_ = NULL;
		SDL_Rect* _tmp10_ = NULL;
		entitasEntity* _tmp11_ = NULL;
		entitasSprite* _tmp12_ = NULL;
		gint _tmp13_ = 0;
		entitasEntity* _tmp14_ = NULL;
		entitasScale* _tmp15_ = NULL;
		gdouble _tmp16_ = 0.0;
		gboolean _tmp17_ = FALSE;
		SDL_Renderer* _tmp55_ = NULL;
		entitasEntity* _tmp56_ = NULL;
		entitasSprite* _tmp57_ = NULL;
		sdxgraphicsSprite* _tmp58_ = NULL;
		SDL_Texture* _tmp59_ = NULL;
		entitasEntity* _tmp60_ = NULL;
		SDL_Rect* _tmp61_ = NULL;
		gint _tmp62_ = 0;
		entitasEntity* _tmp63_ = NULL;
		SDL_Rect* _tmp64_ = NULL;
		gint _tmp65_ = 0;
		entitasEntity* _tmp66_ = NULL;
		SDL_Rect* _tmp67_ = NULL;
		guint _tmp68_ = 0U;
		entitasEntity* _tmp69_ = NULL;
		SDL_Rect* _tmp70_ = NULL;
		guint _tmp71_ = 0U;
		SDL_Rect _tmp72_ = {0};
		gboolean _tmp73_ = FALSE;
		_tmp1_ = e;
		_tmp2_ = (*_tmp1_).bounds;
		_tmp3_ = e;
		_tmp4_ = (*_tmp3_).sprite;
		_tmp5_ = (*_tmp4_).width;
		_tmp6_ = e;
		_tmp7_ = (*_tmp6_).scale;
		_tmp8_ = (*_tmp7_).x;
		(*_tmp2_).w = (guint) ((gint) (((gdouble) _tmp5_) * _tmp8_));
		_tmp9_ = e;
		_tmp10_ = (*_tmp9_).bounds;
		_tmp11_ = e;
		_tmp12_ = (*_tmp11_).sprite;
		_tmp13_ = (*_tmp12_).height;
		_tmp14_ = e;
		_tmp15_ = (*_tmp14_).scale;
		_tmp16_ = (*_tmp15_).y;
		(*_tmp10_).h = (guint) ((gint) (((gdouble) _tmp13_) * _tmp16_));
		_tmp17_ = entitas_entity_isBackground (e);
		if (!_tmp17_) {
			entitasEntity* _tmp18_ = NULL;
			SDL_Rect* _tmp19_ = NULL;
			entitasEntity* _tmp20_ = NULL;
			entitasPosition* _tmp21_ = NULL;
			gdouble _tmp22_ = 0.0;
			entitasEntity* _tmp23_ = NULL;
			SDL_Rect* _tmp24_ = NULL;
			guint _tmp25_ = 0U;
			entitasEntity* _tmp26_ = NULL;
			SDL_Rect* _tmp27_ = NULL;
			entitasEntity* _tmp28_ = NULL;
			entitasPosition* _tmp29_ = NULL;
			gdouble _tmp30_ = 0.0;
			entitasEntity* _tmp31_ = NULL;
			SDL_Rect* _tmp32_ = NULL;
			guint _tmp33_ = 0U;
			gboolean _tmp34_ = FALSE;
			_tmp18_ = e;
			_tmp19_ = (*_tmp18_).bounds;
			_tmp20_ = e;
			_tmp21_ = (*_tmp20_).position;
			_tmp22_ = (*_tmp21_).x;
			_tmp23_ = e;
			_tmp24_ = (*_tmp23_).bounds;
			_tmp25_ = (*_tmp24_).w;
			(*_tmp19_).x = (gint) (((gdouble) _tmp22_) - (_tmp25_ / 2));
			_tmp26_ = e;
			_tmp27_ = (*_tmp26_).bounds;
			_tmp28_ = e;
			_tmp29_ = (*_tmp28_).position;
			_tmp30_ = (*_tmp29_).y;
			_tmp31_ = e;
			_tmp32_ = (*_tmp31_).bounds;
			_tmp33_ = (*_tmp32_).h;
			(*_tmp27_).y = (gint) (((gdouble) _tmp30_) - (_tmp33_ / 2));
			_tmp34_ = entitas_entity_hasTint (e);
			if (_tmp34_) {
				entitasEntity* _tmp35_ = NULL;
				entitasSprite* _tmp36_ = NULL;
				sdxgraphicsSprite* _tmp37_ = NULL;
				SDL_Texture* _tmp38_ = NULL;
				entitasEntity* _tmp39_ = NULL;
				entitasTint* _tmp40_ = NULL;
				gint _tmp41_ = 0;
				entitasEntity* _tmp42_ = NULL;
				entitasTint* _tmp43_ = NULL;
				gint _tmp44_ = 0;
				entitasEntity* _tmp45_ = NULL;
				entitasTint* _tmp46_ = NULL;
				gint _tmp47_ = 0;
				entitasEntity* _tmp48_ = NULL;
				entitasSprite* _tmp49_ = NULL;
				sdxgraphicsSprite* _tmp50_ = NULL;
				SDL_Texture* _tmp51_ = NULL;
				entitasEntity* _tmp52_ = NULL;
				entitasTint* _tmp53_ = NULL;
				gint _tmp54_ = 0;
				_tmp35_ = e;
				_tmp36_ = (*_tmp35_).sprite;
				_tmp37_ = (*_tmp36_).sprite;
				_tmp38_ = _tmp37_->texture;
				_tmp39_ = e;
				_tmp40_ = (*_tmp39_).tint;
				_tmp41_ = (*_tmp40_).r;
				_tmp42_ = e;
				_tmp43_ = (*_tmp42_).tint;
				_tmp44_ = (*_tmp43_).g;
				_tmp45_ = e;
				_tmp46_ = (*_tmp45_).tint;
				_tmp47_ = (*_tmp46_).b;
				SDL_SetTextureColorMod (_tmp38_, (guint8) _tmp41_, (guint8) _tmp44_, (guint8) _tmp47_);
				_tmp48_ = e;
				_tmp49_ = (*_tmp48_).sprite;
				_tmp50_ = (*_tmp49_).sprite;
				_tmp51_ = _tmp50_->texture;
				_tmp52_ = e;
				_tmp53_ = (*_tmp52_).tint;
				_tmp54_ = (*_tmp53_).a;
				SDL_SetTextureAlphaMod (_tmp51_, (guint8) _tmp54_);
			}
		}
		_tmp55_ = sdx_renderer;
		_tmp56_ = e;
		_tmp57_ = (*_tmp56_).sprite;
		_tmp58_ = (*_tmp57_).sprite;
		_tmp59_ = _tmp58_->texture;
		_tmp60_ = e;
		_tmp61_ = (*_tmp60_).bounds;
		_tmp62_ = (*_tmp61_).x;
		_tmp63_ = e;
		_tmp64_ = (*_tmp63_).bounds;
		_tmp65_ = (*_tmp64_).y;
		_tmp66_ = e;
		_tmp67_ = (*_tmp66_).bounds;
		_tmp68_ = (*_tmp67_).w;
		_tmp69_ = e;
		_tmp70_ = (*_tmp69_).bounds;
		_tmp71_ = (*_tmp70_).h;
		_tmp72_.x = _tmp62_;
		_tmp72_.y = _tmp65_;
		_tmp72_.w = (guint) _tmp68_;
		_tmp72_.h = (guint) _tmp71_;
		SDL_RenderCopy (_tmp55_, _tmp59_, NULL, &_tmp72_);
		_tmp73_ = entitas_entity_hasText (e);
		if (_tmp73_) {
			SDL_Renderer* _tmp74_ = NULL;
			entitasEntity* _tmp75_ = NULL;
			entitasText* _tmp76_ = NULL;
			sdxgraphicsSprite* _tmp77_ = NULL;
			SDL_Texture* _tmp78_ = NULL;
			entitasEntity* _tmp79_ = NULL;
			entitasPosition* _tmp80_ = NULL;
			gdouble _tmp81_ = 0.0;
			entitasEntity* _tmp82_ = NULL;
			entitasPosition* _tmp83_ = NULL;
			gdouble _tmp84_ = 0.0;
			entitasEntity* _tmp85_ = NULL;
			entitasText* _tmp86_ = NULL;
			sdxgraphicsSprite* _tmp87_ = NULL;
			gint _tmp88_ = 0;
			entitasEntity* _tmp89_ = NULL;
			entitasText* _tmp90_ = NULL;
			sdxgraphicsSprite* _tmp91_ = NULL;
			gint _tmp92_ = 0;
			SDL_Rect _tmp93_ = {0};
			_tmp74_ = sdx_renderer;
			_tmp75_ = e;
			_tmp76_ = (*_tmp75_).text;
			_tmp77_ = (*_tmp76_).sprite;
			_tmp78_ = _tmp77_->texture;
			_tmp79_ = e;
			_tmp80_ = (*_tmp79_).position;
			_tmp81_ = (*_tmp80_).x;
			_tmp82_ = e;
			_tmp83_ = (*_tmp82_).position;
			_tmp84_ = (*_tmp83_).y;
			_tmp85_ = e;
			_tmp86_ = (*_tmp85_).text;
			_tmp87_ = (*_tmp86_).sprite;
			_tmp88_ = _tmp87_->width;
			_tmp89_ = e;
			_tmp90_ = (*_tmp89_).text;
			_tmp91_ = (*_tmp90_).sprite;
			_tmp92_ = _tmp91_->height;
			_tmp93_.x = (gint) _tmp81_;
			_tmp93_.y = (gint) _tmp84_;
			_tmp93_.w = (guint) _tmp88_;
			_tmp93_.h = (guint) _tmp92_;
			SDL_RenderCopy (_tmp74_, _tmp78_, NULL, &_tmp93_);
		}
	}
	result = TRUE;
	return result;
}


static void _systems_display_system_initialize_entitas_system_initialize (gpointer self) {
	systems_display_system_initialize ((systemsDisplaySystem*) self);
}


static void _systems_display_system_execute_entitas_system_execute (gdouble delta, gpointer self) {
	systems_display_system_execute ((systemsDisplaySystem*) self, delta);
}


entitasISystem systems_display_system_get__ISystem (systemsDisplaySystem* self) {
	entitasISystem result;
	entitasISystem _tmp0_ = {0};
	_tmp0_.initialize = _systems_display_system_initialize_entitas_system_initialize;
	_tmp0_.initialize_target = self;
	_tmp0_.execute = _systems_display_system_execute_entitas_system_execute;
	_tmp0_.execute_target = self;
	result = _tmp0_;
	return result;
}


static void systems_display_system_class_init (systemsDisplaySystemClass * klass) {
	systems_display_system_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->get_property = _vala_systems_display_system_get_property;
	G_OBJECT_CLASS (klass)->finalize = systems_display_system_finalize;
}


static void systems_display_system_instance_init (systemsDisplaySystem * self) {
	self->sprites = NULL;
}


static void systems_display_system_finalize (GObject* obj) {
	systemsDisplaySystem * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, SYSTEMS_TYPE_DISPLAY_SYSTEM, systemsDisplaySystem);
	_g_object_unref0 (self->game);
	_g_object_unref0 (self->world);
	_g_list_free0 (self->sprites);
	G_OBJECT_CLASS (systems_display_system_parent_class)->finalize (obj);
}


/**
* game systems
*/
GType systems_display_system_get_type (void) {
	static volatile gsize systems_display_system_type_id__volatile = 0;
	if (g_once_init_enter (&systems_display_system_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (systemsDisplaySystemClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) systems_display_system_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (systemsDisplaySystem), 0, (GInstanceInitFunc) systems_display_system_instance_init, NULL };
		GType systems_display_system_type_id;
		systems_display_system_type_id = g_type_register_static (G_TYPE_OBJECT, "systemsDisplaySystem", &g_define_type_info, 0);
		g_once_init_leave (&systems_display_system_type_id__volatile, systems_display_system_type_id);
	}
	return systems_display_system_type_id__volatile;
}


static void _vala_systems_display_system_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	systemsDisplaySystem * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, SYSTEMS_TYPE_DISPLAY_SYSTEM, systemsDisplaySystem);
	switch (property_id) {
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



