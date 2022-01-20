/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 19:24:54 by cle-gran          #+#    #+#             */
/*   Updated: 2022/01/08 20:20:06 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_position(t_map *map)
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
			if (map->my_map[i][j] == 'P')
				break ;
			else
				j++;
		}
		if (map->my_map[i][j] == 'P')
			break ;
		else
			i++;
	}
	map->i = i;
	map->j = j;
}
