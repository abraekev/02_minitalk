/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:49:13 by abraekev          #+#    #+#             */
/*   Updated: 2024/04/08 15:34:13 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		search;

	if (!s)
		return (NULL);
	ptr = (const unsigned char *)s;
	search = (unsigned char)c;
	while (n-- > 0)
	{
		if (*ptr == search)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}
