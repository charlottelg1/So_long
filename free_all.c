/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 16:59:27 by cle-gran          #+#    #+#             */
/*   Updated: 2022/01/09 16:22:28 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->my_map)
	{
		while (i <= map->lines)
		{
			free(map->my_map[i]);
			map->my_map[i] = NULL;
			i++;
		}
		free(map->my_map);
		map->my_map = NULL;
	}
}

void	free_mlx(t_map *map)
{
	destroy_img(map);
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	mlx_destroy_display(map->mlx_ptr);
	free(map->mlx_ptr);
}
