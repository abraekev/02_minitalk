/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:58:41 by abraekev          #+#    #+#             */
/*   Updated: 2024/03/17 17:22:21 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char *fspec = %[flags][min width][precision][conv specifier]
char	*ftpf_get_empty_str(t_data *d)
{
	char	*str;

	str = malloc(1);
	if (!str)
		return (NULL);
	str[0] = 0;
	d->insert = str;
	return (str);
}

char	*ftpf_get_null_str(t_data *d)
{
	char	*str;

	str = malloc(7);
	if (!str)
		return (NULL);
	ft_strlcpy(str, "(null)", 7);
	d->i_len = 6;
	return (str);
}

void	ftpf_putstr_special(t_data *d)
{
	if (d->cspec == 'c')
		write(1, d->insert, d->i_len);
	else
		ft_putstr_fd(d->insert, 1);
}

void	ftpf_free_strs(size_t n, ...)
{
	size_t	i;
	char	**s;
	va_list	args;

	va_start(args, n);
	i = 0;
	while (i < n)
	{
		s = va_arg(args, char **);
		if (s && *s)
		{
			free(*s);
			*s = NULL;
		}
		i++;
	}
	return ;
}

void	ftpf_free_data(t_data *d)
{
	if (d && d->fspec)
	{
		free(d->fspec);
		d->fspec = NULL;
	}
	if (d && d->insert)
	{
		free(d->insert);
		d->insert = NULL;
	}
	return ;
}
