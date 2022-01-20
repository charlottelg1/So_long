/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:16:10 by cle-gran          #+#    #+#             */
/*   Updated: 2022/01/09 17:21:23 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_case(t_map *map, char c)
{
	if (c == '1' || c == 'C' || c == 'B' || c == 'P' || c == 'E')
		return (0);
	if (c == 'P')
		exit_dead(map);
	return (1);
}

int	move_bag2(t_map *map, int i, int j)
{
	if (map->moves % 3 == 0 && check_case(map, map->my_map[i + 1][j]) == 1)
	{
		map->my_map[i][j] = '0';
		if (map->my_map[i + 1][j] == 'P')
			exit_dead(map);
		map->my_map[i + 1][j] = 'B';
		return (1);
	}
	else if (check_case(map, map->my_map[i - 1][j]) == 1)
	{
		map->my_map[i][j] = '0';
		if (map->my_map[i - 1][j] == 'P')
			exit_dead(map);
		map->my_map[i - 1][j] = 'B';
		return (1);
	}
	return (0);
}

int	move_bag(t_map *map, int i, int j)
{
	if (map->moves % 5 && check_case(map, map->my_map[i][j + 1]) == 1)
	{
		map->my_map[i][j] = '0';
		if (map->my_map[i][j + 1] == 'P')
			exit_dead(map);
		map->my_map[i][j + 1] = 'B';
		return (1);
	}
	else if (map->moves % 4 == 0 && check_case(map, map->my_map[i][j - 1]) == 1)
	{
		map->my_map[i][j] = '0';
		if (map->my_map[i][j - 1] == 'P')
			exit_dead(map);
		map->my_map[i][j - 1] = 'B';
		return (1);
	}
	return (0);
}

void	find_bag(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map ->lines)
	{
		j = 0;
		while (j < map->len)
		{
			if (map->my_map[i][j] == 'B')
			{
				if (move_bag(map, i, j) == 1)
					return ;
				if (move_bag(map, i, j) == 1)
					return ;
			}
			j++;
		}
		i++;
	}
}
