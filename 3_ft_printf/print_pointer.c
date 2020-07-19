/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 16:45:23 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/19 17:12:19 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			write_pointer(t_flag *flag, t_write *writes, char *input_string)
{
	int				write_idx;
	int				idx;

	idx = 0;
	write_idx = 0;
	while (idx < writes->padding)
	{
		write(1, " ", 1);
		write_idx++;
		idx++;
	}
	write(1, "0x", 2);
	write(1, input_string, flag->str_len);
	write_idx += flag->str_len + 2;
	while (write_idx < writes->length)
	{
		write(1, " ", 1);
		write_idx++;
	}
	return (write_idx);
}

void		pointer_rule(t_flag *flag, t_write *writes, char *input_string)
{
	int				width;
	int				str_len;

	str_len = ft_strlen(input_string);
	if (*input_string == '0' && flag->precision == 0 \
		&& flag->precision_remove == FALSE)
	{
		input_string = ft_strdup("");
		flag->str_len = 0;
		str_len = 0;
	}
	if (flag->precision > str_len)
		flag->precision = str_len;
	if (flag->width < 0)
		flag->width *= -1;
	width = flag->width > flag->precision ? flag->width : flag->precision;
	writes->padding = width - (str_len + 2);
	if (flag->left_range == TRUE)
		writes->padding = 0;
	writes->length = width;
}

int			ft_pointer(char *data, va_list ap, t_flag *flag)
{
	long long		pointer;
	t_write			*writes;
	char			*input_string;
	int				ret_value;

	if (!(writes = malloc(sizeof(t_write) * 1)))
		return (MALLOC_ERROR);
	pointer = va_arg(ap, long long);
	input_string = ft_lltoa_base(pointer);
	get_flag(data, flag, input_string);
	pointer_rule(flag, writes, input_string);
	ret_value = write_pointer(flag, writes, input_string);
	free(writes);
	free(flag);
	free(data);
	return (ret_value);
}
