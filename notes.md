
## performance
wow - as fast as desktop!.

## oop limitations
Compact classes are limited:

no regex
no virtual or override
no interface
no abstract
no [Flags] enum
subclases cannot declare instance members

it's unfortunate, but genie doesn't work as well, it has more dependancies on GObject,
so these are also broken:

* no Gee 
* no Properties
* no underscore in first char

Vala still has lambdas.

## workarounds
to replace interface, make a struct of delegates

## notes

preprocessing checks for Object superclass to injec reference counting code
otherwise explicitely declare [Compact] or extend an existing class.

one class per file
namespace must mirror folder structure

## missing runtinm

Basically, anything that relies on GTypeInfo or GObject is broken. 
Other stuff might work, and might be fixable by adding GLib modules back in.

basically, I need to supply code to satisfy this spec: https://github.com/GNOME/vala/blob/master/vapi/glib-2.0.vapi

## added back in

* GList
* SList
* Queue
* HashTable

## fixed

array concat:

    var x = array of int[0]
    x += 42

Some string stuff:
string funcs (ascii only):

    .up()
    .down()
    .reverse()

string comparison
string.join
string.joinv
string.split





Rebel Alliance logo By User:Tkgd2007 [Public domain], via Wikimedia Commons