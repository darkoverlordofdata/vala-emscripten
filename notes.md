
#### performance
wow - as fast as desktop!.

#### notes
vala syntax works better:
    readonly properties
    can use _ in variable name 1st position
    

### oop limitations

Compact classes are limited:

no regex
no virtual or override
no interface
no abstract
no [Flags] enum

Basically, anything that relies on GTypeInfo or GObject is broken. 
Other stuff might work, and might be fixable by suplying missing runtime 

one class per file
namespace mirrors folder structure
subclases cannot declare instance members
generics are limited to builtins (List, HashTable)

extend pseudo class Object to trigger reference counting code injection 
otherwise explicitely declare [Compact] or extend an existing class.

to replace an interface, make a struct of delegates

### fixed
basically, I need to fullfill the GIDL: https://github.com/GNOME/vala/blob/master/vapi/glib-2.0.vapi
array concat:

    var x = array of int[0]
    x += 42

string funcs (ascii only):

    .up()
    .down()
    .reverse()

reference counting
string comparison
string.join
string.joinv
string.split

GList
SList
Queue
HashTable




Rebel Alliance logo By User:Tkgd2007 [Public domain], via Wikimedia Commons