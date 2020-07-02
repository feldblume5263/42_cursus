/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 17:08:00 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/02 20:45:18 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int			get_padding(t_flag *data_flag)
{
	int				padding;
	int				precision;

	precision = (data_flag->precision < 0) ? 0 : data_flag->precision;
	padding = 0;
	if (data_flag->left_range == FALSE)
		padding += (data_flag->width - precision);
	if (data_flag->minus_flag == TRUE)
		padding -= 1;
	if (padding < 0)
		padding = 0;
	return (padding);
}

int			write_padding(int padding)
{
	int				write_idx;

	write_idx = 0;
	while (write_idx < padding)
	{
		write(1, " ", 1);
		write_idx++;
	}
	return (write_idx);
}

int			write_zero(t_flag *data_flag, int str_len)
{
	int				write_idx;
	int				precision;

	precision = (data_flag->precision < 0) ? 0 : data_flag->precision;
	write_idx = 0;
	if (data_flag->zero_fill == TRUE && data_flag->precision == -1)
	{
		while (write_idx < (data_flag->width - str_len))
		{
			write(1, "0", 1);
			write_idx++;
		}
	}
	else
	{
		while (write_idx < (precision - str_len))
		{
			write(1, "0", 1);
			write_idx++;
		}
	}
	return (write_idx);
}

int			write_percent_zero(t_flag *data_flag, int str_len)
{
	int				write_idx;

	write_idx = 0;
	while (write_idx < (data_flag->precision - str_len))
	{
		write(1, " ", 1);
		write_idx++;
	}

	return (write_idx);
}
