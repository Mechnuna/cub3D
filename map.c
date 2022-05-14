/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:17:51 by a79856            #+#    #+#             */
/*   Updated: 2022/05/05 19:26:01 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_dir(char direction, t_window *total)
{
	if (direction == 'N')
	{
		total->play->dir_x = 0;
		total->play->dir_y = -1;
		total->play->rotation_angle = PI / 2 * 3;
	}
	else if (direction == 'S')
	{
		total->play->dir_x = 0;
		total->play->dir_y = 1;
		total->play->rotation_angle = PI / 2;
	}
	else if (direction == 'W')
	{
		total->play->dir_x = -1;
		total->play->dir_y = 0;
		total->play->rotation_angle = PI;
	}
	else if (direction == 'E')
	{
		total->play->dir_x = 1;
		total->play->dir_y = 0;
		total->play->rotation_angle = 0;
	}
}

void	ft_replace_perso_char(t_info *info, int *i, int *j, int *k)
{
	*j = -1;
	while (info->original_map[*i][++(*j)])
	{
		if (info->original_map[*i][*j] == ' ')
			info->map[*i][*j] = '1';
		else
			info->map[*i][*j] = info->original_map[*i][*j];
		if (info->original_map[*i][*j] == 'N'
			|| info->original_map[*i][*j] == 'S'
			|| info->original_map[*i][*j] == 'W'
			|| info->original_map[*i][*j] == 'E')
		{
			ft_get_dir(info->original_map[*i][*j], info->total);
			info->map[*i][*j] = '0';
			info->total->play->pos_map_x = *j + 0.5;
			info->total->play->pos_map_y = *i + 0.5;
			info->total->play->pos_pix_x = (*j + 0.5) * MINI_TILE_SIZE;
			info->total->play->pos_pix_y = (*i + 0.5) * MINI_TILE_SIZE;
		}
		if (info->original_map[*i][*j] == '2')
		{
			info->total->sprite[*k]->x = (*j + 0.5) * MINI_TILE_SIZE;
			info->total->sprite[(*k)++]->y = (*i + 0.5) * MINI_TILE_SIZE;
		}
	}
}

void	ft_replace_values_in_map(t_info *info)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < info->map_height)
	{
		ft_replace_perso_char(info, &i, &j, &k);
		if (j < info->map_width - 1)
		{
			while (j < info->map_width)
			{
				info->map[i][j] = '1';
				j++;
			}
		}
		info->map[i][j] = '\0';
		i++;
	}
	info->map[i] = NULL;
}

int	ft_clean_map(t_info *info)
{
	int	i;

	info->map = malloc(sizeof(char *) * (info->map_height + 1));
	if (!info->map)
		return (0);
	i = 0;
	while (i < info->map_height)
	{
		info->map[i] = ft_calloc(sizeof(char), (info->map_width + 1));
		if (!info->map[i])
			return (0);
		i++;
	}
	ft_replace_values_in_map(info);
	return (0);
}
