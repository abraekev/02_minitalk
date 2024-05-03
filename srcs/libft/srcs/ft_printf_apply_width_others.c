/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_apply_width_others.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:58:41 by abraekev          #+#    #+#             */
/*   Updated: 2024/03/17 17:22:21 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char *fspec = %[flags][min width][precision][conv specifier]

static char	*strjoin_printf(char *s1, char *s2, size_t s1_len, size_t s2_len)
{
	char	*out;
	size_t	i;

	out = malloc(s1_len + s2_len + 1);
	if (!out)
		return (NULL);
	i = -1;
	while (++i < s1_len)
	{
		out[i] = s1[i];
	}
	i = -1;
	while (++i < s2_len)
	{
		out[s1_len + i] = s2[i];
	}
	out[s1_len + i] = 0;
	return (out);
}

static void	fill_str(char *s, size_t len, char c)
{
	s[len] = 0;
	while (--len != UINT_MAX)
	{
		s[len] = c;
		if (!len)
			break ;
	}
}

static void	process_nbrs(char **out, size_t a_len, t_data *d, t_flags f)
{
	if (ft_strchr("di", d->cspec)
		&& ft_strchr(" +-", (*out)[a_len]) && !f.just_l
		&& f.pad_zero && f.precision < 0)
	{
		(*out)[0] = *(ft_strchr(" +-", (*out)[a_len]));
		(*out)[a_len] = '0';
	}
}

static char	*apply_join(t_data *d, t_flags f, char *add)
{
	char	*out;
	size_t	a_len;

	a_len = ft_strlen(add);
	if (f.just_l)
		out = strjoin_printf(d->insert, add, d->i_len, a_len);
	else
		out = strjoin_printf(add, d->insert, a_len, d->i_len);
	d->i_len = a_len + d->i_len;
	process_nbrs(&out, a_len, d, f);
	ftpf_free_strs(2, &add, &d->insert);
	return (out);
}

char	*ftpf_apply_width_others(t_data *d, t_flags f)
{
	char	*add;
	size_t	a_len;

	if (!d->insert && !f.min_width)
		return (NULL);
	if ((unsigned int)f.min_width <= d->i_len)
		return (d->insert);
	a_len = f.min_width - d->i_len;
	add = malloc(a_len + 1);
	if (!add)
		return (ftpf_free_data(d), NULL);
	if (f.pad_zero && !f.just_l && f.precision < 0
		&& ft_strchr("diuxX", f.cspec))
		fill_str(add, a_len, '0');
	else
		fill_str(add, a_len, ' ');
	return (apply_join(d, f, add));
}
