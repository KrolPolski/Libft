/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:59:03 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/03 16:51:18 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Create a function vec_reduce which takes as an argument a function 
f applied to each element in the vector. Function f takes acc as it's 
first argument thus we can reduce the elements in the vector into one 
element.*/
int	vec_reduce(void *acc, t_vec *src, void (*f) (void *, void *))
{
	size_t i;

	if (!src || !acc || !f)
		return (-1);
	i = 0;
	while (i < src->len)
	{
		f(acc, src->memory + (i * src->elem_size));
		i++;
	}
	return (1);
}
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void reduce_tester(void *acc, void *src)
{
    *(int *)acc += *(int *)src;
}

int main(void)
{
    t_vec   t1;
    int     base[] = {1, 2, 3, 4, 5};
    int     result = 0;

    assert(vec_from(&t1, base, 5, sizeof(int)) > 0);
    vec_reduce(&result, &t1, reduce_tester);
    assert(result == 15);
    vec_free(&t1);
    printf("test_vec_reduce successful!\n");
}