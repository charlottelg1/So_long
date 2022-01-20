/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 20:50:05 by cle-gran          #+#    #+#             */
/*   Updated: 2022/01/09 16:09:41 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	no_ber(char *av)
{
	char	*ext;
	int		state;
	int		i;
	int		j;

	ext = "ber";
	state = 0;
	i = 0;
	j = 0;
	while (av[i] != '\0')
	{
		if (av[i] != '.')
			i++;
		else
		{
			i++;
			while (av[i + j] && ext[j] && av[i + j] == ext[j])
				j++;
			if (j == 3 && av[i + 3] == '\0')
				state = 1;
		}
	}
	return (state);
}

void	check_error_arg(int ac, char *av)
{
	int	state;
	int	fd;

	state = 0;
	if (ac != 2)
	{
		ft_putstr("Error\nYou put in the wrong amount of argument(s)\n");
		exit(0);
	}
	state = no_ber(av);
	if (state == 0)
	{
		ft_putstr("Error\nYour argument is not a .ber file\n");
		exit(0);
	}
	fd = open(av, O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		ft_putstr("Error\nYour argument is a directory\n");
		exit(0);
	}
}

void	start_mlx(t_map *map)
{
	int	i;

	i = 131072;
	map->mlx_ptr = mlx_init();
	if (map->mlx_ptr == NULL)
	{
		free_map(map);
		ft_putstr("Error\nThe initialization of the mlx failed\n");
		exit(0);
	}
	map->win_ptr = mlx_new_window(map->mlx_ptr, 64 * map->len, \
	64 * map->lines, TITLE);
	if (map->win_ptr == NULL)
	{
		mlx_destroy_display(map->mlx_ptr);
		free(map->mlx_ptr);
		free_map(map);
		ft_putstr("Error\nThe initialization of the window failed\n");
		exit(0);
	}
	ft_file_to_img(map);
	ft_image_to_window(map);
	mlx_hook(map->win_ptr, KeyPress, KeyPressMask, &handle, map);
	mlx_hook(map->win_ptr, 33, i, &handle_esc, map);
	mlx_loop(map->mlx_ptr);
}

int	main(int ac, char **av)
{
	t_map	map;

	check_error_arg(ac, av[1]);
	init_map(&map);
	count_lines(&map, av[1]);
	build_map(&map, av[1]);
	check_map(&map);
	start_mlx(&map);
	free_map(&map);
	return (0);
}
