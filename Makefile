##
## EPITECH PROJECT, 2019
## my_defender
## File description:
## Makefile
##

SRC	=	main.c\
		lib/my_lib.c\
		src/useful_csfml_funct.c\
		src/useful_funct.c\
		src/close.c\
		src/menu_buttons.c\
		src/defender.c\
		src/create_interface.c\
		src/create_buildings.c\
		src/init_enemies.c\
		src/menu.c\
		src/move_map.c\
		src/mouse_col.c\
		src/error_messages.c\
		src/pause.c\
		src/add_turret.c\
		src/castle_life.c\
		src/set_score_money.c\
		src/drag_and_drop.c\
		src/destroy_turret.c\
		src/turret_position.c\
		src/enemy_waves.c\
		src/move_archer.c\
		src/move_paladin.c\
		src/display_screen.c\
		src/free_all.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_defender

FLAGS	=	-W -Wall -Wextra

CFLAGS	=	-Iinclude

GRAPHIC	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CC	=	gcc

RM	=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
		@$(CC) $(CFLAGS) $(GRAPHIC) -o $(NAME) $(OBJ)

debug:
	@$(CC) $(SRC) -g3 $(FLAGS) $(CFLAGS) $(GRAPHIC) -o $(NAME)
	valgrind ./$(NAME) 720 480

clean :
	@$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all	clean	fclean	re
