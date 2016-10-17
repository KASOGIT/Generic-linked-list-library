/*
** elem.h for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myirc/src/list
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Sat May 21 20:01:43 2016 
** Last update Fri May 27 11:10:27 2016 
*/

#ifndef ELEM_H_
#define ELEM_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_elem
{
  void		*_data;
  struct s_elem	*_next;
  struct s_elem	*_prev;
  void		*(*data)(struct s_elem *this);
  struct s_elem	*(*next)(struct s_elem *this);
  struct s_elem	*(*prev)(struct s_elem *this);  
}		t_elem;

t_elem	*elem_create(void *data);
void	elem_destroy(t_elem *this);
void	elem_warning(t_elem *this,
		     const char *func,
		     const char *file,
		     int line);
void	elem_error(t_elem *this,
		   const char *func,
		   const char *file,
		   int line);
void	*elem_data(t_elem *this);
t_elem	*elem_next(t_elem *this);
t_elem	*elem_prev(t_elem *this);

#endif /* !ELEM_H_ */
