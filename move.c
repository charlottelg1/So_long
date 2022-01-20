/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 20:04:05 by cle-gran          #+#    #+#             */
/*   Updated: 2022/01/08 21:15:22 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_position(t_map *map, int a, int b)
{
	int	i;
	int	j;

	i = map->i;
	j = map->j;
	map->my_map[i][j] = '0';
	map->my_map[a][b] = 'P';
}

void	move_right(t_map *map)
{
	int	i;
	int	j;

	get_position(map);
	i = map->i;
	j = map->j;
	map->moves++;
	if (map->my_map[i][j + 1] == 'C')
		map->collectibles--;
	if (map->my_map[i][j + 1] == '0' || map->my_map[i][j + 1] == 'C')
		move_position(map, i, j + 1);
	if (map->my_map[i][j + 1] == 'E' && map->collectibles == 0)
		move_exit_happy(map);
	if (map->my_map[i][j + 1] == 'B')
		move_exit_dead(map);
	map->last = 'D';
	find_bag(map);
	if (map->state != 0)
		ft_image_to_window(map);
}

void	move_left(t_map *map)
{
	int	i;
	int	j;

	get_position(map);
	i = map->i;
	j = map->j;
	map->moves++;
	if (map->my_map[i][j - 1] == 'C')
		map->collectibles--;
	if (map->my_map[i][j - 1] == '0' || map->my_map[i][j - 1] == 'C')
		move_position(map, i, j - 1);
	if (map->my_map[i][j - 1] == 'E' && map->collectibles == 0)
		move_exit_happy(map);
	if (map->my_map[i][j - 1] == 'B')
		move_exit_dead(map);
	map->last = 'A';
	find_bag(map);
	if (map->state != 0)
		ft_image_to_window(map);
}

void	move_up(t_map *map)
{
	int	i;
	int	j;

	get_position(map);
	i = map->i;
	j = map->j;
	map->moves++;
	if (map->my_map[i - 1][j] == 'C')
		map->collectibles--;
	if (map->my_map[i - 1][j] == '0' || map->my_map[i - 1][j] == 'C')
		move_position(map, i - 1, j);
	if (map->my_map[i - 1][j] == 'E' && map->collectibles == 0)
		move_exit_happy(map);
	if (map->my_map[i - 1][j] == 'B')
		move_exit_dead(map);
	map->last = 'W';
	find_bag(map);
	if (map->state != 0)
		ft_image_to_window(map);
}

void	move_down(t_map *map)
{
	int	i;
	int	j;

	get_position(map);
	i = map->i;
	j = map->j;
	map->moves++;
	if (map->my_map[i + 1][j] == 'C')
		map->collectibles--;
	if (map->my_map[i + 1][j] == '0' || map->my_map[i + 1][j] == 'C')
		move_position(map, i + 1, j);
	if (map->my_map[i + 1][j] == 'E' && map->collectibles == 0)
		move_exit_happy(map);
	if (map->my_map[i + 1][j] == 'B')
		move_exit_dead(map);
	map->last = 'S';
	find_bag(map);
	if (map->state != 0)
		ft_image_to_window(map);
}
