
#### performance
wow - as fast as desktop!.

0.000074
0.000096


#### notes
no data structs (list, dict, array are from libGee), only GList, struct and [].
however, libGee is implemented in Vala. check dova-core for tips on integrating my own no-g version of libGee
missing some string handling
no regex
no virtual or override
no interface
no abstract
no for..in Iterable requres GObject
no [Flags] enum

limited generics - only primitive types except for builtins (List)

Basically, anything that relies on GTypeInfo or GObject is broken. 
Other stuff might work, and might be fixable by suplying missing runtime 


### oop limitations
one class per file
namespace mirrors folder structure
subclases cannot declare instance members

extend pseudo class Object to trigger reference counting code injection 
otherwise explicitely declare [Compact] or extend an existing class.

to replace an interface, make a struct of delegates

### fixed

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

various list methods





Rebel Alliance logo By User:Tkgd2007 [Public domain], via Wikimedia Commons