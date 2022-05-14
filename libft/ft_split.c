/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:52:10 by bbellatr          #+#    #+#             */
/*   Updated: 2021/05/14 19:34:14 by bbellatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ssc(char const *s, char c)
{
	const char	*tmp;
	int			n;

	n = 0;
	while (*s)
	{
		tmp = s;
		while (*s != c &&*s != '\0')
			s++;
		if (tmp != s)
			n++;
		while (*s == c && *s != 0)
			s++;
	}
	return (n);
}

static int	mallosplit(char **matstr, char const *s, char c)
{
	const char	*strs;
	size_t		strl;
	size_t		i;

	i = 0;
	while (*s)
	{
		strs = s;
		while (*s != c && *s != '\0')
			s++;
		if (strs != s)
		{
			strl = s - strs;
			matstr[i] = ft_substr(strs, 0, strl);
			if (!(matstr[i++]))
				return (0);
		}
		while (*s == c && *s != '\0')
			s++;
	}
	return (37);
}

static void	myfree(char **matstr)
{
	size_t	i;

	i = 0;
	while (matstr[i] != NULL)
	{
		free(matstr[i]);
		i++;
	}
	free(matstr);
}

char	**ft_split(char const *s, char c)
{
	char	**matstr;
	int		nw;

	if (!s)
		return (NULL);
	nw = ssc(s, c);
	matstr = malloc(sizeof(char *) * (nw + 1));
	if (!matstr)
		return (NULL);
	if (nw != 0)
	{
		if (mallosplit(matstr, s, c) == 0)
		{
			myfree(matstr);
			return (NULL);
		}
	}
	matstr[nw] = NULL;
	return (matstr);
}
