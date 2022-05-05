/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 03:07:25 by a79856            #+#    #+#             */
/*   Updated: 2022/05/05 19:28:20 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "minilibx_mms_202002199/mlx.h"

# define PI					3.141592653589793
# define MINI_TILE_SIZE		10

struct s_window;

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
	struct t_window	*total;
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
	double	dir_x;
	double	dir_y;
	char	orientation;
	int		pos_map_x;
	int		pos_map_y;
	double	pos_pix_x;
	double	pos_pix_y;
	int		mov_up;
	int		mov_down;
	int		mov_left;
	int		mov_right;
	int		rot_left;
	int		rot_right;
	int		turn_direction;
	int		axis_direction;
	int		lat_direction;
	double	rotation_angle;
	double	move_speed;
	double	rotation_speed;
	int		mouse_moving;
}				t_player;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_player	*play;
	t_data	*img;
	t_info	*info;
}	t_window;


#endif