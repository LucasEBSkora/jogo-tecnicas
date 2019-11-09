#OBJS specifies which files to compile as part of the project
OBJS =  *.cpp HasturEngine/*.cpp HasturEngine/Drawables/*.cpp HasturEngine/Events/*.cpp HasturEngine/Maps/*.cpp HasturEngine/TileSystem/*.cpp DescentIntoMadness/Entities/Enemies/*.cpp DescentIntoMadness/Entities/Projectiles/*.cpp DescentIntoMadness/Entities/Players/*.cpp DescentIntoMadness/States/Levels/*.cpp DescentIntoMadness/States/Menus/*.cpp DescentIntoMadness/States/*.cpp DescentIntoMadness/Tiles/*.cpp DescentIntoMadness/Tiles/TempleLevelTiles/*.cpp DescentIntoMadness/Tiles/CavernLevelTiles/*.cpp


#CC specifies which compiler we're using
CC = g++

#INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS =

#LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

#COMPILER_FLAGS specifies the additional compilation options we're using
COMPILER_FLAGS = -std=c++17 -Wall -Wextra -Wsign-conversion -pedantic -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wundef -Wno-unused -Wno-variadic-macros -Wno-parentheses -fdiagnostics-show-option  #-Weffc++

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS =

#OBJ_NAME specifies the name of our executable
OBJ_NAME = jogo

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
