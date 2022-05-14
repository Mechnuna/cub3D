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
#include <errno.h>
#include <math.h>
#include <mlx.h>
#include <fcntl.h>
#include "libft/libft.h"

# define PI					3.141592653589793
# define MINI_TILE_SIZE		10

struct s_window;

typedef struct s_keys
{
	int 	w;
	int 	a;
	int 	s;
	int 	d;
	int 	la;
	int 	ra;
}	t_keys;

typedef struct s_texture
{
	void	*img_val;
	char	*img_ptr;
	int 	line_len;
	int 	endian;
	int 	width;
	int 	height;
	int 	bpp;
}	t_texture;

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
	float 	dir_x;
	float 	dir_y;
	char	orientation;
	int		pos_map_x;
	int		pos_map_y;
	float 	pos_pix_x;
	float 	pos_pix_y;
	int		mov_up;
	int		mov_down;
	int		mov_left;
	int		mov_right;
	int		rot_left;
	int		rot_right;
	int		turn_direction;
	int		axis_direction;
	int		lat_direction;
	float 	rotation_angle;
	float 	move_speed;
	float 	rotation_speed;
	int		mouse_moving;
	//new
	float			camera;
	float			plane_x;
	float			plane_y;
	float			wall;
	int 			tex_x;
	int 			tex_y;
	float			raydir_x;
	float			raydir_y;
	float			delta_dist_x;
	float			delta_dist_y;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	float			side_dist_x;
	float			side_dist_y;
	int				side;
	int				hit;
	float			perp_wall_dist;
	int				line_height;
	int				draw_start;
	int				draw_end;
	float			step;
	float			text_pos;
	t_keys 			*keys;
	struct s_window	*main;
}				t_player;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_player	*play;
	t_data	*img;
	t_info	*info;
	//new
	int 	player_base[2];
	char	direct;
	char	*nswe[4];
	int			floor;
	int			ceilling;
	t_texture *north;
	t_texture *south;
	t_texture *west;
	t_texture *east;
}	t_window;

//erroren
void	erroren(t_window *window, char *str, int perr);
void	exit_game(t_window *window, int flag);
void	ft_free(t_window *window);
//parse
int		ft_handle_map(char **av, t_window *total);
//inits
void	init_rc(t_window *window, t_player *play);
//textures

//keys
int		keypress(int keycode, t_window *wd);
int		keyrelease(int keycode, t_window *wd);
void	key_event(t_player *play, t_keys *keys);
//movements
void	move_w(t_player *play);
void	move_a(t_player *play);
void	move_s(t_player *play);
void	move_d(t_player *play);
void	rotate_r(t_player *play);
void	rotate_l(t_player *play);
//raycast
int	render(t_window *wd);
void	seach_draw_and_txt(t_player *play);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int get_pixel_color(t_texture *text, int x, int y);
void	choice_texture(t_player *play, t_window *wd, int x);
//parser

#endif