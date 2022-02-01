##
## EPITECH PROJECT, 2022
## vocab
## File description:
## Makefile
##

SRC =	src/main.cpp	\

OBJ	=	$(SRC:.cpp=.o)

NAME	=	Vocab

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) -lncurses -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	NAME all $(NAME0) clean fclean re