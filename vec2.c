/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:22:22 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/02 11:48:46 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vec.h"
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

/* Create a function vec_get which returns an opaque handle to the element at index.*/

void	*vec_get(t_vec *src, size_t index)
{
	if (!src || !src->len || (!src->memory) || index >= src->len)
		return (NULL);
	return (&src->memory[src->elem_size * index]);

}

#include <assert.h>
#include <stdio.h>
#include <string.h>



/*int main(void)
{
    t_vec   t1;
    int     base[] = {1, 2, 3, 4, 5};
    int     *expect;

    assert(vec_new(&t1, 1, sizeof(int)) > 0);
    vec_push(&t1, &base[1]);
    vec_push(&t1, &base[3]);
    expect = vec_get(&t1, 0);
    assert(*expect == 2);
    expect = vec_get(&t1, 1);
    assert(*expect == 4);
    assert(t1.len == 2);
    vec_free(&t1);
    printf("test_vec_get successful!\n");
}*/
int main(void)
{
    t_vec   t1;
    int     base[] = {1, 2, 3, 4, 5};
    int     expect = 0;

    assert(vec_new(&t1, 1, sizeof(int)) > 0);
    vec_push(&t1, &base[1]);
    vec_push(&t1, &base[3]);
    vec_pop(&expect, &t1);
    assert(expect == 4);
    vec_pop(&expect, &t1);
    assert(expect == 2);
    assert(t1.len == 0);
    vec_free(&t1);
    printf("test_vec_pop successful!\n");
}
