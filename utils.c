/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 20:55:58 by cle-gran          #+#    #+#             */
/*   Updated: 2022/01/08 20:20:42 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c, int *count)
{
	(void)count;
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str, 0);
		str++;
	}
}

void	ft_putnbr(int nb, int *count)
{
	if (nb == -2147483648)
	{
		ft_putchar('-', count);
		ft_putchar('2', count);
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-', count);
		nb *= (-1);
	}
	if (nb / 10 != 0)
		ft_putnbr(nb / 10, count);
	ft_putchar((nb % 10) + '0', count);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_str_occ(char *str, char c)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == c)
			i++;
		str++;
	}
	return (i);
}
