/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 17:08:00 by junhpark          #+#    #+#             */
/*   Updated: 2020/06/24 17:08:58 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int			get_padding(t_flag *data_flag, int minus, int str_len)
{
	int				padding;

	padding = 0;
	if (data_flag->left_range == FALSE)
		padding += data_flag->width - data_flag->precision;
	if (minus == TRUE)
		padding -= 1;
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

	write_idx = 0;
	while (write_idx < (data_flag->precision - str_len))
	{
		write(1, "0", 1);
		write_idx++;
	}
	return (write_idx);
}
