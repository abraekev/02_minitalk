/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:58:41 by abraekev          #+#    #+#             */
/*   Updated: 2024/04/10 13:19:49 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	MANUAL:
If nmemb or size is 0, then calloc() returns either NULL, or a unique pointer
value that can later  be  successfully passed to free().

If the multiplication of nmemb and size would result in integer overflow,
then calloc() returns an error.  By  contrast,  an integer  overflow  would
not be detected in the following call to malloc(), with the result that an 
incorrectly sized block of memory  would be allocated

void* malloc(size_t size);

argument cant go over size_t max (= SIZE_MAX):

nmemb * size < size_max
*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*out;
	size_t			total;
	size_t			i;

	if (nmemb && size > (SIZE_MAX / nmemb))
		return (NULL);
	total = nmemb * size;
	out = malloc(total);
	if (!out)
		return (NULL);
	i = 0;
	while (i < total)
		out[i++] = 0;
	return ((void *)out);
}
