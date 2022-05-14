#include "cub3d.h"

void	seach_draw_and_txt(t_player *play)
{
	if (!play->side)
	{
		play->perp_wall_dist = play->side_dist_x - play->delta_dist_x;
		play->wall = play->pos_map_y
						  + play->perp_wall_dist * play->raydir_y;
	}
	else
	{
		play->perp_wall_dist = play->side_dist_y - play->delta_dist_y;
		play->wall = play->pos_map_x
						  + play->perp_wall_dist * play->raydir_x;
	}
	play->wall -= floorf(play->wall);
	play->tex_x = (int)(play->wall * (float)64);
	if (!play->side && play->raydir_x > 0)
		play->tex_x = 64 - play->tex_x - 1;
	if (play->side && play->raydir_y < 0)
		play->tex_x = 64 - play->tex_x - 1;
	play->line_height = (int)(480 / play->perp_wall_dist);
	play->draw_start = -play->line_height / 2 + 480 / 2;
	if (play->draw_start < 0)
		play->draw_start = 0;
	play->draw_end = play->line_height / 2 + 480 / 2;
	if (play->draw_end >= 480)
		play->draw_end = 480 - 1;
}

void draw_line(t_player *play, t_texture *text, int y, int x, t_window *wd)
{
	int	c;

	c = 0;
	play->step = (1.0f * 64 / play->line_height);
	play->text_pos = (float)((play->draw_start - 480 / 2
								+ play->line_height / 2) * play->step);
	while(c < play->draw_start)
	{
		my_mlx_pixel_put(wd->img, x, c, play->main->ceilling);
		c++;
	}
	while (y <= play->draw_end)
	{
		play->tex_y = (int)play->text_pos & (64 - 1);
		play->text_pos += play->step;
		my_mlx_pixel_put(wd->img, x, y, get_pixel_color(text, 64 - play->tex_x - 1,
												 play->tex_y));
		y++;
	}
	while (play->draw_end < 480)
	{
		my_mlx_pixel_put(wd->img, x, play->draw_end, play->main->floor);
		play->draw_end++;
	}
}

void	choice_texture(t_player *play, t_window *wd, int x)
{
	t_texture *texture;

	if (!play->side && play->map_x < play->pos_map_x)
		texture = wd->west;
	if (!play->side && play->map_x >= play->pos_map_x)
		texture = wd->east;
	if (play->side && play->map_y < play->pos_map_y)
		texture = wd->north;
	if (play->side && play->map_y >=play->pos_map_y)
		texture = wd->south;
	draw_line(play, texture, play->draw_start, x, wd);
}