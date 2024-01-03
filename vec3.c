/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:39:55 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/03 14:24:03 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Create a function vec_append which appends vector src to dst.*/
int	vec_append(t_vec *dst, t_vec *src)
{
	size_t	alloc_size;
	
	if (!dst || !src || !src->memory)
		return (-1);
	else if (!dst->memory)
		vec_new(dst, 1, dst->elem_size);
	alloc_size = dst->elem_size * dst->len + src->elem_size * src->len;
	if (dst->alloc_size < alloc_size)
		if (vec_resize(dst, (alloc_size * 2)) < 0)
			return (-1);
	ft_memmove((void *)&dst->memory[dst->elem_size * dst->len],
		src->memory, src->elem_size * src->len);
	dst->len += src->len;
	return (1);
}
/*Create a function vec_prepend which prepends vector src to dst.*/
int vec_prepend(t_vec *dst, t_vec *src)
{
	size_t	alloc_size;
	
	if (!dst || !src || !src->memory)
		return (-1);
	else if (!dst->memory)
		vec_new(dst, 1, dst->elem_size);
	alloc_size = dst->elem_size * dst->len + src->elem_size * src->len;
	if (dst->alloc_size < alloc_size)
		if (vec_resize(dst, (alloc_size * 2)) < 0)
			return (-1);
	ft_memmove(&dst->memory[src->elem_size * src->len],
		dst->memory, dst->elem_size * dst->len);
	ft_memmove(dst->memory, src->memory, src->elem_size * src->len);
	dst->len += src->len;
	return (1);
}


#include <assert.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
    t_vec   t1;
    t_vec   t2;
    int     base1[] = {1, 2, 3};
    int     base2[] = {4, 5, 6};
    int     expect[] = {4, 5, 6, 1, 2, 3};

    assert(vec_from(&t1, base1, 3, sizeof(int)) > 0);
    assert(vec_from(&t2, base2, 3, sizeof(int)) > 0);
    assert(vec_prepend(&t1, &t2) > 0);
    assert(memcmp(t1.memory, expect, sizeof(expect)) == 0);
    vec_free(&t1);
    vec_free(&t2);
    printf("test_vec_prepend successful!\n");
}
