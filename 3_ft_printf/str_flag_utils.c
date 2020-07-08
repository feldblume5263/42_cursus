/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_flag_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 13:31:55 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/08 14:55:30 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		make_str_flag(t_flag *data_flag, int str_len)
{
	int			width;
	int			precision;

	width = data_flag->width;
	precision = data_flag->precision;
	if (precision > str_len)
		precision = str_len;
	if (precision < 0)
		precision = str_len;
	if (precision > width)
		width = precision;
	if (precision == 0 && data_flag->precision_remove == TRUE)
		precision = str_len;
	data_flag->width = width;
	data_flag->precision = precision;
}

int			get_str_precision(char *data, t_flag *data_flag)
{
	int				idx;
	int				precision;

	data_flag->precision_remove = FALSE;
	if (data_flag->precision != FALSE)
		return(data_flag->precision);
	precision = 0;
	idx = -1;
	while (data[++idx])
	{
		data_flag->precision_remove = TRUE;
		if (data[idx] == '.' && ft_atoi(&data[idx + 1]) >= 0 && data_flag->precision >= 0)
		{
			data_flag->precision_remove = FALSE;
			precision = ft_atoi(&data[idx + 1]);
			break ;
		}
	}
	return (precision);
}

int			get_str_width(char *data, t_flag *data_flag)
{
	int				large_width;
	int				idx;

	large_width = 0;
	if (data_flag->width < 0)
	{
		data_flag->width *= (-1);
		data_flag->zero_fill = FALSE;
	}
	idx = 0;
	while (data[idx] && (data[idx] < '0' || data[idx] > '9') && data[idx] != '.')
		idx++;
	if (data[idx] != '.')
		large_width = ft_atoi(&(data[idx]));
	if (large_width < 0)
		large_width *= (-1);
	large_width = large_width > data_flag->width ? large_width : data_flag ->width;
	return (large_width);
}
