/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:51:20 by bbellatr          #+#    #+#             */
/*   Updated: 2022/05/29 16:51:20 by bbellatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_w(t_player *play)
{
	if (play->main->map[(int)play->pos_y]
		[(int)(play->pos_x + play->dir_x * 0.11f)] != '1')
		play->pos_x += play->dir_x * play->move_speed;
	if (play->main->map[(int)(play->pos_y + play->dir_y * 0.11f)]
		[(int)play->pos_x] != '1')
		play->pos_y += play->dir_y * play->move_speed;
}

void	move_a(t_player *play)
{
	if (play->main->map[(int)play->pos_y]
		[(int)(play->pos_x - play->plane_x * 0.11f)] != '1')
		play->pos_x -= play->plane_x * play->move_speed;
	if (play->main->map[(int)(play->pos_y - play->plane_y * 0.11f)]
		[(int)play->pos_x] != '1')
		play->pos_y -= play->plane_y * play->move_speed;
}

void	move_s(t_player *play)
{
	if (play->main->map[(int)play->pos_y]
		[(int)(play->pos_x - play->dir_x * 0.11f)] != '1')
		play->pos_x -= play->dir_x * play->move_speed;
	if (play->main->map[(int)(play->pos_y - play->dir_y * 0.11f)]
		[(int)play->pos_x] != '1')
		play->pos_y -= play->dir_y * play->move_speed;
}

void	move_d(t_player *play)
{
	if (play->main->map[(int)play->pos_y]
		[(int)(play->pos_x + play->plane_x * 0.11f)] != '1')
		play->pos_x += play->plane_x * play->move_speed;
	if (play->main->map[(int)(play->pos_y + play->plane_y * 0.11f)]
		[(int)(play->pos_x)] != '1')
		play->pos_y += play->plane_y * play->move_speed;
}
