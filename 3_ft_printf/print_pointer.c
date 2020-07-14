/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:08:48 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/08 21:04:35 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			write_pointer_with_flag(char *input_string, t_flag *flag)
{
	int				padding;
	int				write_idx;
	int				str_len;

	str_len = ft_strlen(input_string);
	padding = get_padding(flag);
	write_idx = write_padding(padding);
	write_idx += write_zero(flag, str_len + 2);
	write(1, "0x", 2);
	write_idx += 2;
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

void		make_pointer_flag(t_flag *flag, char *data, char *input_string)
{
	int				str_len;

	str_len = ft_strlen(input_string) + 2;
	if (ft_atoi(input_string) == 0)
		flag->real_zero = TRUE;
	flag->left_range = get_range(data, flag);
	flag->zero_fill = find_zero(data);
	flag->precision = get_precision(data, str_len, flag);
	flag->width = get_width(data, str_len, flag);
}

int			ft_pointer(char *data, va_list ap, t_flag *flag)
{
	char			*input_string;
	long long		num;

	get_star(data, flag, ap);
	num = va_arg(ap, long long);
	flag->minus_flag = FALSE;
	flag->x_flag = TRUE;
	input_string = ft_lltoa_base(num);
	make_pointer_flag(flag, data, input_string);
	return (write_pointer_with_flag(input_string, flag));
}
