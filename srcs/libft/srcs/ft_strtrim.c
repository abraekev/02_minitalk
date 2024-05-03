/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:49:13 by abraekev          #+#    #+#             */
/*   Updated: 2024/04/08 17:09:42 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_char_of(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static char	*get_return(char const *s1, size_t start, size_t len)
{
	char	*out;

	out = ft_substr(s1, start, len);
	if (!out)
		return (NULL);
	return (out);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	len = ft_strlen(s1);
	i = 0;
	while (is_char_of(s1[i], set) && i < len)
		i++;
	start = i;
	i = len;
	while ((is_char_of(s1[i], set) || s1[i] == '\0') && i > start)
		i--;
	end = i;
	if (end - start + 1 > 0)
		len = end - start + 1;
	else
		len = 0;
	return (get_return(s1, start, len));
}
