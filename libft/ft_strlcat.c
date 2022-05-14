/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 09:55:19 by bbellatr          #+#    #+#             */
/*   Updated: 2021/05/12 16:16:16 by bbellatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		destl;
	char		*d;
	const char	*s;
	size_t		n;

	d = dest;
	s = src;
	n = size;
	while (n-- && *d != '\0')
		d++;
	destl = d - dest;
	n = size - destl;
	if (n == 0)
		return (destl + ft_strlen(s));
	while (*s)
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (destl + (s - src));
}
