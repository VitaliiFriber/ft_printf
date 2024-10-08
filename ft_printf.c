/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfriber <vfriber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:55:26 by vfriber           #+#    #+#             */
/*   Updated: 2024/08/07 20:11:27 by vfriber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_switch(char s, va_list *args, int *len)
{
	if (s == 's')
		ft_print_string(va_arg(*args, char *), len);
	else if (s == 'd' || s == 'i')
		ft_print_number(va_arg(*args, int), len);
	else if (s == 'u')
		ft_print_unsigned_int(va_arg(*args, unsigned int), len);
	else if (s == 'x')
		ft_print_hexadecimal(va_arg(*args, unsigned int), len, 'x');
	else if (s == 'X')
		ft_print_hexadecimal(va_arg(*args, unsigned int), len, 'X');
	else if (s == 'p')
		ft_print_pointer(va_arg(*args, size_t), len);
	else if (s == 'c')
		ft_print_char(va_arg(*args, int), len);
	else if (s == '%')
		ft_print_char('%', len);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			ft_printf_switch(string[i], &args, &length);
			i++;
		}
		else
		{
			ft_print_char((char)string[i], &length);
			i++;
		}
	}
	va_end(args);
	return (length);
}
