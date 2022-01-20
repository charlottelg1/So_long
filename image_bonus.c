/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 18:37:04 by cle-gran          #+#    #+#             */
/*   Updated: 2022/01/15 18:17:43 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	direction_turtle(t_map *map, int i, int j)
{
	if (map->last == 'D')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, \
		map->turtle_r, j * 64, i * 64);
	else if (map->last == 'A')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, \
		map->turtle_l, j * 64, i * 64);
	else if (map->last == 'W')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, \
		map->turtle_u, j * 64, i * 64);
	else if (map->last == 'S')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, \
		map->turtle_d, j * 64, i * 64);
	ft_printf("The turtle swam %d times.\n", map->moves);
}

void	ft_image_to_window2(t_map *map, int i, int j)
{
	if (map->my_map[i][j] == 'B')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->bag, \
		j * 64, i * 64);
	else if (map->my_map[i][j] == '0')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->water, \
		j * 64, i * 64);
	else if (map->my_map[i][j] == '1')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->rock, \
		j * 64, i * 64);
}

void	ft_image_to_window(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->len)
		{
			if (map->my_map[i][j] == 'P')
				direction_turtle(map, i, j);
			else if (map->my_map[i][j] == 'C')
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->fish, \
				j * 64, i * 64);
			else if (map->my_map[i][j] == 'E')
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->coral, \
				j * 64, i * 64);
			ft_image_to_window2(map, i, j);
			j++;
		}
		i++;
	}
	put_nb_moves(map);
}

void	*each_file_to_img(t_map *map, void *img_ptr, char *path)
{
	int	height;
	int	width;

	img_ptr = mlx_xpm_file_to_image(map->mlx_ptr, path, &height, &width);
	if (img_ptr == NULL)
	{
		ft_printf("Error\nThe display of %s failed\n", path);
		destroy_img(map);
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		mlx_destroy_display(map->mlx_ptr);
		free(map->mlx_ptr);
		map->mlx_ptr = NULL;
		free_map(map);
		exit(0);
	}
	return (img_ptr);
}

void	ft_file_to_img(t_map *map)
{
	map->turtle_r = each_file_to_img(map, map->turtle_r, TURTLE_R_PATH);
	map->turtle_l = each_file_to_img(map, map->turtle_l, TURTLE_L_PATH);
	map->turtle_d = each_file_to_img(map, map->turtle_d, TURTLE_D_PATH);
	map->turtle_u = each_file_to_img(map, map->turtle_u, TURTLE_U_PATH);
	map->s_happy_turtle = each_file_to_img(map, \
	map->s_happy_turtle, S_HAPPY_PATH);
	map->m_happy_turtle = each_file_to_img(map, \
	map->m_happy_turtle, M_HAPPY_PATH);
	map->b_happy_turtle = each_file_to_img(map, \
	map->b_happy_turtle, B_HAPPY_PATH);
	map->rock = each_file_to_img(map, map->rock, ROCK_PATH);
	map->coral = each_file_to_img(map, map->coral, CORAL_PATH);
	map->fish = each_file_to_img(map, map->fish, FISH_PATH);
	map->water = each_file_to_img(map, map->water, WATER_PATH);
	map->bag = each_file_to_img(map, map->bag, BAG_PATH);
	map->m_dead_turtle = each_file_to_img(map, map->m_dead_turtle, M_DEAD_PATH);
	map->b_dead_turtle = each_file_to_img(map, map->b_dead_turtle, B_DEAD_PATH);
}
