/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:58:15 by a79856            #+#    #+#             */
/*   Updated: 2022/05/05 18:58:15 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "cub3d.h"

int	ft_get_path(t_info *info, char **path, char *line)
{
	int	i;
	int	size;
	int	j;

	info->counter++;
	size = ft_strlen(line);
	i = 2;
	while (line[i] && line[i] == ' ')
		i++;
	*path = malloc(sizeof(char) * (size - i + 1));
	if (!(*path))
		return (0);
	j = 0;
	while (line[i + j])
	{
		(*path)[j] = line[i + j];
		j++;
	}
	(*path)[j] = '\0';
	if (ft_check_xpm(*path))
		return (1);
	return (0);
}

int	ft_get_color(t_info *info, char *line)
{
	int	i;
	int	tmp;
	int	j;

	info->counter++;
	i = 1;
	j = 0;
	while (line[i])
	{
		while (line[i] && (line[i] == ' ' || line[i] == ','))
			i++;
		if (line[i] == '-')
			return (1);
		tmp = ft_mini_atoi(line, &i);
		if (tmp > 255 || tmp < 0)
			return (1);
		if (ft_strncmp(line, "F ", 2) == 0)
			info->floor[j] = tmp;
		else if (ft_strncmp(line, "C ", 2) == 0)
			info->ceiling[j] = tmp;
		if (line[i])
			i++;
		j++;
	}
	return (ft_check_empty_floor_ceiling(info, line));
}

int	ft_get_nsew_path(t_info *info, char *line, int j, int *ret)
{
	if (ft_strncmp(line + j, "NO ", 3) == 0)
	{
		if (ft_strlen(info->north_path) > 0)
			return (2);
		*ret = ft_get_path(info, &info->north_path, line + j);
	}
	else if (ft_strncmp(line + j, "SO ", 3) == 0)
	{
		if (ft_strlen(info->south_path) > 0)
			return (2);
		*ret = ft_get_path(info, &info->south_path, line + j);
	}
	else if (ft_strncmp(line + j, "WE ", 3) == 0)
	{
		if (ft_strlen(info->west_path) > 0)
			return (2);
		*ret = ft_get_path(info, &info->west_path, line + j);
	}
	else if (ft_strncmp(line + j, "EA ", 3) == 0)
	{
		if (ft_strlen(info->east_path) > 0)
			return (2);
		*ret = ft_get_path(info, &info->east_path, line + j);
	}
	return (0);
}

int	ft_get_first_info(t_info *info, char *line)
{
	int	j;
	int	ret;

	j = 0;
	ret = 123456789;
	while (line[j] == ' ')
		j++;
	ft_get_nsew_path(info, line, j, &ret);
	if (ret == 2)
		return (ft_write_error("There must be one and only one xpm file \
per direction.\n", 0, NULL));
	if (ft_strncmp(line + j, "F ", 2) == 0
		|| ft_strncmp(line + j, "C ", 2) == 0)
	{
		if (ft_count_commas(line, j) != 2)
			return (ft_write_error("There must be three and only three values for \
the colors.\n", 0, NULL));
		if (ft_get_color(info, line + j))
			return (ft_write_error("Colors should be three numeric values \
between 0 and 255.\n", 0, NULL));
		ret = -1;
	}
	if (ret == 1)
		return (1);
	if (ret == 123456789)
		return (ft_write_error("There must be four textures, and they must start with \
NO, SO, EA or WE.\n",
				0, NULL));
	return (0);
}

int	ft_get_info(int fd, t_info *info, int ret)
{
	char	*line;

	while (ret != 0)
	{
		ret = get_next_line(fd, &line);
		if (ft_strlen(line) == 0)
		{
			ft_free_null(&line);
			continue ;
		}
		if (ft_is_all_one(line))
			break ;
		if (ft_get_first_info(info, line))
			return (ft_free_null(&line));
		if (info->counter == 6)
			break ;
		ft_free_null(&line);
	}
	if (line)
		ft_free_null(&line);
	if (ft_check_number_of_info(info) || ft_get_original_map(fd, info))
		return (1);
	return (0);
}
