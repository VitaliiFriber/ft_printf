/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfriber <vfriber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:51:33 by vfriber           #+#    #+#             */
/*   Updated: 2024/08/07 20:13:10 by vfriber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_number(int number, int *length)
{
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		*length += 11;
		return ;
	}
	if (number < 0)
	{
		ft_print_char('-', length);
		ft_print_number(number * -1, length);
	}
	else
	{
		if (number > 9)
		{
			ft_print_number(number / 10, length);
		}
		ft_print_char(number % 10 + '0', length);
	}
}

void	ft_print_hexadecimal(unsigned int x, int *length, char x_or_x)
{
	char	string[25];
	char	*base_character;
	int		i;

	i = 0;
	if (x_or_x == 'X')
		base_character = "0123456789ABCDEF";
	else
		base_character = "0123456789abcdef";
	if (x == 0)
	{
		ft_print_char('0', length);
		return ;
	}
	while (x != 0)
	{
		string[i] = base_character[x % 16];
		x = x / 16;
		i++;
	}
	while (i--)
	{
		ft_print_char(string[i], length);
	}
}

void	ft_print_unsigned_int(unsigned int u, int *length)
{
	if (u >= 10)
	{
		ft_print_unsigned_int(u / 10, length);
	}
	ft_print_char(u % 10 + '0', length);
}
