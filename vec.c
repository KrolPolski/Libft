/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:25:52 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/03 10:26:17 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Create a function vec_new which will take a pointer to a t_vec and allocate 
len * elem_size bytes in the buffer as well as initialize its length
and element size.*/
int	vec_new(t_vec *dst, size_t init_len, size_t elem_size)
{
	if (!dst || elem_size == 0)
		return (-1);
	dst->alloc_size = init_len * elem_size;
	dst->len = 0;
	dst->elem_size = elem_size;
	if (init_len == 0)
		dst->memory = NULL;
	else
	{
		dst->memory = malloc(dst->alloc_size);
		if (!dst->memory)
			return (-1);
	}
	return (1);
}

/* Create a function vec_free that frees the 
allocated resources in src and zeroes its fields.*/
void	vec_free(t_vec *src)
{
	free(src->memory);
	src->memory = NULL;
	src->alloc_size = 0;
	src->elem_size = 0;
	src->len = 0;
}

/*Create a function vec_from which takes in a pointer to some
 memory, which then will be copied over to the new vector.*/
int	vec_from(t_vec *dst, void *src, size_t len, size_t elem_size)
{
	if (!dst || !src || elem_size == 0)
		return (-1);
	else if (vec_new(dst, len, elem_size) < 0)
		return (-1);
	ft_memmove(dst->memory, src, dst->alloc_size);
	dst->len = len;
	return (1);
}

/* Create a function vec_copy. The copy 
function is very simple and will only copy at 
most as many bytes as are available in the dst vector */
int	vec_copy(t_vec *dst, t_vec *src)
{
	size_t	copy_size;

	if (!dst || !src)
		return (-1);
	if (!dst->memory)
		if (vec_new(dst, src->len, src->elem_size) < 0)
			return (-1);
	if (src->len * src->elem_size < dst->alloc_size)
		copy_size = src->len * src->elem_size;
	else
		copy_size = dst->alloc_size;
	if (!ft_memmove(dst->memory, src->memory, copy_size))
		return (-1);
	return (1);
}

/*Create a function vec_resize which will take in a target_size parameter 
and either shrink (destructively) or grow the vector to the target size, 
copying the old contents over to the new allocation.*/
int	vec_resize(t_vec *src, size_t target_size)
{
	unsigned char	*old_ptr;

	if (!src || target_size < 0)
		return (-1);
	old_ptr = src->memory;
	if (target_size >= src->alloc_size)
	{
		src->memory = malloc(target_size);
		if (!src->memory || !ft_memmove(src->memory, old_ptr, src->alloc_size))
			return (-1);
		free(old_ptr);
		src->alloc_size = target_size;
	}
	else
	{
		src->memory = malloc(target_size);
		if (!src->memory || !ft_memmove(src->memory, old_ptr, target_size))
			return (-1);
		free(old_ptr);
		src->alloc_size = target_size;
	}
	return (1);
}
