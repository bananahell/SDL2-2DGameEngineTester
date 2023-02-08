#################################
##### Linux Makefile for SDL2 use
#################################

##### Compiler
COMPILER = g++
##### Remove directories
RMDIR = rm -rdf
##### Remove files
RM = rm -f

##### Automatic dependency creation
DEP_FLAGS = -M -MT $@ -MT $(BIN_PATH)/$(*F).o -MP -MF $@
##### Linked libraries
LIBS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lm
##### Include path
INC_PATHS = -I$(INC_PATH) -I$(INC_ENGINE_PATH)

##### Compile directives
FLAGS = -std=c++17 -Wall -pedantic -Wextra -Werror=init-self
##### Extra debugging directives
DFLAGS = -ggdb -O0 -DDEBUG -g
##### Extra release directives
RFLAGS = -O3 -mtune=native

INC_PATH = include
SRC_PATH = src
ENGINE_PATH = ../../MySDL2-2DEngine/code
INC_ENGINE_PATH = $(ENGINE_PATH)/include
SRC_ENGINE_PATH = $(ENGINE_PATH)/src
BIN_PATH = bin
DEP_PATH = dep
BIN_ENGINE_PATH = $(ENGINE_PATH)/bin
DEP_ENGINE_PATH = $(ENGINE_PATH)/dep

##### File list by type
CPP_FILES = $(wildcard $(SRC_PATH)/*.cpp)
INC_FILES = $(wildcard $(INC_PATH)/*.h)
FILE_NAMES = $(CPP_FILES:.cpp=) $(INC_FILES:.h=)
DEP_FILES = $(addprefix $(DEP_PATH)/,$(addsuffix .d,$(FILE_NAMES)))
OBJ_FILES = $(addprefix $(BIN_PATH)/,$(notdir $(CPP_FILES:.cpp=.o)))

##### Executable name
EXEC = game.out

.PHONY: release debug cppcheck clean folders help execute valgrind

##### General rule
all: $(EXEC)

##### Generates executable
$(EXEC): $(OBJ_FILES)
	@echo
	@echo ---------------- Compiling Engine ----------------
	make -C $(ENGINE_PATH)
	@echo --------------------------------------------------
	@echo
	cp $(ENGINE_PATH)/bin/*.o bin/
	@echo
	@echo --------------- Linking All Objects --------------
	make link
	@echo --------------------------------------------------
	@echo

link:
	$(COMPILER) -o $(EXEC) $(shell find $(BIN_PATH) -name '*.o') $(LIBS) $(FLAGS)

##### Generates object files
.PRECIOUS: $(BIN_PATH)/%.o
$(BIN_PATH)/%.o: $(DEP_PATH)/%.d | folders
	$(COMPILER) $(INC_PATHS) $(addprefix $(SRC_PATH)/,$(notdir $(<:.d=.cpp))) -c $(FLAGS) -o $@

##### Generates dependency files
.PRECIOUS: $(DEP_PATH)/%.d
$(DEP_PATH)/%.d: $(CPP_FILES) | folders
	$(COMPILER) $(INC_PATHS) $< $(DEP_FLAGS) $(FLAGS)

clean:
	-$(RMDIR) $(DEP_PATH)
	-$(RMDIR) $(BIN_PATH)
	-$(RMDIR) $(DEP_ENGINE_PATH)
	-$(RMDIR) $(BIN_ENGINE_PATH)
	-$(RM) $(EXEC)

execute:
	./$(EXEC)

##### Call for cppcheck
cppcheck:
	cppcheck --enable=all . $(ENGINE_PATH) -I$(INC_PATH) -I$(INC_ENGINE_PATH) --suppress=missingInclude --suppress=unusedFunction

##### Call for valgrind
valgrind:
	valgrind --leak-check=yes -s ./$(EXEC)

release: FLAGS += $(RFLAGS)
release: $(EXEC)

debug: FLAGS += $(DFLAGS)
debug: $(EXEC)

folders:
	@mkdir -p $(DEP_PATH) $(BIN_PATH) $(INC_PATH) $(SRC_PATH)

##### Debugging rules
print-% : ; @echo $* = $($*)

help:
	@echo Available commands
	@echo - release:  Builds release version
	@echo - debug:    Builds debug version
	@echo - clean:    Cleans generated files
	@echo - cppcheck: Uses cppcheck on compiled objects
	@echo - valgrind: Uses valgrind on linked programs
	@echo - execute:  Executes the game
	@echo - help:     Shows help
	@echo - folders:  Generates project directories

.SECONDEXPANSION:
-include $$(DEP_FILES)
