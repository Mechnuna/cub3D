/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 10:42:56 by bbellatr          #+#    #+#             */
/*   Updated: 2021/05/10 17:31:55 by bbellatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*mcdest;
	const unsigned char	*mcsrc;
	unsigned char		mcc;
	size_t				i;

	mcdest = (unsigned char *)dest;
	mcsrc = (const unsigned char *)src;
	mcc = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		mcdest[i] = mcsrc[i];
		if (mcsrc[i] == mcc)
			return (dest + i + 1);
		i++;
	}
	return (0);
}
