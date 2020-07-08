/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 17:20:01 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/08 21:04:33 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			write_unsigned_int_with_flag(char *input_string, t_flag *flag)
{
	int					padding;
	int					write_idx;
	int					str_len;

	str_len = ft_strlen(input_string);
	padding = get_padding(flag);
	write_idx = write_padding(padding);
	write_idx += write_zero(flag, str_len);
	if (!(ft_atoi(input_string) == 0 && flag->precision == 0 \
		&& flag->precision_remove == FALSE))
	{
		write(1, input_string, str_len);
		write_idx += str_len;
	}
	while (write_idx < flag->width)
	{
		write(1, " ", 1);
		write_idx++;
	}
	return (write_idx);
}

int			ft_unsigned_int(char *data, va_list ap, t_flag *flag)
{
	char				*input_string;
	unsigned int		num;

	get_star(data, flag, ap);
	num = va_arg(ap, unsigned int);
	flag->minus_flag = FALSE;
	input_string = ft_utoa(num);
	make_int_flag(flag, data, input_string);
	return (write_unsigned_int_with_flag(input_string, flag));
}
