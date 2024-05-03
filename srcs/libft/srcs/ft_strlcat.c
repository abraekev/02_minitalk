/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:12:52 by abraekev          #+#    #+#             */
/*   Updated: 2024/04/08 15:15:36 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	the lib function expects valid ptrs and does not perform null checks.

size_t	ft_strlcat(char *dest, const char *src, size_t d_size)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;

	i = 0;
	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	if (!d_size)
		return (s_len);
	while (src[i] && d_len + i < d_size - 1)
	{
		dest[d_len + i] = src[i];
		i++;
	}
	dest[d_len + i] = 0;
	if (d_size < d_len)
		return (d_size + s_len);
	return (d_len + s_len);
}
