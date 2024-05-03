/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:49:13 by abraekev          #+#    #+#             */
/*   Updated: 2024/04/09 11:55:30 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	val;
	size_t			i;

	if (!s)
		return (NULL);
	ptr = (unsigned char *)s;
	val = (unsigned char)c;
	i = 0;
	while (i < n)
		ptr[i++] = val;
	return (s);
}

/*
#include <stdio.h>
#include <strings.h>
#include <limits.h>

//	cc -Wall -Wextra -Werror ft_strlen.c

int	main()
{
	char	str[] = "12345";
	size_t	n = 6;

	printf(">%s<\n", (char *)ft_memset((void *)str, (int)'A' , n));
	printf(">%s<\n", (char *)ft_memset(NULL, (int)'A' , n));
	return (0);
}
*/
