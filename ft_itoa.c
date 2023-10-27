/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:50:04 by rboudwin          #+#    #+#             */
/*   Updated: 2023/10/27 12:45:29 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	static	ft_power(int a, int exp)
{
	int	i;
	int	result;

	result = a;
	i = 1;
	if (exp == 0)
		return (1);
	if (exp == 1)
		return (a);
	while (i < exp)
	{
		result = result * a;
		i++;
	}
	return (result);
}

char static	*ft_conversion(int k, int i, char *str, int n)
{
	while (k > 0)
	{
		str[i] = (n / ft_power(10, k)) + 48;
		n = n - ((str[i] - 48) * ft_power(10, k));
		i++;
		k--;
	}
	str[i++] = (n % 10) + 48;
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	int		k;
	int		digits;
	char	*str;

	i = 0;
	str = malloc(12);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		str[i++] = '-';
		n = -n;
	}
	k = n;
	digits = 1;
	while (k / 10 > 0)
	{
		digits++;
		k = k / 10;
	}
	k = digits - 1;
	return (ft_conversion(k, i, str, n));
}
/*
#include <stdio.h>

int	main(void)
{
	int		n;
	char	*str;

	n = -214748348;
	str = ft_itoa(n);
	printf("'%d' represented as a string is '%s'", n, str);
	free(str);
}*/