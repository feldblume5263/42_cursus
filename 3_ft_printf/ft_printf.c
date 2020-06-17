/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 14:57:54 by junhpark          #+#    #+#             */
/*   Updated: 2020/06/16 17:29:07 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

#include <stdio.h>

int			wrirte_data_from_ap(char *data, va_list ap, int data_len)
{
	t_flag			*data_flag;
	int				print_len;

	data_flag = malloc(sizeof(t_flag) * 1);
	if (data[data_len - 1] == 'd')
		print_len = ft_int(data, ap, data_len, data_flag);
	return (print_len);
}

int			get_return_len(char *format)
{
	return (0);
}

int			inspect_chunk(char *chr, char *chunk)
{
	size_t			idx;

	idx = 0;
	while (chunk[idx])
	{
		if (chunk[idx] == *chr)
			return (TRUE);
		idx++;
	}
	return (FALSE);
}

int			get_data_len(char *format)
{
	int				data_len;

	data_len = 0;
	while ((inspect_chunk(&(format[data_len]), FLAG) == TRUE)
		|| (format[data_len] >= '0' && format[data_len] <= '9'))
		data_len++;
	data_len++;
	return (data_len);
}

char		*prepare_data(char *format, int data_len)
{
	char			*data;
	int				idx;

	if (!(data = (char *)malloc(sizeof(char) * (data_len + 1))))
		return ((char *)NLL);
	idx = 0;
	while (idx < data_len)
	{
		data[idx] = format[idx];
		idx++;
	}
	data[idx] = NLL;
	return (data);
}

int			write_by_conv(char *format, va_list ap)
{
	char			*data;
	int				data_len;
	int				idx;

	idx = 0;
	while (format[idx])
	{
		data_len = 0;
		while (format[idx] != '%' && format[idx])
		{
			write(1, &(format[idx]), 1);
			idx++;
		}
		if (format[idx] == '%')
		{
			idx++;
			data_len = get_data_len(&(format[idx]));
			wrirte_data_from_ap((prepare_data(&(format[idx]), data_len)), ap, data_len);
			idx += data_len;
		}
	}
	return (get_return_len(format));
}

int			ft_printf(const char *format, ...)
{
	char			*res_string;
	int				str_len;
	va_list			ap;

	va_start(ap, format);
	str_len = write_by_conv((char *)format, ap);
	va_end(ap);
	return (str_len);
}

int			main(void)
{
	printf("\nShe's |%*d| my sunshine |%8d| in the |%-.5d| rain\n",7, 40, 42, 412);
	ft_printf("\nShe's |%*d| my sunshine |%8d| in the |%-.5d| rain\n",7, 40, 42, 412);
	return (0);
}
