#include "cub3d.h"

void	move_w(t_player *play)
{
	if (play->main->info->map[(int)play->pos_map_y]
		[(int)(play->pos_map_x + play->dir_x * 0.11f)] != '1')
		play->pos_map_x += play->dir_x * play->move_speed;
	if (play->main->info->map[(int)(play->pos_map_y + play->dir_y * 0.11f)]
		[(int)play->pos_map_x] != '1')
		play->pos_map_y += play->dir_y * play->move_speed;
	printf("1\n");
}

void	move_a(t_player *play)
{
	if (play->main->info->map[(int)play->pos_map_y]
		[(int)(play->pos_map_x - play->plane_x * 0.11f)] != '1')
		play->pos_map_x -= play->plane_x * play->move_speed;
	if (play->main->info->map[(int)(play->pos_map_y - play->plane_y * 0.11f)]
		[(int)play->pos_map_x] != '1')
		play->pos_map_y -= play->plane_y * play->move_speed;
}

void	move_s(t_player *play)
{
	if (play->main->info->map[(int)play->pos_map_y]
		[(int)(play->pos_map_x - play->dir_x * 0.11f)] != '1')
		play->pos_map_x -= play->dir_x * play->move_speed;
	if (play->main->info->map[(int)(play->pos_map_y - play->dir_y * 0.11f)]
		[(int)play->pos_map_x] != '1')
		play->pos_map_y -= play->dir_y * play->move_speed;
}

void	move_d(t_player *play)
{
	if (play->main->info->map[(int)play->pos_map_y]
		[(int)(play->pos_map_x + play->plane_x * 0.11f)] != '1')
		play->pos_map_x += play->plane_x * play->move_speed;
	if (play->main->info->map[(int)(play->pos_map_y + play->plane_y * 0.11f)]
		[(int)(play->pos_map_x)] != '1')
		play->pos_map_y += play->plane_y * play->move_speed;
}

