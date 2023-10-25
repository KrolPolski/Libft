/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:44:56 by rboudwin          #+#    #+#             */
/*   Updated: 2023/10/25 15:40:53 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	int		cmpresult;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[j] && haystack[i] != '\0' && i < len)
		{
			cmpresult = ft_strncmp(&haystack[i], needle, ft_strlen(needle));
			if (cmpresult == 0)
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char	haystack[] = "So long and thanks for all the fish!";
	char	needle[] = "and";
	char	*result;

	result = ft_strnstr(haystack, needle, 15);
	printf("Haystack is: '%s' \n", haystack);
	printf("Needle is: '%s' \n", needle);
	printf("If this worked the beginning of the following strings");
	printf("should match:\n");
	printf("'%s'    '%s'", needle, result);
	printf("%p was the value returned by ft_strnstr ", result);
	printf("(which should be null if it wasn't found)");
}*/