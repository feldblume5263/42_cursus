/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 17:54:55 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/19 17:01:00 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		get_flag(char *data, t_flag *flag, char *input_data)
{
	flag->str_len = 0;
	if (input_data != 0 && flag->ischar != TRUE)
		flag->str_len = ft_strlen(input_data);
	if (flag->ischar == TRUE)
		flag->str_len = 1;
	flag->width = get_width(data, flag);
	flag->precision = get_precision(data, flag);
	flag->left_range = get_range(data, flag);
	flag->zero_fill = get_zero(data, flag);
}

int			get_width(char *data, t_flag *flag)
{
	int				idx;

	idx = 0;
	if (flag->width != FALSE)
	{
		if (flag->width < 0)
		{
			flag->left_range = TRUE;
			flag->width_minus = TRUE;
			return (flag->width *= (-1));
		}
		return (flag->width);
	}
	while (data[idx])
	{
		if (data[idx] == '.')
			return (0);
		if (data[idx] >= '1' && data[idx] <= '9')
			return (ft_atoi(&(data[idx])));
		idx++;
	}
	return (0);
}

int			get_precision(char *data, t_flag *flag)
{
	int				idx;

	idx = 0;
	if (flag->precision != FALSE)
		return (flag->precision);
	while (data[idx])
	{
		if (data[idx] == '.')
		{
			flag->precision_remove = FALSE;
			return (ft_atoi(&(data[idx + 1])));
		}
		idx++;
	}
	flag->precision_remove = TRUE;
	return (0);
}

int			get_range(char *data, t_flag *flag)
{
	int				idx;

	idx = 0;
	if (flag->left_range == TRUE)
		return (TRUE);
	while (data[idx])
	{
		if (data[idx] == '-')
			return (TRUE);
		idx++;
	}
	return (FALSE);
}

int			get_zero(char *data, t_flag *flag)
{
	int				idx;

	idx = 0;
	if (flag->zero_fill == TRUE)
		return (TRUE);
	while (data[idx])
	{
		if (data[idx] == '.')
			break ;
		if (data[idx] == '0')
			return (TRUE);
		idx++;
	}
	return (FALSE);
}
