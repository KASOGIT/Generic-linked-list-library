/*
** list.h for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myirc/src/list
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Sat May 21 18:48:03 2016 
** Last update Sat May 28 13:35:51 2016 
*/

#ifndef LIST_H_
#define LIST_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "elem.h"

typedef struct	s_list
{
  t_elem	*_head;
  t_elem	*_back;
  int		_sz;
  t_elem	*(*begin)(struct s_list *this);
  t_elem	*(*end)(struct s_list *this);
  void		(*push_back)(struct s_list *this, void *data);
  void		(*push_front)(struct s_list *this, void *data);
  void		(*pop_back)(struct s_list *this);
  void		(*pop_front)(struct s_list *this);
  void		*(*front)(struct s_list *this);
  void		*(*back)(struct s_list *this);
  void		(*erase)(struct s_list *this, int pos);
  void		(*erase_by_elem)(struct s_list *this, void *elem);
  void		(*erase_by_elem_pred)(struct s_list *this,
				      int (*pred)(void *data, void *elem),
				      void *elem);
  int		(*empty)(struct s_list *this);
  int		(*size)(struct s_list *this);
  void		(*for_each)(struct s_list *this, void (*fun)(void *data));
  void		(*for_each_arg)(struct s_list *this,
				void (*fun)(void *data, void *arg),
				void *arg);
  void		*(*max)(struct s_list *this,
			void *(*func_comp)(void *d1, void *d2));
  int		(*any_of)(struct s_list *this,
			  int (*pred)(void *d1, void *d2),
			  void *to_cmp);
  void		*(*get_elem)(struct s_list *this, int pos);
  void		*(*get_elem_by_pred)(struct s_list *this, int (*pred)(void *data));
  void		*(*get_elem_by_pred_arg)(struct s_list *this,
					 int (*pred)(void *data, void *arg),
					 void *arg);
}		t_list;

t_list	*list_create();
void	list_destroy(t_list *this);
void	list_pop_front(t_list *this);
void	list_pop_back(t_list *this);
void	list_push_back(t_list *this, void *data);
void	list_push_front(t_list *this, void *data);
void	*list_front(t_list *this);
void	*list_back(t_list *this);
void	list_erase(t_list *this, int pos);
void	list_erase_by_elem(t_list *this, void *elem);
void	list_erase_by_elem_pred(t_list *this,
				int (*pred)(void *data, void *elem),
				void *elem);
int	list_empty(t_list *this);
int	list_size(t_list *this);
void	list_for_each(t_list *this, void (*fun)(void *data));
void	list_for_each_arg(t_list *this,
			  void (*fun)(void *data, void *arg),
			  void *arg);
int	list_any_of(t_list *this,
		    int (*pred)(void *d1, void *d2),
		    void *to_cmp);
t_elem	*list_begin(t_list *this);
t_elem	*list_end(t_list *this);
void	*list_max(t_list *this, void *(*func_comp)(void *d1, void *d2));
void	*list_get_elem(t_list *this, int pos);
void	*list_get_elem_by_pred(t_list *list, int (*pred)(void *data));
void	*list_get_elem_by_pred_arg(t_list *list,
				   int (*pred)(void *data, void *arg),
				   void *arg);

#endif /* !LIST_H_ */
