/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 17:20:01 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/05 17:36:54 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			write_unsigned_int_with_flag(char *input_string, t_flag *data_flag)
{
	int					padding;
	int					write_idx;
	int					str_len;

	str_len = ft_strlen(input_string);
	padding = get_padding(data_flag);
	write_idx = write_padding(padding);
	write_idx += write_zero(data_flag, str_len);
	write(1, input_string, str_len);
	write_idx += str_len;
	while (write_idx < data_flag->width)
	{
		write(1, " ", 1);
		write_idx++;
	}
	return (write_idx);
}

int			ft_unsigned_int(char *data, va_list ap, t_flag *data_flag)
{
	char				*input_string;
	unsigned int		num;

	get_star(data, data_flag, ap);
	num = va_arg(ap, unsigned int);
	data_flag->minus_flag = FALSE;
	input_string = ft_utoa(num);
	make_int_flag(data_flag, data, input_string);
	write_int_with_flag(input_string, data_flag);
	return (write_unsigned_int_with_flag(input_string, data_flag));
}
