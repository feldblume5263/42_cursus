/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 19:19:57 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/07 15:59:27 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_precision(char *data, int str_len, t_flag *data_flag)
{
	int				idx;
	int				precision;

	if (data_flag->minus_flag == TRUE)
		str_len--;
	data_flag->precision_remove = FALSE;
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
	precision = precision > data_flag->precision ? precision : data_flag->precision;
	if (precision == 0 && data_flag->precision_remove == FALSE && data_flag->real_zero == TRUE)
		str_len = 0;
	if (str_len > precision)
		precision = str_len;
	return (precision);
}

int			find_zero(char *data)
{
	int				idx;

	idx = 0;
	while (data[idx])
	{
		if ((data[idx] >= '1' && data[idx] <= '9') || data[idx] == '.')
			return (FALSE);
		if (data[idx] == '0')
			return (TRUE);
		idx++;
	}
	return (FALSE);
}

int			get_width(char *data, int str_len, t_flag *data_flag)
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
	while (data[idx] && (data[idx] < '0' || data[idx] > '9'))
		idx++;
	if (ft_atoi(&(data[idx])) > large_width)
		large_width = ft_atoi(&(data[idx]));
	large_width = large_width > data_flag->width ? large_width : data_flag ->width;
	if (data_flag->precision == 0 && data_flag->precision_remove == FALSE \
		&& data_flag->real_zero == TRUE)
		str_len = 0;
	if (str_len > large_width)
		large_width = str_len;
	if (data_flag->precision > large_width)
		large_width = data_flag->precision;
	return (large_width);
}

int			get_range(char *data, t_flag *data_flag)
{
	int				idx;

	idx = 0;

	if (data_flag->width < 0)
		return (TRUE);
	while (data[idx])
	{
		if (data[idx] == '-')
			return (TRUE);
		idx++;
	}
	return (FALSE);
}

void		get_star(char *data, t_flag *data_flag, va_list ap)
{
	int				idx;

	data_flag->precision = FALSE;
	data_flag->width = FALSE;
	idx = 0;
	while (data[idx])
	{
		if (data[idx] == '*' && data[idx - 1] != '.')
			data_flag->width = va_arg(ap, int);
		if (data[idx] == '*' && data[idx - 1] == '.')
			data_flag->precision = va_arg(ap, int);
		idx++;
	}
}
