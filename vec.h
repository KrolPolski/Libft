/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:22:48 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/03 10:25:27 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

typedef struct s_vec
{
	unsigned char	*memory;
	size_t			elem_size;
	size_t			alloc_size;
	size_t			len;
}	t_vec;
int			vec_new(t_vec *dst, size_t init_len, size_t elem_size);
void		vec_free(t_vec *src);
int			vec_from(t_vec *dst, void *src, size_t len, size_t elem_size);
int			vec_copy(t_vec *dst, t_vec *src);
int			vec_resize(t_vec *src, size_t target_size);
void		*vec_get(t_vec *src, size_t index);
int			vec_pop(void *dst, t_vec *src);
int			vec_insert(t_vec *dst, void *src, size_t index);
int			vec_remove(t_vec *src, size_t index);
#endif
