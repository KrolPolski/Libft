/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:22:22 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/02 14:29:38 by rboudwin         ###   ########.fr       */
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
		return (vec_push(dst, src));
	if (dst->alloc_size <= dst->elem_size * dst->len)
		if (vec_resize(dst, (dst->alloc_size * 2)) < 0)
			return (-1);
	ft_memmove(vec_get(dst, index + 1),
		vec_get(dst, index), (dst->len - index) * dst->elem_size);
	ft_memcpy(vec_get(dst, index), src, dst->elem_size);
	dst->len++;
	return (1);
}

#include <assert.h>
#include <stdio.h>
#include <string.h>

/*int main(void)
{
	t_vec t1;
	int original[0, 1, 3, 4, 5];
	vec_from(t1, base, )
}*/
/*int vec_insert(t_vec *dst, void *src, size_t index)
{
	if (!dst || !src || index > dst->len)
		return (-1);
	else if (index == dst->len)
		return (vec_push(dst, src));
	if (dst->elem_size * dst->len >= dst->alloc_size)
		if (vec_resize(dst, (dst->alloc_size * 2) / dst->elem_size) < 0)
			return (-1);
	memmove(
		vec_get(dst, index + 1),
		vec_get(dst, index),
		(dst->len - index) * dst->elem_size);
	memcpy(
		vec_get(dst, index),
		src, dst->elem_size);
	dst->len++;
	return (1);
}*/
/*int main(void)
{
    t_vec   t1;
    int     base[] = {1, 2, 3, 4, 5};
    int     insert[] = {42, 666, 7};
    int     expect[] = {1, 42, 2, 3, 666, 4, 5, 7};

    assert(vec_from(&t1, base, 5, sizeof(int)) > 0);
	int i = 0;
	while(i < 5)
	{
		printf("%d, ", t1.memory[i++ * t1.elem_size]);
	}
	printf("\n");
	printf("About to insert %d\n", insert[0]);
    vec_insert(&t1, &insert[0], 1);
	i = 0;
	while(i < 6)
	{
		printf("%d, ", t1.memory[i++ * t1.elem_size]);
	}
	printf("\nAbout to insert %d\n", insert[1]);
    vec_insert(&t1, &insert[1], 4);
	i = 0;
	while(i < 7)
	{
		printf("%d, ", t1.memory[i++ * t1.elem_size]);
	}
	printf("\nAbout to insert %d\n", insert[2]);
    vec_insert(&t1, &insert[2], 7);
	i = 0;
	while(i < 8)
	{
		printf("%d, ", t1.memory[i++ * t1.elem_size]);
	}
   assert(memcmp(t1.memory, expect, sizeof(expect)) == 0);
   vec_free(&t1);
   printf("test_vec_insert successful!\n");
}*/
int main(void)
{
    t_vec   t1;
    int     base[] = {1, 2, 3, 4, 5};
    int     insert[] = {42, 666, 7};
    int     expect[] = {1, 42, 2, 3, 666, 4, 5, 7};

    assert(vec_from(&t1, base, 5, sizeof(int)) > 0);
    vec_insert(&t1, &insert[0], 1);
    vec_insert(&t1, &insert[1], 4);
    vec_insert(&t1, &insert[2], 7);
    assert(memcmp(t1.memory, expect, sizeof(expect)) == 0);
    vec_free(&t1);
    printf("test_vec_insert successful!\n");
}