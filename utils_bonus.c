/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:58:02 by cle-gran          #+#    #+#             */
/*   Updated: 2022/01/08 19:58:29 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_nb_moves(t_map *map)
{
	char	*str1;
	char	*str2;
	char	*count;

	str1 = "The turtle swam ";
	str2 = " times.";
	count = ft_itoa(map->moves);
	str1 = ft_strjoin2(str1, count);
	str1 = ft_strjoin(str1, str2);
	mlx_string_put(map->mlx_ptr, map->win_ptr, 16, 16, 0x00FF0000, str1);
	free(str1);
	free(count);
}
