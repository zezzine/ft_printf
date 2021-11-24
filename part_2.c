/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:54:23 by zezzine           #+#    #+#             */
/*   Updated: 2021/11/24 20:30:51 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (s[i])
		ft_putchar(s[i++]);
	return (i);
}

static int	len_int(unsigned int i)
{
	int	count;

	count = 0;
	if (i == 0)
		return (1);
	while (i != 0)
	{
		i /= 10;
		count++;
	}
	return (count);
}

char	*ft_unsigned(unsigned int n)
{
	char			*res;
	int				len;

	len = len_int(n);
	res = (char *) malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (n > 0)
	{
		res[--len] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}
