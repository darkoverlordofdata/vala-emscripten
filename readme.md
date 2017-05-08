# vala-emscripten

* Compile vala/genie with emscripten. 
* Works with SDL2. 
* Both vala and genie
inspired by https://github.com/radare/posixvala 


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

LPGL2 - misc glib cut and psted code (C) 1991 Free Software Foundation, Inc.
LGPL3 - posixvala glib replacement (C) 2013 - pancake@nopcode.org
Remainder of this work copyright 2017 darkoverlordofdata - Apache 2.0 License
