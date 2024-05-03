/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_validate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:58:41 by abraekev          #+#    #+#             */
/*   Updated: 2024/03/17 17:22:21 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char *fspec = %[flags][min width][precision][conv specifier]

static int	check_precision(char *s, size_t i)
{
	if (s[i] == '.')
	{
		i++;
		if (s[i] == '*')
			i++;
		else
		{
			if (s[i] == '-')
				i++;
			while (ft_isdigit(s[i]))
				i++;
		}
	}
	return (i);
}

int	ftpf_validate_flags(char *s, t_flags *flags)
{
	size_t		i;

	i = 1;
	while (ft_strchr("#0- +", s[i]))
	{
		if (s[i] == '0')
			flags->pad_zero = 1;
		i++;
	}
	if ((s[i] >= '1' && s[i] <= '9') || s[i] == '*')
		i++;
	while (ft_isdigit(s[i]))
	{
		if (s[i - 1] == '*')
			break ;
		i++;
	}
	i = check_precision(s, i);
	if (s[i] && ft_strchr("cspdiuxX%", s[i]) && !s[i + 1])
		return (1);
	return (0);
}
