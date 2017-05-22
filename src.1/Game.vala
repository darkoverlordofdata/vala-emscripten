/**
 * Game controller 
 */
using entitas;
using systems;


public class Game : Object {

	public static Game instance;
	public int width;
	public int height;
	public Factory world;

	public CollisionSystem collision;
	public ExpireSystem expire;
	public InputSystem input;
	public PhysicsSystem physics;
	public RemoveSystem remove;
	public SpawnSystem spawn;
	public AnimationSystem animate;
	public DisplaySystem display;
	public ScoreSystem score;

	public Game(int width, int height) {
		instance = this;
		this.width = width;
		this.height = height;
	}

	public void initialize() {

		sdx.setSmallFont("assets/fonts/OpenDyslexic-Bold.otf", 16);
		sdx.setDefaultFont("assets/fonts/OpenDyslexic-Bold.otf", 24);
		sdx.setShowFps(true);

		world = new Factory();
		world.setEntityRemovedListener(entityRemoved);

		spawn = new SpawnSystem(this, world);
		input = new InputSystem(this, world);
		collision = new CollisionSystem(this, world);
		physics = new PhysicsSystem(this, world);
		expire = new ExpireSystem(this, world);
		remove = new RemoveSystem(this, world);
		animate = new AnimationSystem(this, world);
		display = new DisplaySystem(this, world);
		score = new ScoreSystem(this, world);

		world.addSystem(spawn._ISystem);
		world.addSystem(input._ISystem);
		world.addSystem(physics._ISystem);
		world.addSystem(collision._ISystem);
		world.addSystem(animate._ISystem);
		world.addSystem(expire._ISystem);
		world.addSystem(remove._ISystem);
		world.addSystem(score._ISystem);
		world.addSystem(display._ISystem);
		world.initialize();
		world.createBackground();
	}

	public void start() {
		sdx.start();
	}

	public void update() {
		sdx.update();	
		sdx.processEvents();
		world.execute(sdx.delta);
	}

	public void draw() {
		sdx.begin();
		foreach (var sprite in display.sprites) {
			if (sprite.isActive()) display.draw(sprite);
		}
		sdx.drawFps();
		sdx.end();
	}

}