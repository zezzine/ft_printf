/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:30:03 by zezzine           #+#    #+#             */
/*   Updated: 2021/11/24 21:12:58 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, int *count)
{
	unsigned int	n;

	if (nb < 0)
	{
		*count += ft_putchar('-');
		n = nb * -1;
	}
	else
		n = nb;
	if (n > 9)
	{
		ft_putnbr(n / 10, count);
		*count += ft_putchar((n % 10) + '0');
	}
	else
		*count += ft_putchar(n + '0');
}

void	ft_put_unsigned(unsigned int n, int *count)
{
	if (n > 9)
	{
		ft_putnbr(n / 10, count);
		*count += ft_putchar((n % 10) + '0');
	}
	else
		*count += ft_putchar(n + '0');
}

static void	ft_puthex(unsigned long long nb, char *base, int *count)
{
	if (nb >= 16)
	{
		ft_puthex(nb / 16, base, count);
	}
	*count += ft_putchar(base[nb % 16]);
}

void	ft_putaddr(unsigned long long nb, char type, int *count)
{
	if (type == 'x' || type == 'p')
		ft_puthex(nb, "0123456789abcdef", count);
	else if (type == 'X')
		ft_puthex(nb, "0123456789ABCDEF", count);
}
/*
#include<stdio.h>
int	main(void)
{
	unsigned int	a;

	a = -125545714;
	printf("%u\n", a);
	printf("%s", ft_unsigned(a));
}*/