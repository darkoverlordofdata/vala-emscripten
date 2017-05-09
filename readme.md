# vala-emscripten

* Compile vala/genie with emscripten. 
* Works with SDL2. 
* Both vala and genie, but vala has fewer limitations.

Vala compiles to C, so it can target emscripten. The problem is, there is no GLib, or GObject.

using https://github.com/radare/posixvala to show the way, we can hack parts of GLib back to life.


## performance
wow - as fast as desktop!

## oop limitations
Compact classes are limited:

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

preprocessing checks for Object superclass to inject reference counting into the class definition.

one class per file
namespace must mirror folder structure




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
