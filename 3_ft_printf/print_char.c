/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 15:59:40 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/08 21:04:41 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			write_char_with_flag(char ret_char, t_flag *flag)
{
	int				padding;
	int				write_idx;

	write_idx = 0;
	padding = get_padding(flag);
	write_idx += write_padding(padding);
	write(1, &ret_char, 1);
	write_idx++;
	while (write_idx < flag->width)
	{
		write(1, " ", 1);
		write_idx++;
	}
	return (write_idx);
}

void		make_char_flag(t_flag *flag, char *data)
{
	flag->left_range = get_range(data, flag);
	flag->width = get_width(data, 1, flag);
	flag->precision = get_precision(data, 1, flag);
	flag->minus_flag = FALSE;
	flag->zero_fill = FALSE;
}

int			ft_char(char *data, va_list ap, t_flag *flag)
{
	char			ret_char;

	get_star(data, flag, ap);
	ret_char = va_arg(ap, int);
	make_char_flag(flag, data);
	return (write_char_with_flag(ret_char, flag));
}
