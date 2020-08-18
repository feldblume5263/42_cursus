/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 16:09:32 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/15 20:12:27 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			write_int_with_flag(char *input_string, t_flag *flag)
{
	int				padding;
	int				write_idx;
	int				str_len;

	str_len = ft_strlen(input_string);
	padding = get_padding(flag);
	write_idx = write_padding(padding);
	if (flag->minus_flag == TRUE)
	{
		write(1, "-", 1);
		write_idx++;
	}
	write_idx += write_zero(flag, str_len);
	if (!(ft_atoi(input_string) == 0 && flag->precision == 0 \
		&& flag->precision_remove == FALSE))
	{
		write(1, input_string, ft_strlen(input_string));
		write_idx += ft_strlen(input_string);
	}
	while (write_idx < flag->width)
	{
		write(1, " ", 1);
		write_idx++;
	}
	return (write_idx);
}

void		make_int_flag(t_flag *flag, char *data, char *input_string)
{
	int				str_len;

	flag->real_zero = FALSE;
	str_len = ft_strlen(input_string);
	if (flag->minus_flag == TRUE)
		str_len++;
	if (ft_atoi(input_string) == 0)
		flag->real_zero = TRUE;
	flag->zero_fill = find_zero(data);
	flag->left_range = get_range(data, flag);
	flag->precision = get_precision(data, str_len, flag);
	flag->width = get_width(data, str_len, flag);
}

int			ft_int(char *data, va_list ap, t_flag *flag)
{
	char			*input_string;
	int				num;
	int				ret;

	get_star(data, flag, ap);
	num = va_arg(ap, int);
	flag->minus_flag = FALSE;
	input_string = ft_itoa(num);
	if (*input_string == '-')
	{
		*input_string = '\0';
		input_string++;
		flag->minus_flag = TRUE;
	}
	make_int_flag(flag, data, input_string);
	ret = write_int_with_flag(input_string, flag);
	return (ret);
}
