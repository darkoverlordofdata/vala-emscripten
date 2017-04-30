## <img title="A New Hope" src="https://upload.wikimedia.org/wikipedia/commons/2/2a/Rebel_Alliance_logo.svg" width="64">

Compile vala/genie to wasm using emscripten. 
Initially, this works with classic (stable) SDL. 




## status
work in progress
uses https://github.com/radare/posixvala as a starting point. 

it appears that vala treats glib as it's builtin runtime library, so for example instead of calling strdup, it calls g_strdup which calls strdup. That is pretty much how proprietary languages enforce vendor lockin. So much for moral superiority.

In any case, the fix is in some cases to copy back in the missing glib functions as they break. I don't see a license conflict in doing so, as it is done to support vala, a product covered by the same license as glib. 

## licenses


LGPL3 - posixvala glib replacement (C) 2013 - pancake@nopcode.org
LPGL2 - some misc functions from glib (C) 1991 Free Software Foundation, Inc.

Remainder of this work copyright 2017 darkoverlordofdata - Apache 2.0 License
