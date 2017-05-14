# vala-emscripten

* Compile vala/genie with emscripten. 
* Works with SDL2. 
* Both vala and genie, but vala has fewer limitations.

Vala compiles to C, so it can target emscripten. That seems like a no brainer. 
The problem is, there is no runtime - Vala uses GLib for it's runtime, and there is no glib port for Emscripten. 

https://github.com/radare/posixvala shows how we can hack the runtime back to life, by supplying missing GLib implementation.

I'm taking this hack further, re-fitting selected glib modules to work in emscripten. 
There is also no GObject in Emscripten. This limits it to compact class. so I've added a preprocessing step to inject automatic reference counting into classes tagged by 'subclassing' Object.

## status
work in progress. my game compiles and runs on both desktop and escriptem, same code except the main loop.

## build

deskstop:
mkdir install
cd install
cmake .. -DDESKTOP=ON -DPROFILING=ON
make

emscripten
cake em

## oop limitations

* no regex
* no virtual or override
* no interface
* no abstract
* no [Flags] enum
* subclases cannot declare instance members

## workarounds
to replace interface, make a struct of delegates

### example
the main loop is simple:


```vala
public static int main (string[] args) {

    Game game = new Game();
    emscripten_set_main_loop_arg(mainloop, game, 0, 1);
    return;
}

public void mainloop(void* arg) {
    var game = (Game*)arg;
    game->update();
    game->draw();

}
```



valac2 --plugin tools/emvalac --builddir build -C --define PROFILING --save-temps --disable-warnings --vapidir src/vapis --pkg mt19937ar --pkg posix --pkg sdl2 --pkg SDL2_image --pkg SDL2_ttf --pkg SDL2_mixer --pkg emscripten -X "--preload-file assets" -X -Iinclude -X -O2 -X "-s WASM=1" -X "-s USE_SDL=2" -X "-s USE_SDL_IMAGE=2" -X "-s USE_SDL_TTF=2"  -X "-s SDL2_IMAGE_FORMATS='[\"png\"]'" -X "-s EXPORTED_FUNCTIONS='[\"_game\"]'" -X "-s ASSERTIONS=1" -o web/shmupwarz.html  build/src/Factory.vala build/src/Game.vala build/src/components.gs build/src/entitas/Cache.vala build/src/entitas/Group.vala build/src/entitas/Matcher.vala build/src/entitas/World.vala build/src/entitas/entitas.vala build/src/main.vala build/src/sdx/Color.gs build/src/sdx/Files.vala build/src/sdx/Font.vala build/src/sdx/files/FileHandle.vala build/src/sdx/graphics/Sprite.vala build/src/sdx/graphics/Surface.vala build/src/sdx/sdx.vala build/src/systems/AnimationSystem.vala build/src/systems/CollisionSystem.vala build/src/systems/DisplaySystem.vala build/src/systems/ExpireSystem.vala build/src/systems/InputSystem.vala build/src/systems/PhysicsSystem.vala build/src/systems/RemoveSystem.vala build/src/systems/ScoreSystem.vala build/src/systems/SpawnSystem.vala build/src/util/Cache.vala build/src/util/File.vala build/src/util/String.vala build/src/vala-emscripten.vala

