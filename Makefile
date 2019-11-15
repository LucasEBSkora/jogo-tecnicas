#OBJS specifies which files to compile as part of the project
OBJS =  *.cpp Entities/*.cpp Entities/Enemies/*.cpp Entities/Players/*.cpp Entities/Projectiles/*.cpp Levels/*.cpp Lists/*.cpp Mementos/*.cpp Menus/*.cpp TileSystem/*.cpp TileSystem/Tiles/*.cpp TileSystem/Tiles/CavernLevelTiles/*.cpp TileSystem/Tiles/TempleLevelTiles/*.cpp


#CC specifies which compiler we're using
CC = g++

#INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = `pkg-config --cflags sfml-all`

#LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS = `pkg-config --libs sfml-all`

#COMPILER_FLAGS specifies the additional compilation options we're using
COMPILER_FLAGS = -g -std=c++17 -Wall -Wextra -Wsign-conversion -pedantic -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wundef -Wno-unused -Wno-variadic-macros -Wno-parentheses -fdiagnostics-show-option  #-Weffc++

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS =

#OBJ_NAME specifies the name of our executable
OBJ_NAME = jogo

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
