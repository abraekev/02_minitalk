/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:01:06 by abraekev          #+#    #+#             */
/*   Updated: 2024/04/08 15:32:48 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The function expects both s1 and s2 to be valid pointers to null-terminated
strings. If either is NULL, the behavior is not defined by the C Standard.
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	i = 0;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	if (!n)
		return (0);
	while (i < n && p1[i] && p2[i] == p1[i])
		i++;
	if (i == n)
		return (0);
	return (p1[i] - p2[i]);
}
