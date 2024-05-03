/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:08:27 by abraekev          #+#    #+#             */
/*   Updated: 2024/04/08 16:54:17 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_out_len(const char *str, char c)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
			len++;
		while (str[i] && str[i] != c)
			i++;
		while (str[i] && str[i] == c)
			i++;
	}
	return (len);
}

static int	assign_out_el(
char **out, const char *str, size_t s_len, size_t i)
{
	size_t	j;
	size_t	s_start;

	s_start = i - s_len;
	j = 0;
	while (out[j])
		j++;
	out[j] = malloc(s_len + 1);
	if (!out[j])
	{
		while (--j != SIZE_MAX)
			free(out[j]);
		free(out);
		return (0);
	}
	i = 0;
	while (i < s_len)
	{
		(out[j])[i] = str[s_start + i];
		i++;
	}
	(out[j])[i] = 0;
	return (1);
}

static int	do_split(char **out, const char *str, char c)
{
	size_t	strlen;
	size_t	i;

	i = 0;
	while (str[i])
	{
		strlen = 0;
		while (str[i] && str[i] != c)
		{
			strlen ++;
			i++;
		}
		if (strlen)
			if (!(assign_out_el(out, str, strlen, i)))
				return (0);
		while (str[i] && str[i] == c)
			i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char		**out;
	size_t		len;
	size_t		i;

	len = get_out_len(s, c) + 1;
	out = malloc(sizeof(char *) * len);
	if (!out)
		return (NULL);
	i = 0;
	while (i < len)
		out[i++] = 0;
	if (!(do_split(out, s, c)))
		return (NULL);
	return (out);
}
