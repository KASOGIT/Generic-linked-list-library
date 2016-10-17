/*
** elem.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myirc/src/list
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Sat May 21 20:02:39 2016 
** Last update Fri May 27 21:28:52 2016 
*/

#include "elem.h"

static void	set_methods(t_elem *this)
{
  this->data = &elem_data;
  this->next = &elem_next;
  this->prev = &elem_prev;
}

t_elem		*elem_create(void *data)
{
  t_elem	*new_elem;

  new_elem = malloc(sizeof(t_elem));
  if (new_elem == NULL)
    elem_error(new_elem, "malloc", __FILE__, __LINE__);
  set_methods(new_elem);
  new_elem->_next = NULL;
  new_elem->_prev = NULL;
  new_elem->_data = data;
  return (new_elem);
}

void	elem_destroy(t_elem *this)
{
  if (this)
    {
      this->_next = NULL;
      this->_prev = NULL;
      this->_data = NULL;
      free(this);
    }
  else
    elem_warning(this, "elem_destroy", __FILE__, __LINE__);
}

void	elem_warning(__attribute__((unused))t_elem *this,
		     const char *func,
		     const char *file,
		     int line)
{
  fprintf(stderr, "Warning: file: %s, line: %d, func: %s\n",
	  file,
	  line,
	  func);
}

void	elem_error(t_elem *this,
		   const char *func,
		   const char *file,
		   int line)
{
    fprintf(stderr, "Error: file: %s, line: %d, func: %s\n",
	    file,
	    line,
	    func);
    elem_destroy(this);
    exit(EXIT_FAILURE);
}

void	*elem_data(t_elem *this)
{
  return (this->_data);
}

t_elem	*elem_next(t_elem *this)
{
  return (this->_next);
}

t_elem	*elem_prev(t_elem *this)
{
  return (this->_prev);
}
