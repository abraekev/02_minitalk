/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_gets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:58:41 by abraekev          #+#    #+#             */
/*   Updated: 2024/03/17 17:22:21 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ftpf_get_char(char c)
{
	char	*s;

	s = malloc(2);
	if (!s)
		return (NULL);
	s[0] = c;
	s[1] = 0;
	return (s);
}

char	*ftpf_get_str(char *s)
{
	char	*out;
	size_t	o_len;

	if (!s)
		return (NULL);
	else
	{
		o_len = ft_strlen(s);
		out = malloc(o_len + 1);
		if (!out)
			return (NULL);
		ft_strlcpy(out, s, o_len + 1);
	}
	return (out);
}

static char	*apply_flags(t_flags f, t_data *d)
{
	ftpf_set_i_len(d);
	if (ft_strchr("sdiuxX", f.cspec))
		d->insert = ftpf_apply_precision(d, f);
	ftpf_set_i_len(d);
	if (ft_strchr("di", f.cspec))
		d->insert = ftpf_apply_spaceplus(d, f);
	ftpf_set_i_len(d);
	if (ft_strchr("xX", f.cspec))
		d->insert = ftpf_apply_altprint(d, f);
	ftpf_set_i_len(d);
	if (ft_strchr("cspdiuxX", f.cspec))
		d->insert = ftpf_apply_width_others(d, f);
	ftpf_set_s_len_and_nullprotect(d);
	return (d->insert);
}

char	*ftpf_get_insertstr(t_data *d, va_list args)
{
	t_flags	flags;

	flags = ftpf_initiate_flags();
	if (!ftpf_get_flags(d->fspec, &flags, args))
	{
		d->insert = ft_strdup(d->fspec);
		ftpf_set_lengths(d);
		return (d->insert);
	}
	d->insert = NULL;
	if (d->cspec == '%')
		d->insert = ftpf_get_char('%');
	if (d->cspec == 'c')
		d->insert = ftpf_get_char(va_arg(args, int));
	if (d->cspec == 's')
		d->insert = ftpf_get_str(va_arg(args, char *));
	if (d->cspec == 'd' || d->cspec == 'i')
		d->insert = ft_itoa(va_arg(args, int));
	if (d->cspec == 'p')
		d->insert = ftpf_get_vptr_base(va_arg(args, uintptr_t), d);
	if (d->cspec == 'u' || d->cspec == 'x' || d->cspec == 'X')
		d->insert = ftpf_get_uint_base(va_arg(args, unsigned int), d->cspec);
	return (apply_flags(flags, d));
}
