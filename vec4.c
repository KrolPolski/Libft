/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:59:03 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/03 18:07:22 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Create a function vec_reduce which takes as an argument a function 
f applied to each element in the vector. Function f takes acc as it's 
first argument thus we can reduce the elements in the vector into one 
element.*/
int	vec_reduce(void *acc, t_vec *src, void (*f) (void *, void *))
{
	size_t	i;

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

/*Create a function vec_sort which takes in a function f
 determining order and equality of the two elements passed 
 as parameters and thus sorting the array accordingly 
 from the smallest to the largest element.*/
void	vec_sort(t_vec *src, int (*f)(void *, void *))
{
	unsigned long	i;
	long			cmp_result;

	if (!src || !f)
		return ;
	i = 0;
	while (i < src->len - 1)
	{
		cmp_result = f(vec_get(src, i), vec_get(src, i + 1));
		ft_printf("%u \n", cmp_result);
		if (cmp_result > 0)
		{
			vec_insert(src, vec_get(src, i), src->len);
			vec_remove(src, i);
			i = 0;
		}
		else
			i++;
	}
}
