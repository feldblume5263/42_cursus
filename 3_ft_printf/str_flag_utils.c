/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_flag_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 13:31:55 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/12 17:19:55 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		make_str_flag(t_flag *flag, int str_len)
{
	int			width;
	int			precision;

	width = flag->width;
	precision = flag->precision;
	if (precision > str_len)
		precision = str_len;
	if (precision < 0)
		precision = str_len;
	if (precision > width)
		width = precision;
	if (precision == 0 && flag->precision_remove == TRUE)
		precision = str_len;
	flag->width = width;
	flag->precision = precision;
}

int			get_str_precision(char *data, t_flag *flag)
{
	int				idx;
	int				precision;

	flag->precision_remove = FALSE;
	if (flag->precision != FALSE)
		return (flag->precision);
	precision = 0;
	idx = -1;
	while (data[++idx])
	{
		flag->precision_remove = TRUE;
		if (data[idx] == '.' && ft_atoi(&data[idx + 1]) >= 0 \
			&& flag->precision >= 0)
		{
			flag->precision_remove = FALSE;
			precision = ft_atoi(&data[idx + 1]);
			break ;
		}
	}
	return (precision);
}

int			get_str_width(char *data, t_flag *flag)
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
	while (data[idx] && (data[idx] < '1' \
			|| data[idx] > '9') && data[idx] != '.')
		idx++;
	if (data[idx] != '.')
		large_width = ft_atoi(&(data[idx]));
	if (large_width < 0)
		large_width *= (-1);
	large_width = large_width > flag->width ? large_width : flag->width;
	return (large_width);
}
