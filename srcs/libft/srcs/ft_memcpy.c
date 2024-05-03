/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:49:13 by abraekev          #+#    #+#             */
/*   Updated: 2024/04/08 15:09:42 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*from;
	unsigned char	*to;
	size_t			i;

	if (!dest || !src)
		return (dest);
	from = (unsigned char *)src;
	to = (unsigned char *)dest;
	i = -1;
	while (++i < n)
		to[i] = from[i];
	return (dest);
}
