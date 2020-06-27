/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 17:03:14 by junhpark          #+#    #+#             */
/*   Updated: 2020/06/27 17:33:04 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

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

#include <stdio.h>
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
	//printf("%d ", precision);
	if (str_len < precision)
		precision = str_len;
	if (precision > data_flag->width)
		precision = data_flag->width;
	return (precision);
}

void		make_string_flag(t_flag *data_flag, char *data, int flag_width, char *input_string)
{
	int				str_len;

	str_len = ft_strlen(input_string);
	data_flag->left_range = get_range(data, flag_width);
	data_flag->width = get_width(data, flag_width, str_len);
	data_flag->precision = get_str_precision(data, str_len, data_flag);
	data_flag->zero_fill = FALSE;
	data_flag->minus_flag = FALSE;
}

int			ft_string(char *data, va_list ap, t_flag *data_flag)
{
	int				flag_width;
	char			*input_string;
	int				idx;

	flag_width = FALSE;
	idx = 0;
	while (data[idx])
	{
		if (data[idx] == '*')
			flag_width = va_arg(ap, int);
		idx++;
	}
	input_string = va_arg(ap, char *);
	make_string_flag(data_flag, data, flag_width, input_string);
	return (write_string_with_flag(input_string, data_flag));
}
