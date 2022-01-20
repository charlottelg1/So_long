/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 19:03:14 by cle-gran          #+#    #+#             */
/*   Updated: 2022/01/08 19:54:08 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_c(va_list ap, int *count)
{
	int	c;

	c = va_arg(ap, int);
	ft_putchar(c, count);
}

void	ft_s(va_list ap, int *count)
{
	char	*s;

	s = va_arg(ap, char *);
	if (s == NULL)
		s = "(null)";
	while (*s)
	{
		ft_putchar(*s, count);
		s++;
	}
}

void	ft_di(va_list ap, int *count)
{
	int	d;

	d = va_arg(ap, int);
	ft_putnbr(d, count);
}

void	ft_spec(const char *format, int *count, va_list ap)
{
	format++;
	if (*format == 'c')
		ft_c(ap, count);
	else if (*format == 's')
		ft_s(ap, count);
	else if ((*format == 'd') || (*format == 'i'))
		ft_di(ap, count);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			ft_spec(format, &count, ap);
			format++;
		}
		else
			ft_putchar(*format, &count);
		format++;
	}
	va_end(ap);
	return (0);
}
