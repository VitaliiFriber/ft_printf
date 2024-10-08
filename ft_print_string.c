/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfriber <vfriber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:38:53 by vfriber           #+#    #+#             */
/*   Updated: 2024/08/07 20:11:48 by vfriber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(char character, int *length)
{
	write(1, &character, 1);
	increment_printed_char_length(length);
}

void	increment_printed_char_length(int *length)
{
	*length += 1;
}

void	ft_print_string(char *args, int *length)
{
	size_t	i;

	i = 0;
	if (!args)
	{
		write(1, "(null)", 6);
		*length += 6;
		return ;
	}
	while (args[i] != '\0')
	{
		ft_print_char(args[i], length);
		i++;
	}
}
