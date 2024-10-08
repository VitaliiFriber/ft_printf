/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfriber <vfriber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:39:06 by vfriber           #+#    #+#             */
/*   Updated: 2024/09/09 23:00:52 by vfriber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifdef __APPLE__
#  define PTR_NULL "0x0"
# else
#  define PTR_NULL "(nil)"
# endif

# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_print_char(char character, int *length);
void	ft_print_string(char *args, int *length);
void	ft_print_number(int number, int *length);
void	ft_print_hexadecimal(unsigned int x, int *length, char x_or_x);
void	ft_print_unsigned_int(unsigned int u, int *length);
void	ft_print_pointer(size_t pointer, int *length);
int		ft_printf(const char *string, ...);
void	increment_printed_char_length(int *length);
#endif
