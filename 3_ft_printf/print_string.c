/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 17:03:14 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/07 22:34:35 by junhpark         ###   ########.fr       */
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
	str_len = 0;
	if (input_string != 0)
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

	data_flag->precision_remove = FALSE;
	precision = 0;
	idx = -1;
	while (data[++idx])
	{
		data_flag->precision_remove = TRUE;
		if (data[idx] == '.' && ft_atoi(&data[idx + 1]) >= 0 && data_flag->precision >= 0)
		{
			data_flag->precision_remove = FALSE;
			precision = ft_atoi(&data[idx + 1]);
			break ;
		}
	}
	precision = precision > data_flag->width ? precision : data_flag ->width;
	return (precision);
}

int			get_str_width(char *data, int str_len, t_flag *data_flag)
{
	int				large_width;
	int				idx;

	large_width = 0;
	if (data_flag->width < 0)
	{
		data_flag->width *= (-1);
		data_flag->zero_fill = FALSE;
	}
	idx = 0;
	while (data[idx] && (data[idx] < '0' || data[idx] > '9') && data[idx + 1] == '.')
		idx++;
	if (ft_atoi(&(data[idx])) > large_width)
		large_width = ft_atoi(&(data[idx]));
	large_width = large_width > data_flag->width ? large_width : data_flag ->width;
	return (large_width);
}

void		make_string_flag(t_flag *data_flag, char *data, char *input_string)
{
	int				str_len;

	data_flag->real_zero = FALSE;
	str_len = ft_strlen(input_string);
	if (input_string == 0)
		data_flag->real_zero = TRUE;
	data_flag->left_range = get_range(data, data_flag);
	data_flag->precision = get_str_precision(data, str_len, data_flag);
	data_flag->width = get_str_width(data, str_len, data_flag);
	data_flag->zero_fill = FALSE;
	data_flag->minus_flag = FALSE;
	make_str_flag(data, data_flag, str_len);
}

int			ft_string(char *data, va_list ap, t_flag *data_flag)
{
	char			*input_string;

	get_star(data, data_flag, ap);
	input_string = va_arg(ap, char *);
	make_string_flag(data_flag, data, input_string);
	return (write_string_with_flag(input_string, data_flag));
}
