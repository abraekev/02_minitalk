/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:12:52 by abraekev          #+#    #+#             */
/*   Updated: 2024/04/09 12:17:49 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	size = size of the DESTINATION buffer.

	the maximum number of characters that can be safely copied from src 
	to dst, including the null terminator.
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	s_len;

	i = 0;
	if (!src)
		return (0);
	s_len = ft_strlen(src);
	if (!size)
		return (s_len);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (s_len);
}

/*
#include <stdio.h>
#include <strings.h>
#include <limits.h>

//	cc -Wall -Wextra -Werror ft_strlcpy.c -L. libft.a

int	main()
{
	char	src[] = "testvalues";
	size_t	dsize = 50;
	char	dst[dsize];

	ft_strlcpy(dst, src, dsize);
	printf(">%s<\n", dst);
	return (0);
}
*/
