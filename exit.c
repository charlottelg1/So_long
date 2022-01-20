/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:15:02 by cle-gran          #+#    #+#             */
/*   Updated: 2022/01/15 18:03:58 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_happy(t_map *map)
{
	if (map->len == 5 && map->lines <= 3)
	{
		mlx_put_image_to_window(map->mlx_ptr, \
		map->win_ptr, map->s_happy_turtle, 0, 0);
		map->state = 0;
	}
	else if (map->len == 10 && map->lines <= 6)
	{
		mlx_put_image_to_window(map->mlx_ptr, \
		map->win_ptr, map->m_happy_turtle, 0, 0);
		map->state = 0;
	}
	else if (map->len == 15 && map->lines <= 10)
	{
		mlx_put_image_to_window(map->mlx_ptr, \
		map->win_ptr, map->b_happy_turtle, 0, 0);
		map->state = 0;
	}
	else
		handle_esc(map);
}

void	exit_dead(t_map *map)
{
	if (map->len == 10 && map->lines <= 7)
	{
		mlx_put_image_to_window(map->mlx_ptr, \
		map->win_ptr, map->m_dead_turtle, 0, 0);
		map->state = 0;
	}
	else if (map->len == 15 && map->lines <= 11)
	{
		mlx_put_image_to_window(map->mlx_ptr, \
		map->win_ptr, map->b_dead_turtle, 0, 0);
		map->state = 0;
	}
	else
		handle_esc(map);
}

void	move_exit_happy(t_map *map)
{
	if (map->len == 10 || map->len == 5 || map->len == 15)
	{
		exit_happy(map);
		return ;
	}
	else
		handle_esc(map);
}

void	move_exit_dead(t_map *map)
{
	if (map->len == 10 || map->len == 5 || map->len == 15)
	{
		exit_dead(map);
		return ;
	}
	else
		handle_esc(map);
}
