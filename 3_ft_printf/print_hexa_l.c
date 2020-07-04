/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_l.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 17:59:11 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/04 22:41:08 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			write_hexa_l_with_flag(char *input_string, t_flag *data_flag)
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

void		make_hexa_l_flag(t_flag *data_flag, char *data, int flag_width, char *input_string)
{
	int				str_len;

	str_len = ft_strlen(input_string);
	data_flag->left_range = get_range(data, flag_width);
	data_flag->width = get_width(data, flag_width, str_len);
	data_flag->precision = get_precision(data, str_len, data_flag);
	data_flag->zero_fill = find_zero(data);
}

int			ft_hexa_l(char *data, va_list ap, t_flag *data_flag)
{
	int				flag_width;
	char			*input_string;
	int				idx;
	unsigned int	num;

	flag_width = FALSE;
	idx = 0;
	while (data[idx])
	{
		if (data[idx] == '*')
			flag_width = va_arg(ap, int);
		idx++;
	}
	num = va_arg(ap, int);
	data_flag->minus_flag = FALSE;
	input_string = ft_utoa_base(num);
	make_hexa_l_flag(data_flag, data, flag_width, input_string);
	return (write_hexa_l_with_flag(input_string, data_flag));
}