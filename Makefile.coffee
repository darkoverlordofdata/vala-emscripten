module.exports =
	profile:		
		gobject: (data) ->
					return '.PHONY:'+""" build
C1=#{ data.valac }
FLAGS=#{ data.flags }
DEF=#{ data.defines }
DEP=#{ data.dependancies }
CODE=#{ data.code } 
OPT=#{ data.optimize }
INC=#{ data.include } 
LIB=#{ data.libraries }
RES=#{ data.resources }
EXP=#{ data.exporting }
OUT=#{ data.output }

SRC=#{ data.src }

build: clean  all 

all:
	cp -rf $(SRC) build
	$(C1) $(FLAGS) $(DEF) $(DEP) $(INC) $(LIB) $(OPT) $(RES) $(EXP) $(OUT) $(CODE)

clean:
	rm -rf build/$(SRC)

"""
		compact: (data) ->
					return '.PHONY:'+""" build
C1=#{ data.valac }
FLAGS=#{ data.flags }
DEF=#{ data.defines }
DEP=#{ data.dependancies }
CODE=#{ data.code } 

CC=#{ data.cc }
OPT=#{ data.optimize }
INC=#{ data.include } 
RES=#{ data.resources }
EXP=#{ data.exporting }
OUT=#{ data.output }
IR=#{ data.c_code }

SRC=#{ data.src }

build: clean  all 

all:
	cp -rf $(SRC) build
	tools/valac.coffee
	$(C1) -C --save-temps $(FLAGS) $(DEF) $(DEP) $(CODE)
	tools/emcc.coffee
	$(CC) $(INC) $(OPT) $(RES) $(EXP) $(OUT) $(IR)

emcc:
	$(CC) $(INC) $(OPT) $(RES) $(EXP) $(OUT) $(IR)

clean:
	rm -rf build/$(SRC)

"""
