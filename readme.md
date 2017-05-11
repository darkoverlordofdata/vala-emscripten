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

## oop limitations

* no regex
* no virtual or override
* no interface
* no abstract
* no [Flags] enum
* subclases cannot declare instance members

it's unfortunate, but genie doesn't work as well, it has more dependancies on GObject,
so these are also broken:

* no Gee 
* no Properties
* no underscore in first char

Vala still has lambdas.

## workarounds
to replace interface, make a struct of delegates

## notes
one class per file
namespace must mirror folder structure

preprocessing checks for Object superclass to inject reference counting into the class definition.
2nd pass is done to fix missing forward references when multiple files are used (also noted by https://github.com/xdave/pvala)




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
### Licences

LGPL3 - posixvala glib replacement (C) 2013 - pancake@nopcode.org
LPGL2 - other misc glib code (C) 1991 Free Software Foundation, Inc.

everything else copyright 2017 darkoverlordofdata - Apache 2.0 License
