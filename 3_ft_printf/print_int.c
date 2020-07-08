/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 16:09:32 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/08 20:22:52 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			write_int_with_flag(char *input_string, t_flag *data_flag)
{
	int				padding;
	int				write_idx;
	int				str_len;

	str_len = ft_strlen(input_string);
	padding = get_padding(data_flag);
	write_idx = write_padding(padding);
	if (data_flag->minus_flag == TRUE)
	{
		write(1, "-", 1);
		write_idx++;
	}
	write_idx += write_zero(data_flag, str_len);
	if (!(ft_atoi(input_string) == 0 && data_flag->precision == 0 \
		&& data_flag->precision_remove == FALSE))
	{
		write(1, input_string, ft_strlen(input_string));
		write_idx += ft_strlen(input_string);
	}
	while (write_idx < data_flag->width)
	{
		write(1, " ", 1);
		write_idx++;
	}
	return (write_idx);
}

void		make_int_flag(t_flag *data_flag, char *data, char *input_string)
{
	int				str_len;

	data_flag->real_zero = FALSE;
	str_len = ft_strlen(input_string);
	if (data_flag->minus_flag == TRUE)
		str_len++;
	if (ft_atoi(input_string) == 0)
		data_flag->real_zero = TRUE;
	data_flag->zero_fill = find_zero(data);
	data_flag->left_range = get_range(data, data_flag);
	data_flag->precision = get_precision(data, str_len, data_flag);
	data_flag->width = get_width(data, str_len, data_flag);
}

int			ft_int(char *data, va_list ap, t_flag *data_flag)
{
	char			*input_string;
	int				num;

	get_star(data, data_flag, ap);
	num = va_arg(ap, int);
	data_flag->minus_flag = FALSE;
	input_string = ft_itoa(num);
	if (*input_string == '-')
	{
		*input_string = '\0';
		input_string++;
		data_flag->minus_flag = TRUE;
	}
	make_int_flag(data_flag, data, input_string);
	return (write_int_with_flag(input_string, data_flag));
}
