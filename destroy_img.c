/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:53:21 by cle-gran          #+#    #+#             */
/*   Updated: 2022/01/09 16:12:40 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_bag_dead(t_map *map)
{
	if (map->bag)
	{
		mlx_destroy_image(map->mlx_ptr, map->bag);
		map->bag = NULL;
	}
	if (map->m_dead_turtle)
	{
		mlx_destroy_image(map->mlx_ptr, map->m_dead_turtle);
		map->m_dead_turtle = NULL;
	}
	if (map->b_dead_turtle)
	{
		mlx_destroy_image(map->mlx_ptr, map->b_dead_turtle);
		map->b_dead_turtle = NULL;
	}
	free_map(map);
}

void	destroy_happy_img(t_map *map)
{
	if (map->s_happy_turtle)
	{
		mlx_destroy_image(map->mlx_ptr, map->s_happy_turtle);
		map->s_happy_turtle = NULL;
	}
	if (map->m_happy_turtle)
	{
		mlx_destroy_image(map->mlx_ptr, map->m_happy_turtle);
		map->m_happy_turtle = NULL;
	}
	if (map->b_happy_turtle)
	{
		mlx_destroy_image(map->mlx_ptr, map->b_happy_turtle);
		map->b_happy_turtle = NULL;
	}
	destroy_bag_dead(map);
}

void	destroy_turtle_img(t_map *map)
{
	if (map->turtle_r)
	{
		mlx_destroy_image(map->mlx_ptr, map->turtle_r);
		map->turtle_r = NULL;
	}
	if (map->turtle_l)
	{
		mlx_destroy_image(map->mlx_ptr, map->turtle_l);
		map->turtle_l = NULL;
	}
	if (map->turtle_d)
	{
		mlx_destroy_image(map->mlx_ptr, map->turtle_d);
		map->turtle_d = NULL;
	}
	if (map->turtle_u)
	{
		mlx_destroy_image(map->mlx_ptr, map->turtle_u);
		map->turtle_u = NULL;
	}
	destroy_happy_img(map);
}

void	destroy_img(t_map *map)
{
	if (map->rock)
	{
		mlx_destroy_image(map->mlx_ptr, map->rock);
		map->rock = NULL;
	}
	if (map->water)
	{
		mlx_destroy_image(map->mlx_ptr, map->water);
		map->water = NULL;
	}
	if (map->fish)
	{
		mlx_destroy_image(map->mlx_ptr, map->fish);
		map->fish = NULL;
	}
	if (map->coral)
	{
		mlx_destroy_image(map->mlx_ptr, map->coral);
		map->coral = NULL;
	}
	destroy_turtle_img(map);
}
