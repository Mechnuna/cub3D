/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 12:17:34 by bbellatr          #+#    #+#             */
/*   Updated: 2021/05/11 20:03:37 by bbellatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	int				last;
	unsigned char	uc;

	i = 0;
	last = -1;
	uc = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == uc)
			last = i;
		i++;
	}
	if (s[i] == uc)
		last = i;
	if (last != -1)
		return ((char *)&s[last]);
	else
		return (NULL);
}
