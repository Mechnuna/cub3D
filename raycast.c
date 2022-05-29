/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:51:48 by bbellatr          #+#    #+#             */
/*   Updated: 2022/05/29 16:51:48 by bbellatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_step_and_sidedist(t_player *play)
{
	if (play->raydir_x < 0)
	{
		play->step_x = -1;
		play->side_dist_x = (play->pos_x - play->map_x)
			* play->delta_dist_x;
	}
	else
	{
		play->step_x = 1;
		play->side_dist_x = (play->map_x + 1.0f - play->pos_x)
			* play->delta_dist_x;
	}
	if (play->raydir_y < 0)
	{
		play->step_y = -1;
		play->side_dist_y = (play->pos_y - play->map_y)
			* play->delta_dist_y;
	}
	else
	{
		play->step_y = 1;
		play->side_dist_y = (play->map_y + 1.0f - play->pos_y)
			* play->delta_dist_y;
	}
}

void	dir_and_dist(t_player *play, int x)
{
	play->camera_x = 2 * x / (float)SCREEN_WIDTH - 1;
	play->raydir_x = play->dir_x + play->plane_x * play->camera_x;
	play->raydir_y = play->dir_y + play->plane_y * play->camera_x;
	play->delta_dist_x = fabs(1 / play->raydir_x);
	play->delta_dist_y = fabs(1 / play->raydir_y);
	play->map_x = (int)play->pos_x;
	play->map_y = (int)play->pos_y;
}

void	search_hit(t_player *play, t_window *game)
{
	play->hit = 0;
	while (!play->hit)
	{
		if (play->side_dist_x < play->side_dist_y)
		{
			play->side_dist_x += play->delta_dist_x;
			play->map_x += play->step_x;
			play->side = 0;
		}
		else
		{
			play->side_dist_y += play->delta_dist_y;
			play->map_y += play->step_y;
			play->side = 1;
		}
		if (game->map[play->map_y][play->map_x] == '1')
			play->hit = 1;
	}
}

void	calc_raycast(t_player *play, t_window *game)
{
	int	x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		dir_and_dist(play, x);
		calc_step_and_sidedist(play);
		search_hit(play, game);
		seach_draw_and_txt(play);
		choice_txt(play, game, x);
		x++;
	}
}

int	render(t_window *game)
{
	key_event(game->play, game->play->keys);
	calc_raycast(game->play, game);
	mlx_put_image_to_window(game->play->mlx, game->play->win,
		game->play->data->img, 0, 0);
	return (0);
}
