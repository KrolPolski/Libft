/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:25:52 by rboudwin          #+#    #+#             */
/*   Updated: 2023/12/29 10:53:19 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "vec.h"
/*Create a function vec_new which will take a pointer to a t_vec and allocate 
len * elem_size bytes in the buffer as well as initialize its length
and element size.*/
int vec_new(t_vec *dst, size_t init_len, size_t elem_size)
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
/* Create a function vec_free that frees the allocated resources in src and zeroes its fields.*/
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
int vec_from(t_vec *dst, void *src, size_t len, size_t elem_size)
{
	if (!dst || !src || elem_size == 0)
		return (-1);
	else if (vec_new(dst, len, elem_size) < 0)
		return (-1);
	dst->memory = ft_memmove(dst->memory, src, dst->alloc_size);
	if (!dst->memory)
		return (-1);
	dst->len = len;
	return(1);
}

#include <assert.h>
#include <stdio.h>
#include <string.h>
int main(void)
{
    t_vec   t1;
    int     base[] = {1, 2, 3, 4, 5};

    assert(vec_from(&t1, base, 5, sizeof(int)) > 0);
    assert(memcmp(t1.memory, base, sizeof(base)) == 0);
    vec_free(&t1);
    printf("test_vec_from successful!\n");
}

