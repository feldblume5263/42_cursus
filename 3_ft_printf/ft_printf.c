/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 14:57:54 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/19 16:52:21 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			wrirte_data_from_ap(char *data, va_list ap, int data_len)
{
	t_flag			*flag;
	int				print_len;

	if (!(flag = malloc(sizeof(t_flag) * 1)))
		return (MALLOC_ERROR);
	prepare_flag(data, flag, ap);
	if (data[data_len - 1] == 'd' || data[data_len - 1] == 'i')
		return (print_len = ft_int(data, ap, flag));
	else if (data[data_len - 1] == 'u')
		return (print_len = ft_unsigned_int(data, ap, flag));
	else if (data[data_len - 1] == 'c')
		return (print_len = ft_char(data, ap, flag));
	else if (data[data_len - 1] == 's')
		return (print_len = ft_string(data, ap, flag));
	else if (data[data_len - 1] == 'x')
		return (print_len = ft_hexa_low(data, ap, flag));
	else if (data[data_len - 1] == 'X')
		return (print_len = ft_hexa_up(data, ap, flag));
	else if (data[data_len - 1] == 'p')
		return (print_len = ft_pointer(data, ap, flag));
	return (print_len = 0);
}

void		prepare_flag(char *data, t_flag *flag, va_list ap)
{
	int				idx;

	flag->width = FALSE;
	flag->width_minus = FALSE;
	flag->precision = FALSE;
	flag->precision_remove = TRUE;
	flag->left_range = FALSE;
	flag->zero_fill = FALSE;
	flag->minus_flag = FALSE;
	flag->ischar = FALSE;
	idx = 0;
	while (data[idx])
	{
		if (data[idx] == '*' && data[idx - 1] != '.')
			flag->width = va_arg(ap, int);
		if (data[idx] == '*' && data[idx - 1] == '.')
		{
			flag->precision = va_arg(ap, int);
			flag->precision_remove = FALSE;
		}
		idx++;
	}
}

int			write_by_conv(char *format, va_list ap)
{
	int				data_len;
	int				idx;
	int				return_byte;

	idx = 0;
	return_byte = 0;
	while (format[idx])
	{
		data_len = 0;
		while (format[idx] != '%' && format[idx])
		{
			write(1, &(format[idx]), 1);
			idx++;
			return_byte++;
		}
		if (format[idx] == '%' && format[idx])
		{
			idx++;
			data_len = get_data_len(&(format[idx]));
			return_byte += wrirte_data_from_ap(\
				(prepare_data(&(format[idx]), data_len)), ap, data_len);
			idx += data_len;
		}
	}
	return (return_byte);
}

int			ft_printf(const char *format, ...)
{
	int				str_len;
	va_list			ap;

	va_start(ap, format);
	str_len = write_by_conv((char *)format, ap);
	va_end(ap);
	return (str_len);
}
