/*
** main.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myirc/src/list
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Sat May 28 00:59:06 2016 
** Last update Sat May 28 10:14:38 2016 
*/

#include <stdio.h>
#include "list.h"

void	display(void *arg)
{
  printf("value: %d\n", *((int *)arg));
}

int	pred(void *data, void *arg)
{
  if (*((int *)data) == *((int *)arg))
    return (1);
  return (0);
}

int	main()
{
  int	a = 1, b = 2, c = 3;

  t_list	*list = list_create();

  list->push_back(list, &a);
  list->push_back(list, &b);
  list->push_back(list, &c);

  list->for_each(list, &display);

  list->erase_by_elem(list, &a);
  list->erase_by_elem(list, &c);
  list->erase_by_elem(list, &b);

  list->push_back(list, &a);
  list->push_back(list, &b);
  list->push_back(list, &c);
  list->for_each(list, &display);

  void *elem = list->get_elem_by_pred_arg(list, &pred, &b);
  printf("elem: %d\n", *((int *)elem));
  
  list_destroy(list);
}
