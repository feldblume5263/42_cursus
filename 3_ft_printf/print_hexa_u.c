/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 14:39:41 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/05 17:41:29 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			write_hexa_u_with_flag(char *input_string, t_flag *data_flag)
{
	int				padding;
	int				write_idx;
	int				str_len;

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

void		make_hexa_u_flag(t_flag *data_flag, char *data, char *input_string)
{
	int				str_len;

	str_len = ft_strlen(input_string);
	data_flag->left_range = get_range(data, data_flag);
	data_flag->width = get_width(data, str_len, data_flag);
	data_flag->precision = get_precision(data, str_len, data_flag);
	data_flag->zero_fill = find_zero(data);
}

int			ft_hexa_u(char *data, va_list ap, t_flag *data_flag)
{
	char			*input_string;
	unsigned int	num;

	get_star(data, data_flag, ap);
	num = va_arg(ap, int);
	data_flag->minus_flag = FALSE;
	input_string = ft_utoa_base_up(num);
	make_hexa_u_flag(data_flag, data, input_string);
	return (write_hexa_u_with_flag(input_string, data_flag));
}
