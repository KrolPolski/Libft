/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:22:22 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/04 13:59:06 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Create a function vec_push which takes in a vector 
and a pointer to an element to be pushed to the end of the vector.*/
int	vec_push(t_vec *dst, void *src)
{
	if (!dst || !src)
		return (-1);
	if (!dst->memory)
		vec_new(dst, 1, dst->elem_size);
	if (dst->elem_size * dst->len >= dst->alloc_size)
		if (vec_resize(dst, dst->alloc_size * 2) < 1)
			return (-1);
	ft_memmove(&dst->memory[dst->elem_size * dst->len], src, dst->elem_size);
	dst->len++;
	return (1);
}

/*Create a function vec_pop which will remove the 
last element from the vector and copy it to dst.*/
int	vec_pop(void *dst, t_vec *src)
{
	if (!dst || !src)
		return (-1);
	else if
		(!src->memory || src->len == 0)
			return (0);
	ft_memmove(dst, vec_get(src, src->len - 1), src->elem_size);
	src->len--;
	return (1);
}

/* Create a function vec_get which returns an opaque 
handle to the element at index.*/

void	*vec_get(t_vec *src, size_t index)
{
	if (!src || !src->len || (!src->memory) || index >= src->len)
		return (NULL);
	return (&src->memory[src->elem_size * index]);
}

/*Create a function vec_insert which will insert a new 
element at any position in the vector without 
overwriting existing elements.*/

int	vec_insert(t_vec *dst, void *src, size_t index)
{
	if (!dst || !src || index > dst->len)
		return (-1);
	else if (index == dst->len)
	{
		ft_printf("We are just going to push");
		return (vec_push(dst, src));
	}
	if (dst->alloc_size <= dst->elem_size * dst->len)
		if (vec_resize(dst, (dst->alloc_size * 2)) < 0)
			return (-1);
	//problem is here. 
	ft_printf("new allocation is %d \n", dst->alloc_size);
	//so this line is having problems because it is trying to access a pointer for a place
	// that does not exist. because the second time there is only one element in the vector.
	ft_memmove(vec_get(dst, index) + dst->elem_size,
		vec_get(dst, index), (dst->len - index) * dst->elem_size);
	ft_memcpy(vec_get(dst, index), src, dst->elem_size);
	dst->len++;
	return (1);
}

/*Create a function vec_remove which will remove an element 
from any position in the vector without overwriting existing elements.*/
int	vec_remove(t_vec *src, size_t index)
{
	if (!src || index > src->len)
		return (-1);
	else if (index == src->len)
	{
		src->len--;
		return (1);
	}
	ft_memmove(vec_get(src, index), &src->memory[src->elem_size * (index + 1)],
		(src->len - index) * src->elem_size);
	src->len--;
	return (1);
}
