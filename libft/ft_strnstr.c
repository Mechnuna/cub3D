/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 11:53:37 by bbellatr          #+#    #+#             */
/*   Updated: 2021/05/10 18:06:41 by bbellatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	llen;
	char	*b;
	size_t	c;

	i = 0;
	llen = ft_strlen(little);
	b = (char *)big;
	if (llen == 0 || big == little)
		return (b);
	while (b[i] && i < len)
	{
		c = 0;
		while (b[i + c] && little[c] && b[i + c] == little[c]
			&& (i + c) < len)
			c++;
		if (c == llen)
			return (b + i);
		i++;
	}
	return (0);
}
