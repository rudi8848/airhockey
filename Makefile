NAME	=	game
SRCS	=	App.cpp \
			App_onInit.cpp \
			App_onLoop.cpp \
			App_onQuit.cpp \
			App_onRender.cpp \
			App_onStart.cpp \
			App_updateState.cpp \
			Enemy.cpp \
			Event.cpp \
			functions.cpp \
			Game.cpp \
			InitError.cpp \
			main.cpp \
			Match.cpp \
			Menu.cpp \
			Player.cpp \
			Puck.cpp \
			Room.cpp \
			Surface.cpp 

HDRS	=	App.hpp	\
			defines.hpp \
			Enemy.hpp \
			Event.hpp \
			Game.hpp \
			InitError.hpp	\
			Match.hpp	\
			Menu.hpp	\
			Player.hpp	\
			Puck.hpp	\
			Room.hpp	\
			Surface.hpp	

CC		=	g++

OBJS	=	$(SRCS:.cpp=.o)


#	for Linux
#CFLAGS	=	-lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf

#	for Mac Os
CFLAGS	=	-L${HOME}/.brew/Cellar/sdl2/2.0.9_1/lib -L${HOME}/.brew/Cellar/sdl2_mixer/2.0.4/lib -L${HOME}/.brew/Cellar/sdl2_image/2.0.4/lib -L${HOME}/.brew/Cellar/sdl2_ttf/2.0.15/lib -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf

#	for Linux
#INCL 	=	-I/usr/include/SDL2

#	for Mac Os
INCL 	=	-I${HOME}/.brew/Cellar/sdl2/2.0.9_1/include/sdl2 -I${HOME}/.brew/Cellar/sdl2_ttf/2.0.15/include/SDL2 -I${HOME}/.brew/Cellar/sdl2_mixer/2.0.4/include/SDL2 -I${HOME}/.brew/Cellar/sdl2_image/2.0.4/include/SDL2


all:		$(NAME)

$(NAME):	$(OBJS) $(HDRS)
			$(CC) -o $(NAME) $(OBJS) $(INCL) $(CFLAGS)

%.o:		%.cpp
			$(CC)  $(INCL) $(CFLAGS) -o $@ -c $<

clean:
			/bin/rm -f $(OBJS)

fclean:		clean
			/bin/rm -f $(NAME)

re:			fclean all

.PHONY:	clean fclean all re



#all:
#	g++ -o game -Wall -Wextra -Werror *.cpp -I/usr/include/SDL2 -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf
	#g++ -std=c++11 -o game *.cpp  -I/Users/gvynogra/.brew/Cellar/sdl2/2.0.9_1/include/sdl2 -L/Users/gvynogra/.brew/Cellar/sdl2/2.0.9_1/lib -lsdl2 -I/Users/gvynogra/.brew/Cellar/sdl2_mixer/2.0.4/include/sdl2 -L//Users/gvynogra/.brew/Cellar/sdl2_mixer/2.0.4/lib -lSDL2_mixer
# to find where brew installed lib : brew info sdl2
# brew install sdl2, sdl2_mixer, sdl2_image, sdl2_ttf 
