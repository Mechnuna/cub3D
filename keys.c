/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:50:57 by bbellatr          #+#    #+#             */
/*   Updated: 2022/05/29 16:50:57 by bbellatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	free_all(void)
{
	exit(EXIT_SUCCESS);
}

int	keypress(int keycode, t_keys *keys)
{
	if (keycode == ESC)
		free_all();
	if (keycode == AR_LEFT)
		keys->key_la = 1;
	if (keycode == AR_RIGHT)
		keys->key_ra = 1;
	if (keycode == S)
		keys->key_s = 1;
	if (keycode == A)
		keys->key_a = 1;
	if (keycode == D)
		keys->key_d = 1;
	if (keycode == W)
		keys->key_w = 1;
	return (0);
}

int	keyrelease(int keycode, t_keys *keys)
{
	if (keycode == AR_LEFT)
		keys->key_la = 0;
	if (keycode == AR_RIGHT)
		keys->key_ra = 0;
	if (keycode == S)
		keys->key_s = 0;
	if (keycode == A)
		keys->key_a = 0;
	if (keycode == D)
		keys->key_d = 0;
	if (keycode == W)
		keys->key_w = 0;
	return (0);
}

void	key_event(t_player *play, t_keys *keys)
{
	if (keys->key_a)
		move_a(play);
	if (keys->key_d)
		move_d(play);
	if (keys->key_s)
		move_s(play);
	if (keys->key_w)
		move_w(play);
	if (keys->key_la)
		rotate_l(play);
	if (keys->key_ra)
		rotate_r(play);
}
