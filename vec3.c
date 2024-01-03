/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:39:55 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/03 14:59:06 by rboudwin         ###   ########.fr       */
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

/*Create a function vec_iter which takes as an 
argument a function f applied to each element in the vector.*/
void	vec_iter(t_vec *src, void (*f) (void *))
{
	size_t i;

	if (src == NULL || f == NULL)
		return ;
	i = 0;
	while (i < src->len)
	{
		f(src->memory + (i * src->elem_size));
		i++;
	}
}

/*Create a function vec_map which takes as an argument a function
 f applied to a copy of each element in the vector. 
 The copied element will be added to vector dst.*/

void vec_map(t_vec *dst, t_vec *src, void (*f) (void *))
{
	size_t i;

	if (!src || !dst || !f)
		return ;
	i = 0;
	if (vec_from(dst, src->memory, src->len, src->elem_size) < 0)
		return ;
	while (i < dst->len)
	{
		ft_printf("Before: %d\n", (int)dst->memory[i * dst->elem_size]);
		f(&dst->memory[(i * dst->elem_size)]);
		ft_printf("After: %d\n", dst->memory[i * dst->elem_size]);
		i++;
	}
}


#include <assert.h>
#include <stdio.h>
#include <string.h>

void map_tester(void *src)
{
    *(int *)src += 1;
}

int main(void)
{
    t_vec   t1;
    t_vec   t2;
    int     base[] = {1, 2, 3, 4, 5};
    int     expect[] = {2, 3, 4, 5, 6};

    assert(vec_from(&t1, base, 5, sizeof(int)) > 0);
    assert(vec_new(&t2, 5, sizeof(int)) > 0);
	vec_map(&t2, &t1, map_tester);
    assert(memcmp(t2.memory, expect, sizeof(expect)) == 0);
    vec_free(&t1);
    vec_free(&t2);
    printf("test_vec_map successful!\n");
}