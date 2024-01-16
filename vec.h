/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:22:48 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/16 09:39:40 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H
# define TRUE 1
# define FALSE 0

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
int			vec_push(t_vec *dst, void *src);
int			vec_pop(void *dst, t_vec *src);
int			vec_insert(t_vec *dst, void *src, size_t index);
int			vec_remove(t_vec *src, size_t index);
int			vec_append(t_vec *dst, t_vec *src);
int			vec_prepend(t_vec *dst, t_vec *src);
void		vec_iter(t_vec *src, void (*f) (void *));
void		vec_map(t_vec *dst, t_vec *src, void (*f) (void *));
int			vec_filter(t_vec *dst, t_vec *src, int (*f) (void *));
int			vec_reduce(void *acc, t_vec *src, void (*f) (void *, void *));
void		vec_sort(t_vec *src, int (*f)(void *, void *));
#endif
