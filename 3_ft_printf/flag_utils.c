/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 19:19:57 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/05 17:28:35 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_precision(char *data, int str_len, t_flag *data_flag)
{
	int				idx;
	int				precision;

	if (data_flag->precision < 0)
		data_flag->precision = 0;
	data_flag->precision_remove = FALSE;
	precision = 0;
	idx = 0;
	while (data[idx])
	{
		data_flag->precision_remove = TRUE;
		if (data[idx] == '.')
		{
			data_flag->precision_remove = FALSE;
			precision = ft_atoi(&data[idx + 1]);
			break;
		}
		idx++;
	}
	if (str_len > precision)
		precision = str_len;
	if (precision > data_flag->width)
		data_flag->width = precision;
	return (precision > data_flag->precision ? precision : data_flag->precision);
}

int			find_zero(char *data)
{
	int				idx;

	idx = 0;
	while(data[idx])
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
		data_flag->width *= (-1);
	idx = 0;
	while (data[idx] && (data[idx] < '0' || data[idx] > '9'))
		idx++;
	if (ft_atoi(&(data[idx])) > large_width)
		large_width = ft_atoi(&(data[idx]));
	if (str_len > large_width)
		large_width = str_len;
	return (large_width > data_flag->width ? large_width : data_flag ->width);
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
		if (data[idx] == '*' && data[idx] != '.')
			data_flag->width = va_arg(ap, int);
		else if (data[idx] == '*' && data[idx] == '.')
			data_flag->precision = va_arg(ap, int);
		idx++;
	}
}
