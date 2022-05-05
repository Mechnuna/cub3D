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


////////кастомная mlx_put
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

////////////////рисуем игрока
void	put_player(int size, t_window *data)
{
	int i;
	int j;

	i = 0;
	data->img->img = mlx_new_image(data->win_ptr, 512, 512);
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bits_per_pixel,
		&data->img->line_length, &data->img->endian);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_mlx_pixel_put(data->img, data->play->pos_map_x + j, data->play->pos_map_y + i, 0x00FF0000);
			j++;
		}
		// printf("%d %d\n", data->play->pos_map_x + j, data->play->pos_map_y + i);
		i++;
	}
	mlx_put_image_to_window(data->win_ptr, data->mlx_ptr, data->img->img, 0, 0);
}

///////////// функции для обработки нажатия клавиш
int	is_a_key(int key)
{
	return (key == 123 || key == 124 || key == 125 || key == 126
		|| key == 24 || key == 27 || key == 2 || key == 0
		|| key == 1 || key == 13 || key == 49 || key == 53
		|| key == 47 || key == 43);
}

// 0 - A S -1 W -13 D - 2

void	buttons(int key, t_player *data)
{
	if (key == 13)
		data->pos_map_y -= 8;
	if (key == 1)
		data->pos_map_y += 8;
	if (key == 2)
		data->pos_map_x += 8;
	if (key == 0)
		data->pos_map_x -= 8;
}

int	deal_key(int key, t_window *data)
{
	if (is_a_key(key))
	{
		mlx_clear_window(data->win_ptr, data->mlx_ptr);
		buttons(key, data->play);
		put_player(8, data);
	}
	if (key == 53)
	{
		mlx_destroy_window(data->win_ptr, data->mlx_ptr);
		exit(0);
	}
	return (0);
}

int main(int ac, char **av)
{
	t_window wd;
	t_player	play;
	t_data	img;
	t_info	info;

	play.pos_map_x = 300;
	play.pos_map_y = 300;
	wd.info = &info;
	wd.play = &play;
	// if (ft_handle_map(av, wd.info, &wd))
	// 	return (0);
	wd.win_ptr = mlx_init();
	wd.img = &img;
	wd.mlx_ptr = mlx_new_window(wd.win_ptr,512, 512, "Cub3D");
	// img.img = mlx_new_image(wd.win_ptr, 512, 512);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
	// 	&img.line_length, &img.endian);
	put_player(8, &wd);
	mlx_put_image_to_window(wd.win_ptr, wd.mlx_ptr, img.img, 0, 0);
	mlx_key_hook(wd.mlx_ptr, deal_key, &wd);
	mlx_loop(wd.win_ptr);
}