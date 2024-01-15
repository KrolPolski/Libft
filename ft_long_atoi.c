/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:46:01 by rboudwin          #+#    #+#             */
/*   Updated: 2024/01/15 10:50:50 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static long	ft_str_to_int(char *str, long accumulator)
{
	int	i;

	i = 0;
	str = str + i;
	if (!str || !*str || !(*str > 47 && *str < 58))
		return (accumulator);
	else
		return (ft_str_to_int(str + 1, accumulator * 10 + (*str - '0')));
}

static char	*trim_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && (str[i] < 48 || str[i] > 57))
	{
		if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
			i++;
		else if (str[i] == '+' && str[i + 1] >= 48 && str[i + 1] <= 57)
		{
			i++;
			return (str + i);
		}
		else if (str[i] == '-')
			return (str + i);
		else
			return (str + i);
	}
	return (str + i);
}

long	ft_long_atoi(const char *str)
{
	long	result;
	long	accumulator;
	char	*clean_string;
	int		am_i_negative;

	am_i_negative = 0;
	clean_string = trim_whitespace((char *)str);
	accumulator = 0;
	if (clean_string[0] == '-')
	{
		am_i_negative = 1;
		clean_string++;
	}
	result = ft_str_to_int(clean_string, accumulator);
	if (am_i_negative == 1)
		result = -result;
	return (result);
}
/*
#include <stdio.h>
int	main(void)
{
	long result;
//	char string[] = "  -4242145";
	char string[] = "-54";
	char string2[] = "21474836475";
	result = ft_long_atoi(string);
	printf("The string '%s' converts to the integer '%ld'\n", string, result);
	result = ft_long_atoi(string2);
	printf("the string '%s' should be a long number: %ld\n", string2, result);
}*/
