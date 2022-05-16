/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:29:50 by a79856            #+#    #+#             */
/*   Updated: 2022/05/05 19:30:05 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

///////////////////////////////////

void	ft_initialiser_ceil_and_floor(t_window *total)
{
	total->mlx_ptr = 0;
	total->win_ptr = 0;
	//total->info->total = total;
	total->info->floor[0] = -1;
	total->info->floor[1] = -1;
	total->info->floor[2] = -1;
	total->info->ceiling[0] = -1;
	total->info->ceiling[1] = -1;
	total->info->ceiling[2] = -1;
}

int	ft_initialiser_info(char **av, t_window *total)
{
	int	i;

	ft_bzero(total->info, sizeof(t_info));
	total->info->av = av[1];
	ft_initialiser_ceil_and_floor(total);
	ft_bzero(total->play, sizeof(t_player));
	return (0);
}

//проверка на расширение .куб
int	ft_check_cub(char *av)
{
	int	size;

	size = ft_strlen(av);
	if ((size < 5) || (av[size - 1] != 'b') || (av[size - 2] != 'u')
		|| (av[size - 3] != 'c') || (av[size - 4] != '.'))
		erroren(NULL, "The map must have a .cub extension.\n", 0);
	return (0);
}

int	ft_handle_map(char **av, t_window *total)
{
	int	fd;

	//if (ft_initialiser_info(av, total))
		//return (1);
	if (ft_check_cub(av[1]) == 1)
		return (1);
	//fd = ft_open(av[1]);
	//if (fd == 0)
		//return (erroen(total, "Open failed.\n", 1));
	//if (ft_get_info(fd, info, 1))
		//return (ft_free(info));
	//if (ft_check_original_map(info))
		//return (ft_free(info));
	//ft_clean_map(info);
	//close(fd);
	return (0);
}
