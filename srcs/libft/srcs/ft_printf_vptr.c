/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_vptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:58:41 by abraekev          #+#    #+#             */
/*   Updated: 2024/03/17 17:22:21 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char *fspec = %[flags][min width][precision][conv specifier]

static size_t	get_vptr_len(uintptr_t nbr, size_t b_len)
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

static char	*vptr_base(uintptr_t nbr, char *base, size_t b_len)
{
	size_t	s_len;
	char	*s;

	s_len = get_vptr_len(nbr, b_len);
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

static char	*empty_ptr(void)
{
	char	*s;

	s = malloc(6);
	if (!s)
		return (NULL);
	ft_strlcpy(s, "(nil)", 6);
	return (s);
}

char	*ftpf_get_vptr_base(uintptr_t nbr, t_data *d)
{
	char	*base;

	base = "0123456789abcdef";
	if (!nbr)
		return (empty_ptr());
	d->insert = vptr_base(nbr, base, ft_strlen(base));
	return (ftpf_add_prefix(d, "0x"));
}
