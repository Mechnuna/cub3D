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

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include "libft/libft.h"

# define S 1
# define A 0
# define D 2
# define W 13
# define ESC 53
# define AR_LEFT 123
# define AR_RIGHT 124
# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 1024
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64

struct	s_window;

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

typedef struct s_keys
{
	int	key_a;
	int	key_d;
	int	key_w;
	int	key_s;
	int	key_la;
	int	key_ra;
}			t_keys;

typedef struct s_textures
{
	void	*img_value;
	char	*img_ptr;
	int		line_len;
	int		endian;
	int		width;
	int		height;
	int		bpp;
}	t_textures;

typedef struct s_data {
	void			*img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
}				t_data;

typedef struct s_player
{
	void			*mlx;
	void			*win;
	float			pos_x;
	float			pos_y;
	float			dir_x;
	float			dir_y;
	float			plane_x;
	float			plane_y;
	float			move_speed;
	float			rot_speed;
	float			camera_x;
	float			raydir_x;
	float			raydir_y;
	float			side_dist_x;
	float			side_dist_y;
	float			delta_dist_x;
	float			delta_dist_y;
	float			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				map_x;
	int				map_y;
	float			wall_x;
	int				tex_x;
	float			step;
	float			tex_pos;
	int				tex_y;
	int				draw_start;
	int				draw_end;
	int				line_height;
	int				side;
	int				hit;
	struct s_window	*main;
	t_data			*data;
	t_textures		*txt_pxl;
	t_keys			*keys;
	struct s_txtr	*txt;
}				t_player;

typedef struct s_window
{
	int			width;
	int			high;
	char		**map;
	char		*nswe[4];
	int			floor;
	int			ceilling;
	int			player_base[2];
	char		playdir;
	t_textures	*north;
	t_textures	*south;
	t_textures	*west;
	t_textures	*east;
	t_player	*play;
}	t_window;

int		ft_handle_map(char **av, t_window *total);
void	init_txt(t_window *main);
void	free_txtr(t_window *main);
int		keypress(int keycode, t_keys *keys);
int		keyrelease(int keycode, t_keys *keys);
void	key_event(t_player *play, t_keys *keys);
int		render(t_window *game);
void	seach_draw_and_txt(t_player *play);
void	choice_txt(t_player *play, t_window *main, int x);
void	pixel_put(t_data *pixel, int x, int y, int color);
int		get_pixel_color(t_textures *txt, int x, int y);

void	move_w(t_player *play);
void	move_a(t_player *play);
void	move_s(t_player *play);
void	move_d(t_player *play);
void	rotate_l(t_player *play);
void	rotate_r(t_player *play);

void	ft_error(t_window *game, char *msg, int op);
int		ft_arrlen(char **arr);
int		free_all(void);
void	ft_free_game(t_window *game);

#endif
