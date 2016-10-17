##
## Makefile for  in /home/kaso/Documents/rendu/PERSO/GITHUB/Generic-linked-list-library/example
## 
## Made by 
## Login   <@epitech.net>
## 
## Started on  Mon Oct 17 10:57:22 2016 
## Last update Mon Oct 17 11:05:55 2016 
##

NAME	= test

CC	= gcc

RM	= rm -rf

SRC	= main.c \

OBJ	= $(SRC:.c=.o)

CFLAGS	= -O2 -pipe -I./../include/

LDFLAGS	= -L./../liblist.a

$(NAME): $(OBJ)
	 $(CC) -o $(NAME) $(LDFLAGS) $(OBJ)

all: $(NAME)

clean:
	 $(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
