#include "cub3d.h"

int fre_all(void)
{
	exit(EXIT_SUCCESS);
}

void	exit_game(t_window *window, int flag)
{

}

void	ft_free(t_window *window)
{

}

void	erroren(t_window *window, char *str, int perr)
{
	ft_putstr_fd("Error: ", 2);
	if (perr == 0)
		ft_putstr_fd(str, 2);
	else
		perror(str);
	ft_free(window);
	exit(EXIT_FAILURE);
}