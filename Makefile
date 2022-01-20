NAME = so_long

NAME_BONUS = bonus

SRCS = main.c \
	init.c \
	create_map.c \
	check_map.c \
	move.c \
	image.c \
	handle.c \
	check_walls.c \
	position.c \
	utils.c \
	free_all.c \
	get_next_line.c \
	gnl_utils.c \
	itoa.c \
	move_bag.c \
	exit.c \
	destroy_img.c \
	ft_printf.c \

BONUS = main.c \
	init.c \
	create_map.c \
	check_map_bonus.c \
	move.c \
	image_bonus.c \
	handle.c \
	check_walls.c \
	position.c \
	utils.c \
	free_all.c \
	get_next_line.c \
	gnl_utils.c \
	itoa.c \
	move_bag.c \
	exit.c \
	utils_bonus.c \
	destroy_img.c \
	ft_printf.c \

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${BONUS:.c=.o}

CC = clang

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g

FL_MLX = -ldl -lmlx -Lmlx -lm -lXext -lX11

all : ${NAME}

$(NAME) : $(OBJS)
	make -s -C ./mlx
	${CC} ${CFLAGS} -I INCLUDES ${SRCS} -o ${NAME} $(FL_MLX)

${NAME_BONUS} : ${OBJS_BONUS}
	make -s -C ./mlx
	${CC} ${CFLAGS} -I includes ${BONUS} -o ${NAME_BONUS} $(FL_MLX)

%.o:%.c
	${CC} ${FLAGS} -Imlx -Ibass -I includes -o $@ -c $<

clean :
	${RM} ${OBJS} ${OBJS_BONUS}

fclean : clean
	${RM} ${NAME} ${NAME_BONUS}

re : fclean all

.PHONY : clean fclean re
