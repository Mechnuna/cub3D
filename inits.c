#include "cub3d.h"

void	get_texture(t_window *window, t_texture *txt, char *path)
{
	if (access(path, O_RDONLY) == -1)
		erroren(window, "textures is missing\n", 0);
	txt->img_ptr = mlx_xpm_file_to_image(window->mlx_ptr,
										 path, &txt->width, &txt->height);
	txt->img_val = mlx_get_data_addr(txt->img_ptr, &txt->bpp,
									 &txt->line_len, &txt->endian);
}

void	init_texture(t_window *window)
{
	window->north = malloc(sizeof(t_texture));
	window->south = malloc(sizeof(t_texture));
	window->west = malloc(sizeof(t_texture));
	window->east = malloc(sizeof(t_texture));
	if (!window->north || !window->south || !window->east || !window->west)
	{
		ft_free(window);
		return;
	}
	get_texture(window, window->north, window->nswe[0]);
	get_texture(window, window->south, window->nswe[1]);
	get_texture(window, window->west, window->nswe[2]);
	get_texture(window, window->east, window->nswe[3]);
}

void	init_direction(t_window *window, t_player *play)
{
	if (window->direct == 'N')
	{
		play->dir_x = 0;
		play->dir_y = -1;
	}
	if (window->direct == 'S')
	{
		play->dir_x = 0;
		play->dir_y = 1;
	}
	if (window->direct == 'E')
	{
		play->dir_x = 1;
		play->dir_y = 0;
	}
	if (window->direct == 'W')
	{
		play->dir_x = -1;
		play->dir_y = 0;
	}
}

void	init_keys(t_player *play)
{
	play->keys = malloc(sizeof(t_keys));
	ft_memset(play->keys, 0, sizeof(t_keys));
}

void	init_rc(t_window *window, t_player *play)
{
	//delete
	window->direct = 'N'; //need to assign in parser!!!!
	window->ceilling = 0X00FF0037;
	window->floor = 0X00FF0073;
	window->info = malloc(sizeof(t_info));
	ft_bzero(window->info, sizeof(t_info));
	window->info->map = (char**)malloc(5* sizeof(char*));
	window->info->map[0] = "111111";
	window->info->map[1] = "100101";
	window->info->map[2] = "101001";
	window->info->map[3] = "110001";
	window->info->map[4] = "111111";
	window->nswe[0] = "./textures/north.xpm";
	window->nswe[1] = "./textures/south.xpm";
	window->nswe[2] = "./textures/west.xpm";
	window->nswe[3] = "./textures/east.xpm";
	window->player_base[0] = 4;
	window->player_base[1] = 3;
	//delete
	play->pos_map_x = (float)window->player_base[0] + 0.5;
	play->pos_map_y = (float)window->player_base[1] + 0.5;
	play->main = window;
	play->camera = 0.0;
	play->move_speed = 0.08;
	play->rotation_speed = 0.08;
	play->wall = 0;
	play->tex_x = 0;
	init_direction(window, play);
	//window->info->map[window->player_base[1]][window->player_base[0]] = '0';
	play->plane_x = -play->dir_y * 0.66;
	play->plane_y = play->dir_x * 0.66;
	init_texture(window);
	init_keys(window->play);
}