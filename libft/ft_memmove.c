/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 08:38:27 by bbellatr          #+#    #+#             */
/*   Updated: 2021/05/11 16:54:24 by bbellatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*mvdest;
	unsigned char	*mvsrc;

	mvdest = (unsigned char *)dest;
	mvsrc = (unsigned char *)src;
	if (mvdest == mvsrc)
		return (dest);
	if (mvsrc < mvdest)
	{
		dest = ft_memcpy(dest, src, n);
	}
	else
	{
		while (n > 0)
		{
			*mvdest++ = *mvsrc++;
			n--;
		}
	}
	return (dest);
}
