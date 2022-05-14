/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 21:49:25 by bbellatr          #+#    #+#             */
/*   Updated: 2021/05/12 19:16:43 by bbellatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (0);
		i++;
	}
	return (1);
}

static void	ijji(size_t *i, char const *s1, char const *set)
{
	size_t	j;
	size_t	slen;

	j = 0;
	slen = ft_strlen(s1) - 1;
	while (check(set, s1[j]) == 0)
		j++;
	i[0] = j;
	j = slen;
	while (j && check(set, s1[j]) == 0)
		j--;
	i[1] = j;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i[2];
	char	*str;

	if (!s1)
		return (NULL);
	ijji(i, s1, set);
	if (i[0] <= i[1])
		str = ft_substr(s1, i[0], i[1] - i[0] + 1);
	else
		str = ft_substr(s1, i[0], 0);
	return (str);
}
