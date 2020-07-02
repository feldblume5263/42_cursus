/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 17:20:01 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/01 17:12:40 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

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
	int					flag_width;
	char				*input_string;
	int					idx;
	unsigned long long	num;

	flag_width = FALSE;
	idx = 0;
	while (data[idx])
	{
		if (data[idx] == '*')
			flag_width = va_arg(ap, int);
		idx++;
	}
	num = va_arg(ap, unsigned int);
	data_flag->minus_flag = FALSE;
	input_string = ft_itoa_u(num);
	make_int_flag(data_flag, data, flag_width, input_string);
	write_int_with_flag(input_string, data_flag);
	return (write_int_with_flag(input_string, data_flag));
}
