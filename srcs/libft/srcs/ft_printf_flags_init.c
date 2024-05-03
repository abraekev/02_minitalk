/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:58:41 by abraekev          #+#    #+#             */
/*   Updated: 2024/03/17 17:22:21 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char *fspec = %[flags][min width][precision][conv specifier]

t_flags	ftpf_initiate_flags(void)
{
	t_flags	flags;

	flags.just_l = 0;
	flags.pad_zero = 0;
	flags.pref_space = 0;
	flags.pref_plus = 0;
	flags.alt_print = 0;
	flags.min_width = 0;
	flags.precision = -1;
	flags.cspec = 0;
	return (flags);
}

static void	get_precision(t_flags *flags, char *fspec, va_list args)
{
	int	i;
	int	nbr;

	i = 0;
	while (fspec[i] && fspec[i] != '.')
		i++;
	if (!fspec[i])
		return ;
	i++;
	if (fspec[i] == '*')
	{
		flags->precision = va_arg(args, int);
		return ;
	}
	nbr = ft_atoi((fspec + i));
	if (nbr)
		flags->precision = nbr;
	else
		flags->precision = 0;
}

static void	get_min_width(t_flags *flags, char *fspec, va_list args)
{
	int	i;
	int	nbr;

	i = 0;
	while (fspec[i] && (fspec[i] < '1' || fspec[i] > '9'))
	{
		if (fspec[i] == '*' && fspec[i - 1] != '.')
		{
			flags->min_width = va_arg(args, int);
			if (flags->min_width < 0)
			{
				flags->just_l = 1;
				flags->min_width *= (-1);
			}
			return ;
		}
		if (fspec[i] == '.')
			return ;
		i++;
	}
	nbr = ft_atoi((fspec + i));
	if (nbr)
		flags->min_width = nbr;
}

int	ftpf_get_flags(char *fspec, t_flags *flags, va_list args)
{
	if (!ftpf_validate_flags(fspec, flags))
		return (0);
	if (ft_strchr(fspec, '-'))
		flags->just_l = 1;
	if (ft_strchr(fspec, '#'))
		flags->alt_print = 1;
	if (ft_strchr(fspec, ' '))
		flags->pref_space = 1;
	if (ft_strchr(fspec, '+'))
		flags->pref_plus = 1;
	flags->cspec = fspec[ft_strlen(fspec) - 1];
	get_min_width(flags, fspec, args);
	get_precision(flags, fspec, args);
	return (1);
}
