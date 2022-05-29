/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_txt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:50:47 by bbellatr          #+#    #+#             */
/*   Updated: 2022/05/29 16:50:47 by bbellatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	open_txt(t_window *main, t_textures *txt, char *path)
{
	if (access(path, O_RDONLY) == -1)
		ft_error(main, "Some texture is missing or access denied\n", 0);
	txt->img_ptr = mlx_xpm_file_to_image(main->play->mlx,
			path, &txt->width, &txt->height);
	txt->img_value = mlx_get_data_addr(txt->img_ptr, &txt->bpp,
			&txt->line_len, &txt->endian);
}

void	load_txt(t_window *main)
{
	open_txt(main, main->north, main->nswe[0]);
	open_txt(main, main->south, main->nswe[1]);
	open_txt(main, main->west, main->nswe[2]);
	open_txt(main, main->east, main->nswe[3]);
}

void	init_txt(t_window *main)
{
	main->north = malloc(sizeof(t_textures));
	main->south = malloc(sizeof(t_textures));
	main->east = malloc(sizeof(t_textures));
	main->west = malloc(sizeof(t_textures));
	if (!main->north || !main->south || !main->west || !main->east)
	{
		free_txtr(main);
		exit(EXIT_FAILURE);
	}
	load_txt(main);
}
