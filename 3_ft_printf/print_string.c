/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 20:58:14 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/19 16:14:55 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			write_string(t_flag *flag, t_write *writes, char *input_string)
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
	write(1, input_string, flag->precision);
	write_idx += flag->precision;
	while (write_idx < writes->length)
	{
		write(1, " ", 1);
		write_idx++;
	}
	return (write_idx);
}

void		string_rule(t_flag *flag, t_write *writes, char *input_string)
{
	int				width;
	int				str_len;

	str_len = ft_strlen(input_string);
	if (flag->precision > str_len)
		flag->precision = str_len;
	if (flag->width < 0)
		flag->width *= -1;
	if ((flag->precision < 0 && flag->precision_remove == FALSE) \
		|| flag->precision_remove == TRUE)
		flag->precision = str_len;
	width = flag->width > flag->precision ? flag->width : flag->precision;
	writes->padding = width - flag->precision;
	if (flag->left_range == TRUE)
		writes->padding = 0;
	writes->length = width;
}

int			ft_string(char *data, va_list ap, t_flag *flag)
{
	t_write			*writes;
	char			*input_string;
	int				ret_value;

	if (!(writes = malloc(sizeof(t_write) * 1)))
		return (MALLOC_ERROR);
	if (!(input_string = va_arg(ap, char *)))
		input_string = ft_strdup("(null)");
	get_flag(data, flag, input_string);
	string_rule(flag, writes, input_string);
	ret_value = write_string(flag, writes, input_string);
	free(writes);
	free(flag);
	free(data);
	return (ret_value);
}
