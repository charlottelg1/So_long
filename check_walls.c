/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:39:42 by cle-gran          #+#    #+#             */
/*   Updated: 2022/01/08 19:48:03 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_wall_sides(t_map *map, unsigned int len)
{
	int	i;

	i = 0;
	while (i < map->lines)
	{
		if (map->my_map[i][0] != '1' || map->my_map[i][len - 1] != '1')
		{
			free_map(map);
			ft_putstr("Error\nThere is a hole in the walls\n");
			exit(0);
		}
		i++;
	}
}

void	check_wall(t_map *map)
{
	int	j;
	int	len;

	j = 0;
	len = ft_strlen(map->my_map[0]);
	while (j < len)
	{
		if (map->my_map[0][j] != '1' || map->my_map[map->lines - 1][j] != '1')
		{
			free_map(map);
			ft_putstr("Error\nThere is a hole in the walls\n");
			exit (0);
		}
		j++;
	}
	check_wall_sides(map, len);
}
