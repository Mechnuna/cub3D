/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 09:58:11 by bbellatr          #+#    #+#             */
/*   Updated: 2021/05/13 20:20:38 by bbellatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sl(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n / 10 > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*strgen(char *str, long longn, int strl)
{
	int	i;
	int	flag;

	if (longn != 0)
		str = ft_calloc(sizeof(char), (strl + 2));
	else
		return (ft_strdup("0"));
	if (!str)
		return (0);
	i = 0;
	flag = 0;
	if (longn < 0)
	{
		longn *= -1;
		str[i] = '-';
		i++;
		flag = 1;
	}
	while (i <= strl)
	{
		str[strl - i + flag] = longn % 10 + '0';
		longn /= 10;
		i++;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		strl;
	long	longn;

	str = NULL;
	longn = (long) n;
	strl = sl(n);
	str = strgen(str, longn, strl);
	if (!str)
		return (0);
	str[strl + 1] = '\0';
	return (str);
}
