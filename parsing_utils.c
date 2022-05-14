/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:58:21 by a79856            #+#    #+#             */
/*   Updated: 2022/05/05 18:58:21 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "cub3d.h"

int	ft_check_empty_floor_ceiling(t_info *info, char *line)
{
	if (ft_strncmp(line, "F ", 2) == 0)
		if (info->floor[0] == -1 || info->floor[1] == -1
			|| info->floor[2] == -1)
			return (1);
	if (ft_strncmp(line, "C ", 2) == 0)
		if (info->ceiling[0] == -1 || info->ceiling[1] == -1
			|| info->ceiling[2] == -1)
			return (1);
	return (0);
}

int	ft_is_all_one(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}
