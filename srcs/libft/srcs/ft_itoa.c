/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:48:35 by abraekev          #+#    #+#             */
/*   Updated: 2024/04/09 11:14:47 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	itoa_len(int n)
{
	size_t	len;

	len = 0;
	if (!n)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		len ++;
	}
	return (len);
}

static void	itoa_str_values(char *s, int n, size_t len)
{
	while (n != 0)
	{
		s[len--] = ('0' + -(n % 10));
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*s;
	size_t	len;
	size_t	is_neg;

	is_neg = 0;
	if (n >= 0)
		n = -n;
	else
		is_neg = 1;
	len = itoa_len(n) + is_neg;
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	if (is_neg)
		s[0] = '-';
	s[len--] = '\0';
	if (n == 0)
		s[0] = '0';
	else
		itoa_str_values(s, n, len);
	return (s);
}
