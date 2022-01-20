/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 20:22:32 by cle-gran          #+#    #+#             */
/*   Updated: 2022/01/08 21:30:23 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_size(t_map *map)
{
	int	i;

	map->len = ft_strlen(map->my_map[0]);
	i = 1;
	while (i < map->lines)
	{
		if (ft_strlen(map->my_map[i]) != map->len)
		{
			ft_putstr("Error\nThe map is not a rectangle\n");
			free_map(map);
			exit(0);
		}
		i++;
	}
}

void	check_error_compo(int c, int p, int e, t_map *map)
{
	int	state;

	state = 0;
	if (c == 0)
	{
		ft_putstr("Error\nThere is no collectible\n");
		free_map(map);
		exit(0);
	}
	if (p != 1)
	{
		ft_putstr("Error\nThere is no or more than one starting position\n");
		free_map(map);
		exit(0);
	}
	if (e == 0)
	{
		ft_putstr("Error\nThere is no exit\n");
		free_map(map);
		exit(0);
	}
}

void	check_compo(t_map *map)
{
	int	i;
	int	c;
	int	p;
	int	e;

	i = 0;
	c = 0;
	p = 0;
	e = 0;
	while (i < map->lines)
	{
		if (ft_strchr(map->my_map[i], 'C'))
			c += ft_str_occ(map->my_map[i], 'C');
		if (ft_strchr(map->my_map[i], 'P'))
			p++;
		if (ft_strchr(map->my_map[i], 'E'))
			e++;
		i++;
	}
	check_error_compo(c, p, e, map);
	map->collectibles = c;
}

void	check_other(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->len)
		{
			if (map->my_map[i][j] != '0' && map->my_map[i][j] != '1' \
			&& map->my_map[i][j] != 'C' && map->my_map[i][j] != 'E' \
			&& map->my_map[i][j] != 'P')
			{
				ft_printf("Error\nThere is a %c in the map\n", map->my_map[i][j]);
				free_map(map);
				exit (0);
			}
			j++;
		}
		i++;
	}
	map->i = i;
	map->j = j;
}

void	check_map(t_map *map)
{
	check_size(map);
	check_compo(map);
	check_wall(map);
	check_other(map);
}
