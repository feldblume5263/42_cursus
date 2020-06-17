/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 17:50:40 by junhpark          #+#    #+#             */
/*   Updated: 2020/06/17 15:37:27 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"



int			ft_unsigned_int(char *data, va_list ap, int data_len, t_flag *data_flag)
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
	input_string = ft_itoa(va_arg(ap, unsigned int));
	data_flag->left_range = get_range(data, flag_width);
	data_flag->precision = get_precision(data, input_string);
	data_flag->width = get_width(data, flag_width, input_string, data_len);
	data_flag->zero_fill = find_zero(data);
	write_int_with_flag(input_string, data_flag);
	return (data_flag->width);
}
