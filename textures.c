/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:51:58 by bbellatr          #+#    #+#             */
/*   Updated: 2022/05/29 16:51:58 by bbellatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	seach_draw_and_txt(t_player *play)
{
	if (!play->side)
	{
		play->perp_wall_dist = play->side_dist_x - play->delta_dist_x;
		play->wall_x = play->pos_y
			+ play->perp_wall_dist * play->raydir_y;
	}
	else
	{
		play->perp_wall_dist = play->side_dist_y - play->delta_dist_y;
		play->wall_x = play->pos_x
			+ play->perp_wall_dist * play->raydir_x;
	}
	play->wall_x -= floorf(play->wall_x);
	play->tex_x = (int)(play->wall_x * (float)TEXTURE_WIDTH);
	if (!play->side && play->raydir_x > 0)
		play->tex_x = TEXTURE_WIDTH - play->tex_x - 1;
	if (play->side && play->raydir_y < 0)
		play->tex_x = TEXTURE_WIDTH - play->tex_x - 1;
	play->line_height = (int)(SCREEN_HEIGHT / play->perp_wall_dist);
	play->draw_start = -play->line_height / 2 + SCREEN_HEIGHT / 2;
	if (play->draw_start < 0)
		play->draw_start = 0;
	play->draw_end = play->line_height / 2 + SCREEN_HEIGHT / 2;
	if (play->draw_end >= SCREEN_HEIGHT)
		play->draw_end = SCREEN_HEIGHT - 1;
}

void	draw_line(t_player *play, t_textures *txt, int y, int x)
{
	int	c;

	c = 0;
	play->step = (1.0f * TEXTURE_HEIGHT / play->line_height);
	play->tex_pos = (float)((play->draw_start - SCREEN_HEIGHT / 2
				+ play->line_height / 2) * play->step);
	while (c < play->draw_start)
	{
		pixel_put(play->data, x, c, play->main->ceilling);
		c++;
	}
	while (y <= play->draw_end)
	{
		play->tex_y = (int)play->tex_pos & (TEXTURE_HEIGHT - 1);
		play->tex_pos += play->step;
		pixel_put(play->data, x, y, get_pixel_color(
				txt, TEXTURE_WIDTH - play->tex_x - 1, play->tex_y));
		y++;
	}
	while (play->draw_end < SCREEN_HEIGHT)
	{
		pixel_put(play->data, x, play->draw_end, play->main->floor);
		play->draw_end++;
	}
}

void	choice_txt(t_player *play, t_window *main, int x)
{
	t_textures	*txt;

	if (!play->side && play->map_x < play->pos_x)
		txt = main->west;
	if (!play->side && play->map_x >= play->pos_x)
		txt = main->east;
	if (play->side && play->map_y < play->pos_y)
		txt = main->north;
	if (play->side && play->map_y >= play->pos_y)
		txt = main->south;
	draw_line(play, txt, play->draw_start, x);
}
