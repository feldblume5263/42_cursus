/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 17:08:00 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/08 21:04:30 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_padding(t_flag *flag)
{
	int				padding;

	if (flag->zero_fill == TRUE && flag->precision_remove == TRUE)
		return (0);
	padding = 0;
	if (flag->left_range == FALSE)
		padding += flag->width - flag->precision;
	if (flag->minus_flag == TRUE)
		padding -= 1;
	if (flag->x_flag == TRUE && flag->precision_remove == FALSE \
		&& flag->precision == 0 && flag->real_zero == TRUE)
		padding -= 2;
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

int			write_zero(t_flag *flag, int str_len)
{
	int				write_idx;

	write_idx = 0;
	if (flag->zero_fill == TRUE && flag->precision_remove == TRUE)
	{
		if (flag->minus_flag == TRUE)
			str_len++;
		while (write_idx < (flag->width - str_len))
		{
			write(1, "0", 1);
			write_idx++;
		}
	}
	else
	{
		while (write_idx < (flag->precision - str_len))
		{
			write(1, "0", 1);
			write_idx++;
		}
	}
	return (write_idx);
}
