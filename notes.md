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

Basically, anything that relies on GTypeInfo or GObject is broken. 
Other stuff might work, and should be fixable by suplying missing runtime 

For sanity, I'm preprocessing a class attribute [Pseudo] to provide reference counting.
post-process files are in build/src. classes need simple names - the name mangling in the custom
script isn't workin correctly for OverlyLongNamedClasses

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

convert explosion.png -implode .5 boom.png

convert boom.png -implode .1 star9.png
convert boom.png -implode .2 star8.png
convert boom.png -implode .3 star7.png
convert boom.png -implode .4 star6.png
convert boom.png -implode .5 star5.png
convert boom.png -implode .6 star4.png
convert boom.png -implode .7 star3.png
convert boom.png -implode .8 star2.png
convert boom.png -implode .9 star1.png

convert +append star*.png boom.png
convert +append star*.png particle.png



Rebel Alliance logo By User:Tkgd2007 [Public domain], via Wikimedia Commons