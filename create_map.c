/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 20:14:51 by cle-gran          #+#    #+#             */
/*   Updated: 2022/01/08 19:49:54 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_close(t_map *map, int fd)
{
	if (close(fd) == -1)
	{
		ft_putstr("Error\nThe file did not close properly\n");
		free_map(map);
		exit(0);
	}
}

void	count_lines(t_map *map, char *av)
{
	int		fd;
	int		ret;
	char	*line;

	ret = 1;
	fd = open(av, O_RDONLY, O_DIRECTORY);
	line = NULL;
	if (fd == -1)
	{
		ft_putstr("Error\nThe file did not open properly\n");
		free_map(map);
		exit(0);
	}
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		free(line);
		if (ret > 0)
			map->lines++;
	}
	ft_close(map, fd);
}

void	build_map(t_map *map, char *av)
{
	int		fd;
	int		ret;
	int		i;

	ret = 1;
	i = 0;
	fd = open(av, O_RDONLY);
	map->my_map = (char **)malloc(sizeof(char *) * (map->lines + 1));
	if (!map->my_map)
		return ;
	if (fd == -1)
	{
		ft_putstr("Error\nThe file did not open properly\n");
		free_map(map);
		exit(0);
	}
	while (ret > 0)
	{
		ret = get_next_line(fd, &map->my_map[i]);
		i++;
	}
	ft_close(map, fd);
}
