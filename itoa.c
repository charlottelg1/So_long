/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:38:48 by cle-gran          #+#    #+#             */
/*   Updated: 2022/01/07 19:40:46 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static unsigned int	len_num(int n)
{
	unsigned int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n *= -1;
	}
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*result;
	unsigned int	len;
	long			nb;

	nb = (long)n;
	len = len_num(nb);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	if (nb == 0)
		result[0] = '0';
	if (nb < 0)
	{
		nb *= (-1);
		result[0] = '-';
	}
	result[len--] = '\0';
	while (nb > 0)
	{
		result[len--] = (nb % 10) + 48;
		nb /= 10;
	}
	return (result);
}
