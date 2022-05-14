/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 19:22:10 by bbellatr          #+#    #+#             */
/*   Updated: 2021/05/11 17:01:04 by bbellatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	strl;
	size_t	s1l;
	size_t	s2l;

	if (!s1 && !s2)
		return (0);
	else if (!s1 && s2)
		return (ft_strdup(s2));
	else if (s1 && !s2)
		return (ft_strdup(s1));
	s1l = ft_strlen(s1);
	s2l = ft_strlen(s2);
	strl = s1l + s2l + 1;
	str = malloc(sizeof(char) * strl);
	if (!str)
		return (NULL);
	ft_memmove(str, s1, s1l);
	ft_memmove(str + s1l, s2, s2l);
	str[strl - 1] = '\0';
	return (str);
}
