/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 03:14:00 by a79856            #+#    #+#             */
/*   Updated: 2022/05/05 19:30:29 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_dir(t_window *main, t_player *play)
{
	if (main->playdir == 'N')
	{
		play->dir_x = 0;
		play->dir_y = -1;
	}
	if (main->playdir == 'S')
	{
		play->dir_x = 0;
		play->dir_y = 1;
	}
	if (main->playdir == 'E')
	{
		play->dir_x = 1;
		play->dir_y = 0;
	}
	if (main->playdir == 'W')
	{
		play->dir_x = -1;
		play->dir_y = 0;
	}
}

void	init_key(t_player *play)
{
	t_keys	*keys;

	keys = malloc(sizeof(t_keys));
	ft_memset(keys, 0, sizeof(t_keys));
	play->keys = keys;
}

void	init_st_rc(t_window *main, t_player *play)
{
	//Should be in parser!
	main->playdir = 'N';
	main->ceilling = 0X00FF0037;
	main->floor = 0X00FF0073;
	main->map = (char**)malloc(5* sizeof(char*));
	main->map[0] = "11111111111";
	main->map[1] = "10000000001";
	main->map[2] = "10100000001";
	main->map[3] = "11000000001";
	main->map[4] = "11111111111";
	main->nswe[0] = "./textures/north.xpm";
	main->nswe[1] = "./textures/south.xpm";
	main->nswe[2] = "./textures/west.xpm";
	main->nswe[3] = "./textures/east.xpm";
	main->player_base[0] = 4;
	main->player_base[1] = 3;
	//del
	play->pos_x = (float)main->player_base[0] + 0.5;
	play->pos_y = (float)main->player_base[1] + 0.5;
	play->main = main;
	play->camera_x = 0.0;
	play->move_speed = 0.09;
	play->rot_speed = 0.07;
	play->wall_x = 0;
	play->tex_x = 0;
	init_dir(main, play);
	//main->map[main->player_base[0]][main->player_base[1]] = '0';
	play->plane_x = -play->dir_y * 0.66;
	play->plane_y = play->dir_x * 0.66;
	init_key(play);
	init_txt(main);
}

void	ft_cub(t_window *game)
{
	t_data		*data;
	t_player	*play;

	play = malloc(sizeof(t_player));
	if (!play)
		exit(EXIT_FAILURE);
	game->play = play;
	play->mlx = mlx_init();
	init_st_rc(game, play);
	data = malloc(sizeof(t_data));
	if (!data)
		exit(EXIT_FAILURE);
	play->data = data;
	play->win = mlx_new_window(play->mlx, SCREEN_WIDTH,
			SCREEN_HEIGHT, "cub37D");
	data->img = mlx_new_image(play->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bpp,
			&data->line_len, &data->endian);
	mlx_hook(play->win, 2, 0, keypress, play->keys);
	mlx_hook(play->win, 3, 0, keyrelease, play->keys);
	mlx_hook(play->win, 17, 0, free_all, play);
	mlx_loop_hook(play->mlx, render, game);
	mlx_loop(play->mlx);
}

int	main(int ac, char **av)
{
	t_window	*wd;

	if (ac < 2)
		ft_error(NULL, "Too few arguments", 0);
	if (ac > 2)
		ft_error(NULL, "Too many arguments", 0);
	wd = (t_window *)malloc(sizeof(t_window));
	ft_handle_map(av, wd);
	ft_cub(wd);
	ft_free_game(wd);
	exit(EXIT_SUCCESS);
}
