#include "cub3d.h"
// 0 - A S -1 W - 13 D - 2 ARR LEFT - 124 ARR RIGHT - 123 ESC 53

int	keypress(int keycode, t_window *wd)
{
	if (keycode == 53)
		exit_game(wd, 1);
	if (keycode == 123)
	{
		printf("2\n");
		wd->play->keys->la = 1;
		printf("2\n");
	}
	if (keycode == 124)
	{
		printf("2\n");
		wd->play->keys->ra = 1;
		printf("2\n");
	}
	if (keycode == 1)
	{printf("2\n");
		wd->play->keys->s = 1;
		printf("2\n");
	}
	if (keycode == 0)
	{ printf("2\n");
		wd->play->keys->a = 1;
		printf("2\n");}
	if (keycode == 2)
	{ printf("2\n");
		wd->play->keys->d = 1;
		printf("2\n");}
	if (keycode == 13)
	{ printf("2\n");
		wd->play->keys->w = 1;
		printf("2\n");}
	return (0);
}

int	keyrelease(int keycode, t_window *wd)
{
	if (keycode == 123)
	{
		printf("3\n");
		wd->play->keys->la = 0;
		printf("3\n");
	}
	if (keycode == 124)
	{printf("3\n");
		wd->play->keys->ra = 0;
		printf("3\n");}
	if (keycode == 1)
	{ printf("3\n");
		wd->play->keys->s = 0;
		printf("3\n");
	}
	if (keycode == 0)
	{ printf("3\n");
		wd->play->keys->a = 0;
		printf("3\n");}
	if (keycode == 2)
	{printf("3\n");
		wd->play->keys->d = 0;
		printf("3\n");}
	if (keycode == 13)
	{
		printf("3\n");
		wd->play->keys->w = 0;
		printf("3\n");
	}
	return (0);
}

void	key_event(t_player *play, t_keys *keys)
{
	if (keys->a)
	{
		printf("4\n");
		move_a(play);
		printf("5\n");

	}
	if (keys->d)
	{printf("4\n");
		move_d(play);
		printf("5\n");
	}
	if (keys->s)
	{printf("4\n");
		move_s(play);
		printf("5\n");
	}
	if (keys->w)
	{printf("4\n");
		move_w(play);
		printf("5\n");}
	if (keys->la)
	{
		{ printf("4\n");
			rotate_l(play);
			printf("5\n");
		}
	}
	if (keys->ra)
	{
		rotate_r(play);
	}
}