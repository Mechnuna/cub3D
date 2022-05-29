/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 17:08:00 by bbellatr          #+#    #+#             */
/*   Updated: 2022/05/29 17:08:00 by bbellatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_l(t_player *play)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = play->dir_x;
	old_plane_x = play->plane_x;
	play->dir_x = play->dir_x * cos(-play->rot_speed)
		- play->dir_y * sin(-play->rot_speed);
	play->dir_y = old_dir_x * sin(-play->rot_speed)
		+ play->dir_y * cos(-play->rot_speed);
	play->plane_x = play->plane_x * cos(-play->rot_speed)
		- play->plane_y * sin(-play->rot_speed);
	play->plane_y = old_plane_x * sin(-play->rot_speed)
		+ play->plane_y * cos(play->rot_speed);
}

void	rotate_r(t_player *play)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = play->dir_x;
	old_plane_x = play->plane_x;
	play->dir_x = play->dir_x * cos(play->rot_speed)
		- play->dir_y * sin(play->rot_speed);
	play->dir_y = old_dir_x * sin(play->rot_speed)
		+ play->dir_y * cos(play->rot_speed);
	play->plane_x = play->plane_x * cos(play->rot_speed)
		- play->plane_y * sin(play->rot_speed);
	play->plane_y = old_plane_x * sin(play->rot_speed)
		+ play->plane_y * cos(play->rot_speed);
}
