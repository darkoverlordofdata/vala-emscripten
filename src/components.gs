/**
 * Entitas Generated Entity & Components for shmupwarz
 *
 * do not edit this file
 */
 
namespace entitas

	[SimpleType]
	struct Background
		active : bool

	// [SimpleType]
	// struct Bounds
	// 	x : int 
	// 	y : int 
	// 	w : int 
	// 	h : int 

	[SimpleType]
	struct Bullet
		active : bool

	[SimpleType]
	struct Enemy1
		active : bool

	[SimpleType]
	struct Enemy2
		active : bool

	[SimpleType]
	struct Enemy3
		active : bool

	[SimpleType]
	struct Expires
		value : double 

	[SimpleType]
	struct Health
		current : double 
		maximum : double 

	[SimpleType]
	struct Hud
		active : bool

	[SimpleType]
	struct Index
		value : int 
		limit : int
		vertical  : bool

	[SimpleType]
	struct Layer
		value : int 

	[SimpleType]
	struct Position
		x : double 
		y : double 

	[SimpleType]
	struct Scale
		x : double 
		y : double 

	// struct Sound
	// 	sound : SDL.Chunk 

	struct Sprite
		sprite: sdx.graphics.Sprite
		width: int
		height: int

	struct Text
		text : string 
		sprite: sdx.graphics.Sprite

	[SimpleType]
	struct Tint
		r : int 
		g : int 
		b : int 
		a : int 

	[SimpleType]
	struct Tween
		min : double 
		max : double 
		speed : double 
		repeat : bool 
		active : bool 

	[SimpleType]
	struct Velocity
		x : double 
		y : double 

	struct Entity					   	/* Core component: */  
		id		  	: int			   	/* sequentially assigned id# */
		name		: string			/* display name */
		pool		: int			   	/* pool entities by type */
		mask		: uint64			/* hasComponent bit array */
		background  : Background?
		bounds		: SDL.Video.Rect? //Bounds?
		bullet		: Bullet?
		enemy1		: Enemy1?
		enemy2		: Enemy2?
		enemy3		: Enemy3?
		expires		: Expires?
		health		: Health?
		hud			: Hud?
		index		: Index?
		layer		: Layer?
		position	: Position?
		scale		: Scale?
		// sound	   : Sound?
		sprite		: Sprite?
		text		: Text?
		tint		: Tint?
		tween		: Tween?
		velocity	: Velocity?

		def hasComponent(index : int) : bool
			return (__POW2__[index] & mask) != 0

		def hasComponents(indices : array of int) : bool
			for var index in indices do if (__POW2__[index] & mask) == 0 do return false
			return true

		def hasAnyComponent(indices : array of int) : bool
			for var index in indices do if (__POW2__[index] & mask) != 0 do return true
			return false

		def setId(id:int):Entity*
			this.id = id
			return &this

		def setName(name:string):Entity*
			this.name = name
			return &this

		def setActive(active:bool):Entity*
			if ((mask & __ACTIVE__) == __ACTIVE__ ) == active do return &this
			if active do mask |= __ACTIVE__
			else do mask ^= __ACTIVE__
			return &this

		def setPool(pool:int):Entity*
			this.pool = pool
			return &this

		def isActive():bool
			return (mask & __ACTIVE__) == __ACTIVE__

		def toString():string
			var sb = ""
			sb = sb + id.to_string() + "(" + name + ")"
			var seperator = false
			for var i = 1 to Components.COUNT
				if hasComponent(i)
					if seperator do sb = sb + ", "
					sb = sb + ComponentString[i]
					seperator = true
			return sb


		/**
		 * Components:
		 */

		def setBackground(value:bool):Entity*
			if value
				this.background = { true }
				mask |= __BACKGROUND__
			else
				this.background = null
				mask ^= __BACKGROUND__
			return &this

		def isBackground():bool
			if this.background == null do return false
			else do return true

		def hasBounds():bool
			return (mask & __BOUNDS__) != 0

		def addBounds(x:int,y:int,w:int,h:int):Entity* 
			if (mask & __BOUNDS__) != 0 do raise new Exception.EntityAlreadyHasComponent("Bounds")
			this.bounds = { x, y, w, h }
			mask |= __BOUNDS__
			World.onComponentAdded(&this, Components.BoundsComponent)
			return &this

		def setBounds(x:int,y:int,w:int,h:int):Entity*
			if (mask & __BOUNDS__) == 0 do raise new Exception.EntityDoesNotHaveComponent("Bounds")
			this.bounds.x = x
			this.bounds.y = y
			this.bounds.w = w
			this.bounds.h = h
			return &this

		def removeBounds():Entity*
			if (mask & __BOUNDS__) == 0 do raise new Exception.EntityDoesNotHaveComponent("Bounds")
			this.bounds = null
			mask ^= __BOUNDS__
			World.onComponentRemoved(&this, Components.BoundsComponent)
			return &this

		def setBullet(value:bool):Entity*
			if value
				this.bullet = { true }
				mask |= __BULLET__
				World.onComponentAdded(&this, Components.BulletComponent)
			else
				this.bullet = null
				mask ^= __BULLET__
				World.onComponentRemoved(&this, Components.BulletComponent)
			return &this

		def isBullet():bool
			return (mask & __BULLET__) != 0

		def setEnemy1(value:bool):Entity*
			if value
				this.enemy1 = { true }
				mask |= __ENEMY1__
				World.onComponentAdded(&this, Components.Enemy1Component)
			else
				this.enemy1 = null
				mask ^= __ENEMY1__
				World.onComponentRemoved(&this, Components.Enemy1Component)
			return &this

		def isEnemy1():bool
			return (mask & __ENEMY1__) != 0

		def setEnemy2(value:bool):Entity*
			if value
				this.enemy2 = { true }
				mask |= __ENEMY2__
				World.onComponentAdded(&this, Components.Enemy2Component)
			else
				this.enemy2 = null
				mask ^= __ENEMY2__
				World.onComponentRemoved(&this, Components.Enemy2Component)
			return &this

		def isEnemy2():bool
			return (mask & __ENEMY2__) != 0

		def setEnemy3(value:bool):Entity*
			if value
				this.enemy3 = { true }
				mask |= __ENEMY3__
				World.onComponentAdded(&this, Components.Enemy3Component)
			else
				this.enemy3 = null
				mask ^= __ENEMY3__
				World.onComponentRemoved(&this, Components.Enemy3Component)
			return &this

		def isEnemy3():bool
			return (mask & __ENEMY3__) != 0

		def hasExpires():bool
			return (mask & __EXPIRES__) != 0

		def addExpires(value:double):Entity* 
			if (mask & __EXPIRES__) != 0 do raise new Exception.EntityAlreadyHasComponent("Expires")
			this.expires = { value }
			mask |= __EXPIRES__
			World.onComponentAdded(&this, Components.ExpiresComponent)
			return &this

		def setExpires(value:double):Entity*
			if (mask & __EXPIRES__) == 0 do raise new Exception.EntityDoesNotHaveComponent("Expires")
			this.expires.value = value
			return &this

		def removeExpires():Entity*
			if (mask & __EXPIRES__) == 0 do raise new Exception.EntityDoesNotHaveComponent("Expires")
			this.expires = null
			mask ^= __EXPIRES__
			World.onComponentRemoved(&this, Components.ExpiresComponent)
			return &this

		def hasHealth():bool
			return (mask & __HEALTH__) != 0

		def addHealth(current:double,maximum:double):Entity* 
			if (mask & __HEALTH__) != 0 do raise new Exception.EntityAlreadyHasComponent("Health")
			this.health = { current, maximum }
			mask |= __HEALTH__
			World.onComponentAdded(&this, Components.HealthComponent)
			return &this

		def setHealth(current:double,maximum:double):Entity*
			if (mask & __HEALTH__) == 0 do raise new Exception.EntityDoesNotHaveComponent("Health")
			this.health.current = current
			this.health.maximum = maximum
			return &this

		def removeHealth():Entity*
			if (mask & __HEALTH__) == 0 do raise new Exception.EntityDoesNotHaveComponent("Health")
			this.health = null
			mask ^= __HEALTH__
			World.onComponentRemoved(&this, Components.HealthComponent)
			return &this

		def setHud(value:bool):Entity*
			if value
				this.hud = { true }
				mask |= __HUD__
				World.onComponentAdded(&this, Components.HudComponent)
			else
				this.hud = null
				mask ^= __HUD__
				World.onComponentRemoved(&this, Components.HudComponent)
			return &this

		def isHud():bool
			if this.hud == null do return false
			else do return true

		def hasIndex():bool
			return (mask & __INDEX__) != 0

		def addIndex(value:int, limit: int, vertical: bool):Entity* 
			if (mask & __INDEX__) != 0 do raise new Exception.EntityAlreadyHasComponent("Index")
			this.index = { value , limit, vertical }
			mask |= __INDEX__
			World.onComponentAdded(&this, Components.IndexComponent)
			return &this

		def setIndex(value:int, limit: int, vertical: bool):Entity*
			if (mask & __INDEX__) == 0 do raise new Exception.EntityDoesNotHaveComponent("Index")
			this.index.value = value
			this.index.limit = value
			this.index.vertical = vertical
			return &this

		def removeIndex():Entity*
			if (mask & __INDEX__) == 0 do raise new Exception.EntityDoesNotHaveComponent("Index")
			this.index = null
			mask ^= __INDEX__
			World.onComponentRemoved(&this, Components.IndexComponent)
			return &this

		def hasLayer():bool
			return (mask & __LAYER__) != 0

		def addLayer(value:int):Entity* 
			if (mask & __LAYER__) != 0 do raise new Exception.EntityAlreadyHasComponent("Layer")
			this.layer = { value }
			mask |= __LAYER__
			World.onComponentAdded(&this, Components.LayerComponent)
			return &this

		def setLayer(value:int):Entity*
			if (mask & __LAYER__) == 0 do raise new Exception.EntityDoesNotHaveComponent("Layer")
			this.layer.value = value
			return &this

		def removeLayer():Entity*
			if (mask & __LAYER__) == 0 do raise new Exception.EntityDoesNotHaveComponent("Layer")
			this.layer = null
			mask ^= __LAYER__
			World.onComponentRemoved(&this, Components.LayerComponent)
			return &this

		def hasPosition():bool
			return (mask & __POSITION__) != 0

		def addPosition(x:double,y:double):Entity* 
			if (mask & __POSITION__) != 0 do raise new Exception.EntityAlreadyHasComponent("Unable to add Position")
			this.position = { x, y }
			mask |= __POSITION__
			World.onComponentAdded(&this, Components.PositionComponent)
			return &this

		def setPosition(x:double,y:double):Entity*
			if (mask & __POSITION__) == 0 do raise new Exception.EntityDoesNotHaveComponent("Unable to set Position")
			this.position.x = x
			this.position.y = y
			return &this

		def removePosition():Entity*
			if (mask & __POSITION__) == 0 do raise new Exception.EntityDoesNotHaveComponent("Unable to remove Position")
			this.position = null
			mask ^= __POSITION__
			World.onComponentRemoved(&this, Components.PositionComponent)
			return &this

		def hasScale():bool
			return (mask & __SCALE__) != 0

		def addScale(x:double,y:double):Entity* 
			if (mask & __SCALE__) != 0 do raise new Exception.EntityAlreadyHasComponent("Scale")
			this.scale = { x, y }
			mask |= __SCALE__
			World.onComponentAdded(&this, Components.ScaleComponent)
			return &this

		def setScale(x:double,y:double):Entity*
			if (mask & __SCALE__) == 0 do raise new Exception.EntityDoesNotHaveComponent("Scale")
			this.scale.x = x
			this.scale.y = y
			return &this

		def removeScale():Entity*
			if (mask & __SCALE__) == 0 do raise new Exception.EntityDoesNotHaveComponent("Scale")
			this.scale = null
			mask ^= __SCALE__
			World.onComponentRemoved(&this, Components.ScaleComponent)
			return &this

		// def hasSound():bool
		// 	return (mask & __SOUND__) != 0

		// def addSound(sound:SDLMixer.Chunk):Entity* 
		// 	if (mask & __SOUND__) != 0 do raise new Exception.EntityAlreadyHasComponent("Sound")
		// 	this.sound = { sound }
		// 	mask |= __SOUND__
		// 	//World.onComponentAdded(&this, Components.SoundComponent)
		// 	return &this

		// def setSound(sound:SDLMixer.Chunk):Entity*
		// 	if (mask & __SOUND__) == 0 do raise new Exception.EntityDoesNotHaveComponent("Sound")
		// 	this.sound.sound = sound
		// 	return &this

		// def removeSound():Entity*
		// 	if (mask & __SOUND__) == 0 do raise new Exception.EntityDoesNotHaveComponent("Sound")
		// 	this.sound = null
		// 	mask ^= __SOUND__
		// 	//World.onComponentRemoved(&this, Components.SoundComponent)
		// 	return &this

		def hasSprite():bool
			return (mask & __SPRITE__) != 0

		def addSprite(sprite:sdx.graphics.Sprite, width: int, height: int):Entity* 
			if (mask & __SPRITE__) != 0 do raise new Exception.EntityAlreadyHasComponent("Sprite")
			this.sprite = { sprite, width, height }
			mask |= __SPRITE__
			World.onComponentAdded(&this, Components.SpriteComponent)
			return &this

		def setSprite(sprite:sdx.graphics.Sprite, width: int, height: int):Entity*
			if (mask & __SPRITE__) == 0 do raise new Exception.EntityDoesNotHaveComponent("Sprite")
			this.sprite.sprite = sprite
			this.sprite.width = width
			this.sprite.height = height
			return &this

		def removeSprite():Entity*
			if (mask & __SPRITE__) == 0 do raise new Exception.EntityDoesNotHaveComponent("Sprite")
			this.sprite = null
			mask ^= __SPRITE__
			World.onComponentRemoved(&this, Components.SpriteComponent)
			return &this

		def hasText():bool
			return (mask & __TEXT__) != 0

		def addText(text:string,texture:sdx.graphics.Sprite):Entity* 
			if (mask & __TEXT__) != 0 do raise new Exception.EntityAlreadyHasComponent("Text")
			this.text = { text, texture }
			mask |= __TEXT__
			World.onComponentAdded(&this, Components.TextComponent)
			return &this

		def setText(text:string,texture:sdx.graphics.Sprite):Entity*
			if (mask & __TEXT__) == 0 do raise new Exception.EntityDoesNotHaveComponent("Text")
			this.text.text = text
			this.text.sprite = texture
			return &this

		def removeText():Entity*
			if (mask & __TEXT__) == 0 do raise new Exception.EntityDoesNotHaveComponent("Text")
			this.text = null
			mask ^= __TEXT__
			World.onComponentRemoved(&this, Components.TextComponent)
			return &this

		def hasTint():bool
			return (mask & __TINT__) != 0

		def addTint(r:int,g:int,b:int,a:int):Entity* 
			if (mask & __TINT__) != 0 do raise new Exception.EntityAlreadyHasComponent("Tint")
			this.tint = { r, g, b, a }
			mask |= __TINT__
			World.onComponentAdded(&this, Components.TintComponent)
			return &this

		def setTint(r:int,g:int,b:int,a:int):Entity*
			if (mask & __TINT__) == 0 do raise new Exception.EntityDoesNotHaveComponent("Tint")
			this.tint.r = r
			this.tint.g = g
			this.tint.b = b
			this.tint.a = a
			return &this

		def removeTint():Entity*
			if (mask & __TINT__) == 0 do raise new Exception.EntityDoesNotHaveComponent("Tint")
			this.tint = null
			mask ^= __TINT__
			World.onComponentRemoved(&this, Components.TintComponent)
			return &this

		def hasTween():bool
			return (mask & __TWEEN__) != 0

		def addTween(min:double,max:double,speed:double,repeat:bool,active:bool):Entity* 
			if (mask & __TWEEN__) != 0 do raise new Exception.EntityAlreadyHasComponent("Tween")
			this.tween = { min, max, speed, repeat, active }
			mask |= __TWEEN__
			World.onComponentAdded(&this, Components.TweenComponent)
			return &this

		def setTween(min:double,max:double,speed:double,repeat:bool,active:bool):Entity*
			if (mask & __TWEEN__) == 0 do raise new Exception.EntityDoesNotHaveComponent("Tween")
			this.tween.min = min
			this.tween.max = max
			this.tween.speed = speed
			this.tween.repeat = repeat
			this.tween.active = active
			return &this

		def removeTween():Entity*
			if (mask & __TWEEN__) == 0 do raise new Exception.EntityDoesNotHaveComponent("Tween")
			this.tween = null
			mask ^= __TWEEN__
			World.onComponentRemoved(&this, Components.TweenComponent)
			return &this

		def hasVelocity():bool
			return (mask & __VELOCITY__) != 0

		def addVelocity(x:double,y:double):Entity* 
			if (mask & __VELOCITY__) != 0 do raise new Exception.EntityAlreadyHasComponent("Velocity")
			this.velocity = { x, y }
			mask |= __VELOCITY__
			World.onComponentAdded(&this, Components.VelocityComponent)
			return &this

		def setVelocity(x:double,y:double):Entity*
			if (mask & __VELOCITY__) == 0 do raise new Exception.EntityDoesNotHaveComponent("Velocity")
			this.velocity.x = x
			this.velocity.y = y
			return &this

		def removeVelocity():Entity*
			if (mask & __VELOCITY__) == 0 do raise new Exception.EntityDoesNotHaveComponent("Velocity")
			this.velocity = null
			mask ^= __VELOCITY__
			World.onComponentRemoved(&this, Components.VelocityComponent)
			return &this


	/**
	 *  Component bit masks
	 */
	const __BACKGROUND__:uint64 = 0x0001
	const __BOUNDS__:uint64 = 0x0002
	const __BULLET__:uint64 = 0x0004
	const __ENEMY1__:uint64 = 0x0008
	const __ENEMY2__:uint64 = 0x0010
	const __ENEMY3__:uint64 = 0x0020
	const __EXPIRES__:uint64 = 0x0040
	const __HEALTH__:uint64 = 0x0080
	const __HUD__:uint64 = 0x0100
	const __INDEX__:uint64 = 0x0200
	const __LAYER__:uint64 = 0x0400
	const __POSITION__:uint64 = 0x0800
	const __SCALE__:uint64 = 0x1000
	// const __SOUND__:uint64 = 0x2000
	const __SPRITE__:uint64 = 0x4000
	const __TEXT__:uint64 = 0x8000
	const __TINT__:uint64 = 0x10000
	const __TWEEN__:uint64 = 0x20000
	const __VELOCITY__:uint64 = 0x40000
	const __ACTIVE__:uint64 = 0x8000000000000000


	
	/**
	* Component names
	*/
	const ComponentString: array of string = {
		"",
		"Background",
		"Bounds",
		"Bullet",
		"Enemy1",
		"Enemy2",
		"Enemy3",
		"Expires",
		"Health",
		"Hud",
		"Index",
		"Layer",
		"Position",
		"Scale",
		"Sound",
		"Sprite",
		"Text",
		"Tint",
		"Tween",
		"Velocity"

	}

	/**
	* Components
	*/
	enum Components
		BackgroundComponent = 1
		BoundsComponent
		BulletComponent
		Enemy1Component
		Enemy2Component
		Enemy3Component
		ExpiresComponent
		HealthComponent
		HudComponent
		IndexComponent
		LayerComponent
		PositionComponent
		ScaleComponent
		SoundComponent
		SpriteComponent
		TextComponent
		TintComponent
		TweenComponent
		VelocityComponent
		COUNT = 19


