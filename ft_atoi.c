/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:01:27 by rboudwin          #+#    #+#             */
/*   Updated: 2023/10/25 16:33:55 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_to_int(char *str, int accumulator)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
	}
	str = str + i;
	if (!str || !*str || !(*str > 47 && *str < 58))
		return (accumulator);
	else
		return (ft_str_to_int(str + 1, accumulator * 10 + (*str - '0')));
}

char static	*trim_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && (str[i] < 48 || str[i] > 57))
	{
		if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' i
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
			i++;
		if (str[i] == '+')
		{
			i++;
			return (str + i);
		}
		if (str[i] == '-')
			return (str + i);
	}
	return (str + i);
}

int	ft_atoi(const char *str)
{
	int		result;
	int		accumulator;
	char	*clean_string;
	int		am_i_negative;

	am_i_negative = 0;
	clean_string = trim_whitespace((char *)str);
	accumulator = 0;
	if (clean_string[0] == '-')
		am_i_negative = 1;
	result = ft_str_to_int(clean_string, accumulator);
	if (am_i_negative == 1)
		result = -result;
	return (result);
}
/*
#include <stdio.h>
int	main(void)
{
	int result;
	char string[] = "  -4242145";

	result = ft_atoi(string);
	printf("The string '%s' converts to the integer '%d'", string, result);
}*/