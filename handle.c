/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 18:35:09 by cle-gran          #+#    #+#             */
/*   Updated: 2022/01/08 20:24:23 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle(int keysym, t_map *map)
{
	if (keysym == 65307)
		handle_esc(map);
	if (map->state == 1)
	{
		if (keysym == 97)
			move_left(map);
		else if (keysym == 119)
			move_up(map);
		else if (keysym == 100)
			move_right(map);
		else if (keysym == 115)
			move_down(map);
	}
	return (0);
}

int	handle_esc(t_map *map)
{
	destroy_img(map);
	if (map->win_ptr)
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	if (map->mlx_ptr)
	{
		mlx_destroy_display(map->mlx_ptr);
		free(map->mlx_ptr);
		map->mlx_ptr = NULL;
	}
	free_map(map);
	exit(0);
	return (0);
}
