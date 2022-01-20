/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 15:21:55 by cle-gran          #+#    #+#             */
/*   Updated: 2022/01/12 16:37:08 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_map *map)
{
	map->lines = 0;
	map->state = 1;
	map->my_map = NULL;
	map->mlx_ptr = NULL;
	map->win_ptr = NULL;
	map->turtle_r = NULL;
	map->turtle_l = NULL;
	map->turtle_d = NULL;
	map->turtle_u = NULL;
	map->s_happy_turtle = NULL;
	map->m_happy_turtle = NULL;
	map->m_happy_turtle = NULL;
	map->m_dead_turtle = NULL;
	map->b_dead_turtle = NULL;
	map->bag = NULL;
	map->rock = NULL;
	map->water = NULL;
	map->fish = NULL;
	map->coral = NULL;
	map->last = 'D';
	map->i = 0;
	map->j = 0;
	map->moves = 0;
	map->collectibles = 0;
}
