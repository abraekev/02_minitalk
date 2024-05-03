/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_apply_prec.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:58:41 by abraekev          #+#    #+#             */
/*   Updated: 2024/03/17 17:22:21 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ftpf_apply_precision_s(t_data *d, t_flags f)
{
	char	*tmp;
	char	*s;

	s = d->insert;
	if (!s && (f.precision >= 6 || f.precision == -1))
	{
		s = ftpf_get_null_str(d);
		if (!s)
			return (NULL);
	}
	if (!s && f.precision < 7)
		return (NULL);
	if ((size_t)f.precision < ft_strlen(s) && f.precision >= 0)
	{
		tmp = malloc(f.precision + 1);
		if (!tmp)
			return (ftpf_free_strs(1, &s), NULL);
		ft_strlcpy(tmp, s, f.precision + 1);
		free(s);
		return (tmp);
	}
	return (s);
}
