/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 19:19:57 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/08 21:10:06 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_precision(char *data, int str_len, t_flag *flag)
{
	int				idx;
	int				precision;

	if (flag->minus_flag == TRUE)
		str_len--;
	flag->precision_remove = FALSE;
	precision = 0;
	idx = -1;
	while (data[++idx])
	{
		flag->precision_remove = TRUE;
		if (data[idx] == '.' && ft_atoi(&data[idx + 1]) >= 0 && \
			flag->precision >= 0)
		{
			flag->precision_remove = FALSE;
			precision = ft_atoi(&data[idx + 1]);
			break ;
		}
	}
	precision = precision > flag->precision ? precision : flag->precision;
	if (precision == 0 && flag->precision_remove == FALSE \
		&& flag->real_zero == TRUE)
		str_len = 0;
	precision = str_len > precision ? str_len : precision;
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

int			get_width(char *data, int str_len, t_flag *flag)
{
	int				large_width;
	int				idx;

	large_width = 0;
	if (flag->width < 0)
	{
		flag->width *= (-1);
		flag->zero_fill = FALSE;
	}
	idx = 0;
	while (data[idx] && (data[idx] < '0' || data[idx] > '9'))
		idx++;
	if (ft_atoi(&(data[idx])) > large_width)
		large_width = ft_atoi(&(data[idx]));
	large_width = large_width > flag->width ? large_width : flag->width;
	if (flag->precision == 0 && flag->precision_remove == FALSE \
		&& flag->real_zero == TRUE)
		str_len = 0;
	if (str_len > large_width)
		large_width = str_len;
	if (flag->precision > large_width)
		large_width = flag->precision;
	return (large_width);
}

int			get_range(char *data, t_flag *flag)
{
	int				idx;

	idx = 0;
	if (flag->width < 0)
	{
		flag->zero_fill = FALSE;
		return (TRUE);
	}
	while (data[idx])
	{
		if (data[idx] == '-')
		{
			flag->zero_fill = FALSE;
			return (TRUE);
		}
		idx++;
	}
	return (FALSE);
}

void		get_star(char *data, t_flag *flag, va_list ap)
{
	int				idx;

	flag->precision = FALSE;
	flag->width = FALSE;
	idx = 0;
	while (data[idx])
	{
		if (data[idx] == '*' && data[idx - 1] != '.')
			flag->width = va_arg(ap, int);
		if (data[idx] == '*' && data[idx - 1] == '.')
			flag->precision = va_arg(ap, int);
		idx++;
	}
}
