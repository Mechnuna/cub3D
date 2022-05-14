/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 09:03:29 by bbellatr          #+#    #+#             */
/*   Updated: 2021/05/10 15:12:40 by bbellatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*mb;
	size_t			i;

	i = 0;
	mb = (unsigned char *)s;
	while (i < n)
	{
		mb[i] = c;
		i++;
	}
	return (s = mb);
}
