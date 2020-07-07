/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 17:03:14 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/07 21:02:43 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			write_string_with_flag(char *input_string, t_flag *data_flag)
{
	int				padding;
	int				write_idx;
	int				str_len;
	int				pre_idx;

	write_idx = 0;
	str_len = ft_strlen(input_string);
	padding = get_padding(data_flag);
	write_idx += write_padding(padding);
	pre_idx = 0;
	while (pre_idx < data_flag->precision)
	{
		write(1, &(input_string[pre_idx]), 1);
		pre_idx++;
	}
	write_idx += pre_idx;
	while (write_idx < data_flag->width)
	{
		write(1, " ", 1);
		write_idx++;
	}
	return (write_idx);
}

int			get_str_precision(char *data, int str_len, t_flag *data_flag)
{
	int				idx;
	int				precision;

	precision = str_len;
	idx = 0;
	while (data[idx])
	{
		if (data[idx] == '.')
			precision = ft_atoi(&data[idx + 1]);
		idx++;
	}
	if (str_len < precision)
		precision = str_len;
	if (precision > data_flag->width)
		precision = data_flag->width;
	return (precision);
}

void		make_string_flag(t_flag *data_flag, char *data, char *input_string)
{
	int				str_len;

	str_len = ft_strlen(input_string);
	data_flag->left_range = get_range(data, data_flag);
	data_flag->width = get_width(data, str_len, data_flag);
	data_flag->precision = get_precision(data, str_len, data_flag);
	data_flag->zero_fill = FALSE;
	data_flag->minus_flag = FALSE;
}

int			ft_string(char *data, va_list ap, t_flag *data_flag)
{
	char			*input_string;

	get_star(data, data_flag, ap);
	input_string = va_arg(ap, char *);
	make_string_flag(data_flag, data, input_string);
	return (write_string_with_flag(input_string, data_flag));
}
