/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 16:09:32 by junhpark          #+#    #+#             */
/*   Updated: 2020/06/12 18:03:39 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void		write_int_with_flag(char *input_string, t_flag *data_flag)
{
	int				padding;
	int				write_idx;
	int				str_len;

	str_len = ft_strlen(input_string);
	padding = 0;
	if  (data_flag->left_range == FALSE)
		padding = data_flag->width - data_flag->precision;
	write_idx = 0;
	while (write_idx < padding)
	{
		write(1, " ", 1);
		write_idx++;
	}
	while (write_idx - padding < data_flag->precision - str_len)
	{
		write(1, "0", 1);
		write_idx++;
	}
	write(1, input_string, ft_strlen(input_string));
	write_idx += str_len;
	while (write_idx < data_flag->width)
	{
		write(1, " ", 1);
		write_idx++;
	}
}

int			get_precision(char *data, char *input_string)
{
	int				idx;
	int				precision;

	precision = 0;
	while (data[idx])
	{
		if (data[idx] == '.')
			precision = ft_atoi(&data[idx + 1]);
		idx++;
	}
	if (ft_strlen(input_string) > precision)
		precision = ft_strlen(input_string);
	return (precision);
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

int			get_width(char *data, int flag_width, char *input_string, int data_len)
{
	int				large_width;
	int				idx;

	large_width = 0;
	if (flag_width < 0)
		flag_width *= (-1);
	large_width = flag_width;
	idx = 0;
	while (data[idx] && (data[idx] < '0' || data[idx] > '9'))
		idx++;
	if (ft_atoi(&(data[idx])) > large_width)
		large_width = ft_atoi(&(data[idx]));
	if (ft_strlen(input_string) > large_width)
		large_width = ft_strlen(input_string);
	return (large_width);
}

int			get_range(char *data, int flag_width)
{
	int				idx;

	idx = 0;

	if (flag_width < 0)
		return (TRUE);
	while (data[idx])
	{
		if (data[idx] == '-')
			return (TRUE);
		idx++;
	}
	return (FALSE);
}

int			ft_int(char *data, va_list ap, int data_len, t_flag *data_flag)
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
	input_string = ft_itoa(va_arg(ap, int));
	data_flag->left_range = get_range(data, flag_width);
	data_flag->precision = get_precision(data, input_string);
	data_flag->width = get_width(data, flag_width, input_string, data_len);
	data_flag->zero_fill = find_zero(data);
	write_data_with_flag(input_string, data_flag);
	return (data_flag->width);
}
