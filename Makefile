all:
	#g++ -o game *.cpp -lSDL2
	g++ -std=c++11 -o game *.cpp  -I/Users/gvynogra/.brew/Cellar/sdl2/2.0.9_1/include -L/Users/gvynogra/.brew/Cellar/sdl2/2.0.9_1/lib -lsdl2
# to find where brew installed lib : brew info sdl2