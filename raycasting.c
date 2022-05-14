#include "cub3d.h"

void	dir_and_dist(t_player *play, int x)
{
	play->camera = 2 * x / (float)640 - 1;
	play->raydir_x = play->dir_x + play->plane_x * play->camera;
	play->raydir_y = play->dir_y + play->plane_y * play->camera;
	play->delta_dist_x= fabs(1 / play->raydir_x);
	play->delta_dist_y = fabs(1 / play->raydir_y);
	play->map_x = (int)play->pos_map_x;
	play->map_y = (int)play->pos_map_y;
}

void	calc_step_and_sidedist(t_player *play)
{
	if (play->raydir_x < 0)
	{
		play->step_x = -1;
		play->side_dist_x = (play->pos_map_x - play->map_x)
							   * play->delta_dist_x;
	}
	else
	{
		play->step_x = 1;
		play->side_dist_x = (play->map_x + 1.0f - play->pos_map_x)
							   * play->delta_dist_x;
	}
	if (play->raydir_y < 0)
	{
		play->step_y = -1;
		play->side_dist_y = (play->pos_map_y - play->map_y)
							   * play->delta_dist_y;
	}
	else
	{
		play->step_y = 1;
		play->side_dist_y = (play->map_y + 1.0f - play->pos_map_y)
							   * play->delta_dist_y;
	}
}

void	search_hit(t_player	*play, t_window *wd)
{
	play->hit  = 0;
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
		if (wd->info->map[play->map_y][play->map_x] == '1')
			play->hit = 1;
	}
}

void	calc_raycast(t_player *play, t_window *wd)
{
	int	x;

	x = 0;
	while (x < 640)
	{
		dir_and_dist(play, x);
		calc_step_and_sidedist(play);
		search_hit(play, wd);
		seach_draw_and_txt(play);
		choice_texture(play, wd, x);
		x++;
	}
}

int	render(t_window *wd)
{
	key_event(wd->play, wd->play->keys);
	calc_raycast(wd->play, wd);
	mlx_put_image_to_window(wd->mlx_ptr, wd->win_ptr, wd->img->img, 0, 0);
	return (0);
}