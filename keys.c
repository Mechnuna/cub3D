#include "cub3d.h"
// 0 - A S -1 W - 13 D - 2 ARR LEFT - 124 ARR RIGHT - 123 ESC 53

int	keypress(int keycode, t_window *wd)
{
	if (keycode == 53)
		exit_game(wd, 1);
	if (keycode == 123)
		wd->play->keys->la = 1;
	if (keycode == 124)
		wd->play->keys->ra = 1;
	if (keycode == 1)
		wd->play->keys->s = 1;
	if (keycode == 0)
		wd->play->keys->a = 1;
	if (keycode == 2)
		wd->play->keys->d = 1;
	if (keycode == 13)
		wd->play->keys->w= 1;
	return (0);
}

int	keyrelease(int keycode, t_window *wd)
{
	if (keycode == 123)
		wd->play->keys->la = 0;
	if (keycode == 124)
		wd->play->keys->ra = 0;
	if (keycode == 1)
		wd->play->keys->s = 0;
	if (keycode == 0)
		wd->play->keys->a = 0;
	if (keycode == 2)
		wd->play->keys->d = 0;
	if (keycode == 13)
		wd->play->keys->w = 0;
	return (0);
}

void	key_event(t_player *play, t_keys *keys)
{
	if (keys->a)
		move_a(play);
	if (keys->d)
		move_d(play);
	if (keys->s)
		move_s(play);
	if (keys->w)
		move_w(play);
	if (keys->la)
		rotate_l(play);
	if (keys->ra)
		rotate_r(play);
}