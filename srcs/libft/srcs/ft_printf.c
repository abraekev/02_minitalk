/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:58:41 by abraekev          #+#    #+#             */
/*   Updated: 2024/04/19 16:31:22 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	format specifier:
//	char *fspec = %[flags][min width][precision][conversion specifier]

static char	*get_fspecstr(t_data *d, size_t i)
{
	char	*convspecs;
	char	*lastchr;
	size_t	j;

	convspecs = "cspdiuxX%";
	j = i + 1;
	while (d->src[j])
	{
		if (ft_strchr(convspecs, d->src[j]))
			break ;
		j++;
	}
	lastchr = (char *)d->src + j;
	return (ft_substr(d->src, i, (lastchr - (d->src + i) + 1)));
}

static int	process_formatspec(t_data *d, int i, va_list args)
{
	d->fspec = get_fspecstr(d, i);
	if (!d->fspec)
		return (ftpf_free_data(d), -1);
	d->f_len = ft_strlen(d->fspec);
	d->cspec = d->fspec[d->f_len - 1];
	d->insert = ftpf_get_insertstr(d, args);
	if (!d->insert)
		return (ftpf_free_data(d), -1);
	ftpf_putstr_special(d);
	return (ftpf_free_data(d), d->f_len);
}

static void	init_d(const char *src, t_data *d, size_t *i)
{
	*i = 0;
	d->src = src;
	d->s_len = ft_strlen(src);
	d->cspec = 0;
	d->f_len = 0;
	d->i_len = 0;
	d->fspec = NULL;
	d->insert = NULL;
}

int	ft_printf(const char *src, ...)
{
	t_data		d;
	size_t		i;
	int			jump;
	va_list		args;

	if (!src)
		return (0);
	va_start(args, src);
	init_d(src, &d, &i);
	while (src[i])
	{
		if (src[i] == '%')
		{
			jump = process_formatspec(&d, i, args);
			if (jump < 0)
				return (ftpf_free_data(&d), -1);
			i = i + jump;
		}
		else
		{
			ft_putchar_fd(src[i], 1);
			i++;
		}
	}
	return (ftpf_free_data(&d), d.s_len);
}
