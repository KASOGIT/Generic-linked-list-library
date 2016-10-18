##
## Makefile for  in /home/kaso/Documents/rendu/PERSO/C/list
## 
## Made by 
## Login   <@epitech.net>
## 
## Started on  Mon Oct 17 02:38:27 2016 
## Last update Tue Oct 18 15:22:25 2016 
##

STATIC_LIB_NAME =	liblist.a

SHARED_LIB_NAME =	liblist.so

CC =	gcc

RM =	rm -rf

FLAGS	= -O2 -pipe -I./include/

#STATIC_CFLAGS	= 

SHARED_CFLAGS	= -fPIC

SHARED_LDFLAGS	= -shared

SRC =	./src/elem.c \
	./src/list.c \

OBJ	= ./elem.o \
	  ./list.o \

static:
	$(CC) $(FLAGS) -c $(SRC)
	ar -cvq $(STATIC_LIB_NAME) $(OBJ)
	ranlib $(STATIC_LIB_NAME)

shared:
	$(CC) $(FLAGS) -c $(SHARED_CFLAGS) $(SRC)
	$(CC) -o $(SHARED_LIB_NAME) $(SHARED_LDFLAGS) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(STATIC_LIB_NAME)
	$(RM) $(SHARED_LIB_NAME)

re: fclean static

