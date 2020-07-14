/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 17:03:14 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/08 21:04:34 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			write_string_with_flag(char *input_string, t_flag *flag)
{
	int				padding;
	int				write_idx;
	int				str_len;
	int				pre_idx;

	write_idx = 0;
	str_len = 6;
	if (input_string != 0)
		str_len = ft_strlen(input_string);
	if (input_string == 0)
		input_string = ft_strdup("(null)");
	padding = get_padding(flag);
	write_idx += write_padding(padding);
	pre_idx = -1;
	while (++pre_idx < flag->precision)
		write(1, &(input_string[pre_idx]), 1);
	write_idx += pre_idx;
	while (write_idx < flag->width)
	{
		write(1, " ", 1);
		write_idx++;
	}
	return (write_idx);
}

void		make_string_flag(t_flag *flag, char *data, char *input_string)
{
	int				str_len;

	str_len = 0;
	flag->real_zero = FALSE;
	if (input_string != 0)
		str_len = ft_strlen(input_string);
	if (input_string == 0)
	{
		flag->real_zero = TRUE;
		str_len = 6;
	}
	flag->left_range = get_range(data, flag);
	flag->precision = get_str_precision(data, flag);
	flag->width = get_str_width(data, flag);
	flag->zero_fill = FALSE;
	flag->minus_flag = FALSE;
	make_str_flag(flag, str_len);
}

int			ft_string(char *data, va_list ap, t_flag *flag)
{
	char			*input_string;

	get_star(data, flag, ap);
	input_string = va_arg(ap, char *);
	make_string_flag(flag, data, input_string);
	return (write_string_with_flag(input_string, flag));
}
