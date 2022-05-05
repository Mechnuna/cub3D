/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 03:07:25 by a79856            #+#    #+#             */
/*   Updated: 2022/05/05 18:51:17 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "minilibx_mms_202002199/mlx.h"

typedef struct s_info
{
	char			*av;
	char			*north_path;
	char			*south_path;
	char			*west_path;
	char			*east_path;
	int				floor[3];
	int				ceiling[3];
	int				counter;
	int				check_double_path;
	char			**original_map;
	char			**map;
	int				map_width;
	int				map_height;
	char			*first_line;
	int				nb_sprites;
	struct s_total	*total;
}				t_info;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_player
{
	int		pos_map_x;
	int		pos_map_y;
	double	pos_pix_x;
	double	pos_pix_y;
	int		mov_up;
	int		mov_down;
	int		mov_left;
	int		mov_right;
	char	orientation;
}	t_play;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_play	*play;
	t_data	*img;
	t_info	*info;
}	t_window;


#endif