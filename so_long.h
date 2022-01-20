/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:22:42 by cle-gran          #+#    #+#             */
/*   Updated: 2022/01/15 17:44:47 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <X11/Xlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define BUFFER_SIZE 1
# define TITLE "The Turtle Game"
# define TURTLE_R_PATH "img/turtle_r.xpm"
# define TURTLE_U_PATH "img/turtle_u.xpm"
# define TURTLE_L_PATH "img/turtle_l.xpm"
# define TURTLE_D_PATH "img/turtle_d.xpm"
# define S_HAPPY_PATH "img/s_happy_turtle.xpm"
# define M_HAPPY_PATH "img/m_happy_turtle.xpm"
# define B_HAPPY_PATH "img/b_happy_turtle.xpm"
# define M_DEAD_PATH "img/m_dead_turtle.xpm"
# define B_DEAD_PATH "img/b_dead_turtle.xpm"
# define BAG_PATH "img/bag.xpm"
# define ROCK_PATH "img/rock.xpm"
# define FISH_PATH "img/fish.xpm"
# define CORAL_PATH "img/coral.xpm"
# define WATER_PATH "img/water.xpm"

typedef struct s_map
{
	int		lines;
	int		len;
	char	last;
	int		moves;
	int		state;
	int		collectibles;
	int		i;
	int		j;
	char	**my_map;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*turtle_r;
	void	*turtle_l;
	void	*turtle_d;
	void	*turtle_u;
	void	*s_happy_turtle;
	void	*m_happy_turtle;
	void	*b_happy_turtle;
	void	*m_dead_turtle;
	void	*b_dead_turtle;
	void	*bag;
	void	*rock;
	void	*water;
	void	*fish;
	void	*coral;
}				t_map;

/*MAIN*/
int		main(int ac, char **av);

/*CREATE MAP*/
void	count_lines(t_map *map, char *av);
void	build_map(t_map *map, char *av);
void	init_map(t_map *map);

/*CHECK MAP & WALLS*/
void	check_map(t_map *map);
void	check_size(t_map *map);
void	check_compo(t_map *map);
void	check_wall(t_map *map);
void	check_wall_sides(t_map *map, unsigned int len);

/*POSITION*/
void	get_position(t_map *map);

/*INIT MLX*/
void	init_mlx(t_map *map);

/*IMAGE*/
void	ft_image_to_window(t_map *map);
void	*each_file_to_img(t_map *map, void *img_ptr, char *path);
void	ft_file_to_img(t_map *map);

/*HANDLE*/
int		handle_esc(t_map *map);
int		handle(int keysym, t_map *map);

/*MOVE*/
void	move_left(t_map *map);
void	move_right(t_map *map);
void	move_down(t_map *map);
void	move_up(t_map *map);
void	find_bag(t_map *map);
int		move_bag(t_map *map, int i, int j);

/*UTILS*/
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_printf(const char *format, ...);
void	ft_putnbr(int nb, int *count);
int		ft_str_occ(char *str, char c);
char	*ft_itoa(int n);

/*GNL*/
int		get_next_line(int fd, char **line);
char	*ft_strdup(char *str);
char	*ft_strchr(char *str, char n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoin2(char *s1, char *s2);
void	ft_putchar(char c, int *count);

/*EXIT*/
void	exit_dead(t_map *map);
void	exit_happy(t_map *map);
void	move_exit_dead(t_map *map);
void	move_exit_happy(t_map *map);

/*FREE*/
void	free_map(t_map *map);
void	free_mlx(t_map *map);
void	destroy_img(t_map *map);

/*BONUS*/
void	put_nb_moves(t_map *map);

#endif
