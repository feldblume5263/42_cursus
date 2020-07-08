/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 21:11:05 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/08 21:04:36 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			write_percent_with_flag(char ret_char, t_flag *flag)
{
	int				padding;
	int				write_idx;

	write_idx = 0;
	padding = get_padding(flag);
	write_idx += write_padding(padding);
	write_idx += write_zero(flag, 1);
	write(1, &ret_char, 1);
	write_idx++;
	while (write_idx < flag->width)
	{
		write(1, " ", 1);
		write_idx++;
	}
	return (write_idx);
}

void		make_percent_flag(t_flag *flag, char *data)
{
	flag->left_range = get_range(data, flag);
	flag->width = get_width(data, 1, flag);
	flag->precision = 1;
	flag->zero_fill = find_zero(data);
	flag->minus_flag = FALSE;
	flag->precision_remove = TRUE;
}

int			ft_percent(char *data, va_list ap, t_flag *flag)
{
	char			ret_char;

	get_star(data, flag, ap);
	ret_char = '%';
	make_percent_flag(flag, data);
	return (write_percent_with_flag(ret_char, flag));
}
