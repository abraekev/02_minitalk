/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:58:41 by abraekev          #+#    #+#             */
/*   Updated: 2024/03/17 17:22:21 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char *fspec = %[flags][min width][precision][conv specifier]

static size_t	get_uint_len(unsigned int nbr, size_t b_len)
{
	size_t	len;

	len = 0;
	if (!nbr)
		return (1);
	while (nbr != 0)
	{
		len ++;
		nbr /= b_len;
	}
	return (len);
}

static char	*uint_base(unsigned int nbr, char *base, size_t b_len)
{
	size_t	s_len;
	char	*s;

	s_len = get_uint_len(nbr, b_len);
	s = malloc(s_len + 1);
	if (!s)
		return (NULL);
	s[s_len] = 0;
	while (s_len != 0)
	{
		s[s_len - 1] = *(base + (nbr % b_len));
		nbr /= b_len;
		s_len--;
	}
	return (s);
}

char	*ftpf_get_uint_base(unsigned int nbr, char c)
{
	char	*base;

	if (c == 'u')
		base = "0123456789";
	else if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	else
		return (NULL);
	return (uint_base(nbr, base, ft_strlen(base)));
}
