#### notes
no data structs (list, dict, array are from libGee), only GList, struct and [].
however, libGee is implemented in Vala. check dova-core for tips on integrating my own no-g version of libGee
missing some string handling - regex based
no virtual or override
no interface
no abstract
no for..in Iterable requres GObject
no [Flags] enum
subclasses, like derived structs, cannot declare instance members
limited generics - only primitive types except for builtins (List)
many string methods lack runtime support, and crash.

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

varoius list methods



Rebel Alliance logo By User:Tkgd2007 [Public domain], via Wikimedia Commons