all:
	g++ -o game *.cpp -I/usr/include/SDL2 -lSDL2 -lSDL2_mixer
	#g++ -std=c++11 -o game *.cpp  -I/Users/gvynogra/.brew/Cellar/sdl2/2.0.9_1/include/sdl2 -L/Users/gvynogra/.brew/Cellar/sdl2/2.0.9_1/lib -lsdl2 -I/Users/gvynogra/.brew/Cellar/sdl2_mixer/2.0.4/include/sdl2 -L//Users/gvynogra/.brew/Cellar/sdl2_mixer/2.0.4/lib -lSDL2_mixer
# to find where brew installed lib : brew info sdl2
# brew install sdl2_mixer
