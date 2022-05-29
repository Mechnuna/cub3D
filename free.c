/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:50:39 by bbellatr          #+#    #+#             */
/*   Updated: 2022/05/29 16:50:39 by bbellatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_txtr(t_window *main)
{
	if (main->west)
		free(main->west);
	if (main->east)
		free(main->east);
	if (main->north)
		free(main->north);
	if (main->south)
		free(main->south);
}

void	free_all_raycast(t_window *main)
{
	if (main->play->keys)
		free(main->play->keys);
	free_txtr(main);
	mlx_destroy_image(main->play->mlx, main->play->data->img);
	mlx_destroy_window(main->play->mlx, main->play->win);
	if (main->play->data)
		free(main->play->data);
	if (main->play)
		free(main->play);
}

char	**ft_free_arr(char **arr, int ln)
{
	int	i;

	if (arr != NULL)
	{
		i = 0;
		while (i < ln)
		{
			if (arr[i] != NULL)
			{
				ft_bzero(arr[i], ft_strlen(arr[i]));
				free(arr[i]);
			}
			i++;
		}
		ft_bzero(arr, sizeof(char *));
		free(arr);
	}
	return (NULL);
}

void	ft_free_game(t_window *game)
{
	int	i;

	if (game != NULL)
	{
		if (game->map != NULL)
			ft_free_arr(game->map, ft_arrlen(game->map));
		i = 0;
		while (i < 4)
		{
			if (game->nswe[i] != NULL)
				free(game->nswe[i]);
			i++;
		}
		ft_bzero(game->nswe, sizeof(char *) * 4);
		free_all_raycast(game);
		ft_bzero(game, sizeof(t_window));
		free(game);
	}
}

void	ft_error(t_window *game, char *msg, int op)
{
	ft_putstr_fd("Error\n", 2);
	if (op == 0)
		ft_putstr_fd(msg, 2);
	if (op == 1)
		perror(msg);
	ft_free_game(game);
	exit(EXIT_FAILURE);
}
