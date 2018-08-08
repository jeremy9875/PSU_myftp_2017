##
## EPITECH PROJECT, 2018
## makefile
## File description:
## 
##

NAME	=	server

SRC	=	./src/main.c		\
		./src/server.c		\
		./src/connection.c	\
		./src/movedirectory.c	\
		./src/command.c		\
		./src/last_command.c	\

OBJ	=	$(SRC:.c=.o)

#CFLAGS	+=	-Wall -Wextra -Werror

CPPFLAGS +=	-I ./include/

CC	=	gcc

RM	=	rm -rf

all:	$(NAME)

$(NAME) : $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(CPPFLAGS) $(OBJ)
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
