/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:59:25 by zezzine           #+#    #+#             */
/*   Updated: 2021/11/24 21:13:26 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_putchar(char c);

void	ft_putaddr(unsigned long long nb, char type, int *count);

char	*ft_unsigned(unsigned int n);

int		ft_printf(const char *s, ...);

int		ft_putstr(char *s);

void	ft_putnbr(int nb, int *count);

void	ft_put_unsigned(unsigned int n, int *count);

#endif
