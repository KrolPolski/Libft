/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:01:00 by rboudwin          #+#    #+#             */
/*   Updated: 2023/10/26 15:38:04 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	static	ft_trimfront(char const *s1, char const *set, char *temp_string)

{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0' && ft_strchr(set, s1[i]) != NULL)
		i++;
	while (s1[i] != '\0')
	{
		temp_string[j] = s1[i];
		j++;
		i++;
	}
	temp_string[j] = '\0';
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*temp_string;
	char	*clean_string;

	clean_string = malloc(ft_strlen(s1));
	temp_string = malloc(ft_strlen(s1));
	if (clean_string == NULL || temp_string == NULL)
		return (NULL);
	k = ft_trimfront(s1, set, temp_string);
	i = 0;
	while (ft_strchr(set, temp_string[k]) != NULL && k > 0)
		k--;
	j = 0;
	while (j <= k)
	{
		clean_string[i] = temp_string[j];
		j++;
		i++;
	}
	clean_string[i] = '\0';
	return (clean_string);
}

/*#include <stdio.h>

int	main(void)
{
	char	dirty_string[] = "=!===!==Da!ta!=====";
	char	set[] = "=!";
	char	*clean_string;

	clean_string = ft_strtrim(dirty_string, set);
	printf("'%s' with '%s' removed is '%s'", dirty_string, set, clean_string);
	free(clean_string);
}*/