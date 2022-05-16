#include "cub3d.h"
// 0 - A S -1 W - 13 D - 2 ARR LEFT - 124 ARR RIGHT - 123 ESC 53

int	keypress(int keycode, t_window *wd)
{
	if (keycode == 53)
		exit_game(wd, 1);
	if (keycode == 123)
	{
		printf("Нажатие\n");
		wd->play->keys->la = 1;
		printf("Нажалось 1\n");
	}
	if (keycode == 124)
	{
		printf("Нажатие\n");
		wd->play->keys->ra = 1;
		printf("Нажалось 1\n");
	}
	if (keycode == 1)
	{printf("Нажатие\n");
		wd->play->keys->s = 1;
		printf("Нажалось 1\n");
	}
	if (keycode == 0)
	{ printf("Нажатие\n");
		wd->play->keys->a = 1;
		printf("Нажалось 1\n");}
	if (keycode == 2)
	{ printf("Нажатие\n");
		wd->play->keys->d = 1;
		printf("Нажалось 1\n");}
	if (keycode == 13)
	{ printf("Нажатие\n");
		wd->play->keys->w = 1;
		printf("Нажалось 1\n");}
	return (0);
}

int	keyrelease(int keycode, t_window *wd)
{
	if (keycode == 123)
	{
		printf("Перед релизом кнопки\n");
		wd->play->keys->la = 0;
		printf("Кнопка в структуре занулена\n");
	}
	if (keycode == 124)
	{printf("Перед релизом кнопки\n");
		wd->play->keys->ra = 0;
		printf("Кнопка в структуре занулена\n");}
	if (keycode == 1)
	{ printf("Перед релизом кнопки\n");
		wd->play->keys->s = 0;
		printf("Кнопка в структуре занулена\n");
	}
	if (keycode == 0)
	{ printf("Перед релизом кнопки\n");
		wd->play->keys->a = 0;
		printf("Кнопка в структуре занулена\n");}
	if (keycode == 2)
	{printf("Перед релизом кнопки\n");
		wd->play->keys->d = 0;
		printf("Кнопка в структуре занулена\n");}
	if (keycode == 13)
	{
		printf("Перед релизом кнопки\n");
		wd->play->keys->w = 0;
		printf("Кнопка в структуре занулена\n");
	}
	return (0);
}

void	key_event(t_player *play, t_keys *keys)
{
	if (keys->a)
	{
		printf("Кей ивент\n");
		move_a(play);
		printf("Кей ивент выполнен\n");

	}
	if (keys->d)
	{printf("Кей ивент\n");
		move_d(play);
		printf("Кей ивент выполнен\n");
	}
	if (keys->s)
	{printf("Кей ивент\n");
		move_s(play);
		printf("Кей ивент выполнен\n");
	}
	if (keys->w)
	{printf("Кей ивент\n");
		move_w(play);
		printf("Кей ивент выполнен\n");}
	if (keys->la)
	{
		{ printf("Кей ивент\n");
			rotate_l(play);
			printf("Кей ивент выполнен\n");
		}
	}
	if (keys->ra)
	{
		printf("Кей ивент\n");
		rotate_r(play);
		printf("Кей ивент выполнен\n");
	}
}