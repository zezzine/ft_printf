/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:31:21 by zezzine           #+#    #+#             */
/*   Updated: 2021/11/24 21:47:11 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_do_work(const char s, va_list args)
{
	int	count;

	count = 0;
	if (s == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (s == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (s == 'd' || s == 'i')
		ft_putnbr(va_arg(args, int), &count);
	else if (s == 'u')
		ft_put_unsigned(va_arg(args, unsigned int), &count);
	else if (s == 'p')
	{
		count += ft_putstr("0x");
		ft_putaddr(va_arg(args, unsigned long long), 'p', &count);
	}
	else if (s == 'x')
		ft_putaddr(va_arg(args, unsigned int), 'x', &count);
	else if (s == 'X')
		ft_putaddr(va_arg(args, unsigned int), 'X', &count);
	else if (s == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int			i;
	va_list		args;
	int			count;

	i = 0;
	count = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] != '%')
			count += ft_putchar(s[i]);
		else
		{
			i++;
			count += ft_do_work(s[i], args);
		}
		i++;
	}
	va_end(args);
	return (count);
}
/*
int main()
{
	unsigned int a = -1;
	printf("%u\n", a);
	ft_printf("%u", a);
}*/