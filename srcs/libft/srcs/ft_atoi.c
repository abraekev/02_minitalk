/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:48:35 by abraekev          #+#    #+#             */
/*   Updated: 2024/04/09 12:24:28 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Passing a NULL pointer to the atoi() function in C leads to undefined behavior.
The function expects a valid, null-terminated string as its argument.
*/

static int	is_white_space(const char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

static int	is_long_overflow(long nb, char c)
{
	if (nb > LONG_MAX / 10 || (nb == LONG_MAX / 10 && c - '0' > LONG_MAX % 10))
		return (1);
	return (0);
}

static int	overflow_return(int min)
{
	if (min > 0)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned int	i;
	int				min;
	long			nb;

	nb = 0;
	min = 1;
	i = 0;
	while (is_white_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			min = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (is_long_overflow(nb, str[i]))
			return (overflow_return(min));
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return ((int)(min * nb));
}

/*
#include <unistd.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//	cc -Wall -Wextra -Werror ft_atoi.c -L. libft.a

int	main(void)
{

	char *str1 = " -000333rdd 0";
	char *str2 = " 0000333rdd 0";
	char *str3 = "+0000333rdd 0";
	char *str4 = "-+00000333rdd 0";
	char *str5 = "-2147483648";
	char *str6 = "+2147483647";
	char *str7 = "2147483648";
	char *str8 = "2147483649";
	char *str9 = "5721985738291";
	char *str10 = "   -92233720368542347758070782623434";
	char *str11 = "   -92233720368547758072341343118922";
	char *str12 = "   922337203685477580723413249085823";
	char *str13 = "   922337203685477580783234234245902";
	char *array[]={str1, str2, str3, str4, str5, str6,
	str7, str8, str9, str10, str11, str12, str13};

	for (int i = 0; i < 13; i++)
	{
		printf("str:\t\"%s\"\nft_:\t%d\n", array[i], ft_atoi(array[i]));
		printf("lib:\t%d\n\n", atoi(array[i]));
	}
	return (0);
}
*/
