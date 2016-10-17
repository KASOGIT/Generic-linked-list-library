/*
** list.c for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_myirc/src/list
** 
** Made by 
** Login   <@epitech.net>
** 
** Started on  Sat May 21 20:19:26 2016 
** Last update Sat May 28 18:51:47 2016 
*/

#include "list.h"

void    list_warning(__attribute__((unused))t_list *this,
		     const char *func,
		     const char *file,
		     int line)
{
  fprintf(stderr, "Warning: file: %s, line: %d, func: %s\n",
	  file,
	  line,
	  func);
}

void    list_error(t_list *this,
		   const char *func,
		   const char *file,
		   int line)
{
  fprintf(stderr, "Error: file: %s, line: %d, func: %s\n",
	  file,
	  line,
	  func);
  list_destroy(this);
  exit(EXIT_FAILURE);
}


void	list_set_methods(t_list *this)
{
  this->pop_back = &list_pop_back;
  this->pop_front = &list_pop_front;
  this->push_back = &list_push_back;
  this->push_front = &list_push_front;
  this->erase = &list_erase;
  this->erase_by_elem = &list_erase_by_elem;
  this->erase_by_elem_pred = &list_erase_by_elem_pred;  
  this->empty = &list_empty;
  this->size = &list_size;
  this->for_each = &list_for_each;
  this->for_each_arg = &list_for_each_arg;  
  this->front = &list_front;
  this->back = &list_back;
  this->begin = &list_begin;
  this->end = &list_end;
  this->max = &list_max;
  this->get_elem = &list_get_elem;
  this->get_elem_by_pred = &list_get_elem_by_pred;
  this->get_elem_by_pred_arg = &list_get_elem_by_pred_arg;
  this->any_of = &list_any_of;
}

static void	list_init(t_list *this)
{
  this->_sz = 0;
  this->_head = NULL;
  this->_back = NULL;  
}

t_list		*list_create()
{
  t_list	*new_list;

  new_list = malloc(sizeof(t_list));
  if (new_list == NULL)
    list_error(new_list, "malloc", __FILE__, __LINE__);
  list_init(new_list);
  list_set_methods(new_list);
  return (new_list);
}

void		list_destroy(t_list *this)
{
  t_elem	*tmp;
  t_elem	*to_del;

  if (this && this->_sz > 0)
    {
      tmp = this->_head;
      while (tmp != this->_back)
	{
	  to_del = tmp;
	  tmp = tmp->_next;
	  elem_destroy(to_del);
	}
      elem_destroy(tmp);
      free(this);
    }
  else
    list_warning(this, "list_destroy", __FILE__, __LINE__);
}

void		list_push_back(t_list *this, void *data)
{
  t_elem	*new_elem;

  new_elem = elem_create(data);
  if (this && this->_sz == 0)
    {
      this->_head = new_elem;
      this->_back = new_elem;
      new_elem->_next = new_elem;
      new_elem->_prev = new_elem;
      this->_sz++;
    }
  else if (this)
    {
      new_elem->_next = this->_head;
      new_elem->_prev = this->_back;
      this->_back->_next = new_elem;
      this->_head->_prev = new_elem;
      this->_back = new_elem;
      this->_sz++;
    }
  else
    list_warning(this, "push_back", __FILE__, __LINE__);
}

void		list_push_front(t_list *this, void *data)
{
  t_elem	*new_elem;

  new_elem = elem_create(data);
  if (this && this->_sz == 0)
    {
      this->_head = new_elem;
      this->_back = new_elem;
      new_elem->_next = new_elem;
      new_elem->_prev = new_elem;
      this->_sz++;
    }
  else if (this)
    {
      new_elem->_next = this->_head;
      new_elem->_prev = this->_back;
      this->_head->_prev = new_elem;
      this->_back->_next = new_elem;
      this->_head = new_elem;
      this->_sz++;
    }
  else
    list_warning(this, "push_front", __FILE__, __LINE__);
}

void		list_erase(t_list *this, int pos)
{
  t_elem	*tmp;

  if (this && this->_head)
    {
      tmp = this->_head;
      while (pos && tmp != this->_back)
	{
	  tmp = tmp->_next;
	  pos--;
	}
      if (pos == 0)
	{
	  if (tmp == this->_back)
	    this->pop_back(this);
	  else if (tmp == this->_head)
	    this->pop_front(this);
	  else
	    {
	      tmp->_prev->_next = tmp->_next;
	      tmp->_next->_prev = tmp->_prev;
	      elem_destroy(tmp);
	      this->_sz--;
	    }
	}
      else
	list_warning(this, "erase", __FILE__, __LINE__);
    }
  else
    list_warning(this, "erase", __FILE__, __LINE__);
}

void		list_erase_by_elem(t_list *this, void *elem)
{
  t_elem	*tmp;

  if (this && this->_head)
    {
      tmp = this->_head;
      while (tmp->_data != elem && tmp != this->_back)
	tmp = tmp->_next;
      if (tmp->_data == elem)
	{
	  if (tmp == this->_back)
	    this->pop_back(this);
	  else if (tmp == this->_head)
	    this->pop_front(this);
	  else
	    {
	      tmp->_prev->_next = tmp->_next;
	      tmp->_next->_prev = tmp->_prev;
	      elem_destroy(tmp);
	      this->_sz--;
	    }
	}
      else
	list_warning(this, "erase_by_elem", __FILE__, __LINE__);
    }
  else
    list_warning(this, "erase_by_elem", __FILE__, __LINE__);
}

void            list_erase_by_elem_pred(t_list *this,
					int (*pred)(void *data, void *elem),
					void *elem)
{
  t_elem        *tmp;
  int           pos;

  if (this && this->_head)
    {
      pos = 0;
      tmp = this->_head;
      while (tmp != this->_back)
	{
	  if ((*pred)(tmp->data(tmp), elem))
	    {
	      if (pos == this->size(this) - 1)
		this->pop_back(this);
	      else if (pos == 0)
		this->pop_front(this);
	      else
		{
		  tmp->_prev->_next = tmp->_next;
		  tmp->_next->_prev = tmp->_prev;
		  elem_destroy(tmp);
		  this->_sz--;
		}
	    }
	  tmp = tmp->_next;
	  pos++;
	}
      if ((*pred)(tmp->data(tmp), elem))
	{
	  if (pos == this->size(this) - 1)
	    this->pop_back(this);
	}
    }
  else
    list_warning(this, "erase_by_elem", __FILE__, __LINE__);
}

void		list_pop_back(t_list *this)
{
  t_elem	*to_del;

  if (this && this->_sz > 1)
    {
      to_del = this->_back;
      this->_back->_prev->_next = this->_head;
      this->_head->_prev = this->_back->_prev;
      this->_back = this->_back->_prev;
      elem_destroy(to_del);
      this->_sz--;
    }
  else if (this && this->_sz == 1)
    {
      this->_sz = 0;
      to_del = this->_back;      
      elem_destroy(to_del);
      list_init(this);
    }
  else
    list_warning(this, "pop_back", __FILE__, __LINE__);
}

void		list_pop_front(t_list *this)
{
  t_elem	*to_del;

  if (this && this->_sz > 1)
    {
      to_del = this->_head;
      this->_back->_next = this->_head->_next;
      this->_head->_next->_prev = this->_back;
      this->_head = this->_head->_next;
      elem_destroy(to_del);
      this->_sz--;
    }
  else if (this && this->_sz == 1)
    {
      this->_sz = 0;
      to_del = this->_head;
      elem_destroy(to_del);
      list_init(this);
    }
  else
    list_warning(this, "pop_front", __FILE__, __LINE__);    
}

int	list_empty(t_list *this)
{
  if (this)
    {
      if (this->_sz == 0)
	return (1);
    }
  else
    list_warning(this, "empty", __FILE__, __LINE__);
  return (0);
}

int	list_size(t_list *this)
{
  if (this)
    return (this->_sz);
  else
    list_warning(this, "size", __FILE__, __LINE__);
  return (0);
}

void		list_for_each(t_list *this, void (*fun)(void *data))
{
  t_elem	*tmp;

  if (this && this->_sz > 0)
    {
      tmp = this->_head;
      while (tmp != this->_back)
	{
	  (*fun)(tmp->_data);
	  tmp = tmp->_next;
	}
      (*fun)(tmp->_data);
    }
  else
    list_warning(this, "for_each", __FILE__, __LINE__);
}


void		list_for_each_arg(t_list *this,
				  void (*fun)(void *data, void *arg),
				  void *arg)
{
  t_elem	*tmp;

  if (this && this->_sz > 0)
    {
      tmp = this->_head;
      while (tmp != this->_back)
	{
	  (*fun)(tmp->_data, arg);
	  tmp = tmp->_next;
	}
      (*fun)(tmp->_data, arg);
    }
  else
    list_warning(this, "for_each_arg", __FILE__, __LINE__);
}

void	*list_front(t_list *this)
{
  if (this && this->_head)
    return (this->_head->_data);
  else
    list_warning(this, "front", __FILE__, __LINE__);
  return (NULL);
}

void	*list_back(t_list *this)
{
  if (this && this->_back)
    return (this->_back->_data);
  else
    list_warning(this, "back", __FILE__, __LINE__);
  return (NULL);
}

t_elem	*list_begin(t_list *this)
{
  if (this && this->_head)
    {
      return (this->_head);
    }
  else
    list_warning(this, "begin", __FILE__, __LINE__);
  return (NULL);
}

t_elem	*list_end(t_list *this)
{
  if (this && this->_back)
    {
      return (this->_back);
    }
  else
    list_warning(this, "end", __FILE__, __LINE__);
  return (NULL);
}

void		*list_max(t_list *this, void *(*func_comp)(void *d1, void *d2))
{
  t_elem	*tmp;
  void		*max;

  if (this && this->_sz > 1)
    {
      tmp = this->begin(this)->_next;
      max = this->front(this);
      while (tmp != this->end(this))
	{
	  max = (*func_comp)(max, tmp->_data);
	  tmp = tmp->_next;
	}
      max = (*func_comp)(max, tmp->_data);
      return (max);
    }
  else if (this && this->_sz == 1)
    {
      return (this->front(this));
    }
  else
    list_warning(this, "max", __FILE__, __LINE__);
  return (NULL);
}

void		*list_get_elem(t_list *this, int pos)
{
  t_elem	*tmp;
  
  if (this && this->_head)
    {
      tmp = this->begin(this);
      while (pos && tmp != this->end(this))
	{
	  tmp = tmp->_next;
	  pos--;
	}
      if (pos == 0)
	{
	  return (tmp->_data);
	}
    }
  list_warning(this, "get_elem", __FILE__, __LINE__);
  return (NULL);
}

void		*list_get_elem_by_pred(t_list *this, int (*pred)(void *data))
{
  t_elem	*tmp;
  
  if (this && this->_head)
    {
      tmp = this->begin(this);
      while (tmp != this->end(this))
	{
	  if ((*pred)(tmp->_data))
	    return (tmp->_data);
	  tmp = tmp->_next;
	}
      if ((*pred)(tmp->_data))
	return (tmp->_data);      
    }
  list_warning(this, "get_elem_by_pred", __FILE__, __LINE__);
  return (NULL);
}

void		*list_get_elem_by_pred_arg(t_list *this,
					   int (*pred)(void *data, void *arg),
					   void *arg)
{
  t_elem	*tmp;
  
  if (this && this->_head)
    {
      tmp = this->begin(this);
      while (tmp != this->end(this))
	{
	  if ((*pred)(tmp->_data, arg))
	    return (tmp->_data);
	  tmp = tmp->_next;
	}
      if ((*pred)(tmp->_data, arg))
	return (tmp->_data);      
    }
  list_warning(this, "get_elem_by_pred_arg", __FILE__, __LINE__);
  return (NULL);
}

int		list_any_of(t_list *this,
			    int (*pred)(void *d1, void *d2),
			    void *to_cmp)
{
  t_elem	*tmp;

  if (this && this->_head)
    {
      tmp = this->begin(this);
      while (tmp != this->end(this))
	{
	  if ((*pred)(to_cmp, tmp->_data))
	    return (1);
	  tmp = tmp->_next;
	}
      if ((*pred)(to_cmp, tmp->_data))
	return (1);
      return (0);
    }
  list_warning(this, "any_of", __FILE__, __LINE__);
  return (0);
}
