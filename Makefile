##
## Makefile for  in /home/kaso/Documents/rendu/PERSO/C/list
## 
## Made by 
## Login   <@epitech.net>
## 
## Started on  Mon Oct 17 02:38:27 2016 
## Last update Mon Oct 17 10:56:33 2016 
##

STATIC_LIB_NAME =	liblist.a

DYNAMIC_LIB_NAME =	liblist.so

CC =	gcc

RM =	rm -rf

CFLAGS	= -O2 -pipe -I./include/

SRC =	elem.c \
	list.c \

OBJ =	$(addprefix src/, $(SRC:.c=.o))

static: $(OBJ)
	ar -cvq $(STATIC_LIB_NAME) $(OBJ)
	ranlib $(STATIC_LIB_NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(STATIC_LIB_NAME)

re: fclean static

