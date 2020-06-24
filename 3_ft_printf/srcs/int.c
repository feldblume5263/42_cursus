/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 16:09:32 by junhpark          #+#    #+#             */
/*   Updated: 2020/06/24 17:08:43 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

void		write_int_with_flag(char *input_string, t_flag *data_flag, int minus)
{
	int				padding;
	int				write_idx;
	int				str_len;

	str_len = ft_strlen(input_string);
	padding = 0;
	padding += get_padding(data_flag, minus, str_len);
	write_idx = write_padding(padding);
	if (minus == TRUE)
	{
		write(1, "-", 1);
		write_idx++;
	}
	write_idx += write_zero(data_flag, str_len);
	write(1, input_string, str_len);
	write_idx += str_len;
	while (write_idx < data_flag->width)
	{
		write(1, " ", 1);
		write_idx++;
	}
}

int			ft_int(char *data, va_list ap, int data_len, t_flag *data_flag)
{
	int				flag_width;
	char			*input_string;
	int				idx;
	int				num;
	int				minus_flag;

	flag_width = FALSE;
	idx = 0;
	while (data[idx])
	{
		if (data[idx] == '*')
			flag_width = va_arg(ap, int);
		idx++;
	}
	num = va_arg(ap, int);
	minus_flag = FALSE;
	if (num < 0)
	{
		num *= (-1);
		minus_flag = TRUE;
	}
	input_string = ft_itoa(num);
	make_all_flag(data_flag, data, flag_width, input_string, data_len);
	write_int_with_flag(input_string, data_flag, minus_flag);
	return (data_flag->width);
}
