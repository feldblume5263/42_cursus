/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 20:58:14 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/15 22:03:19 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			write_string(t_flag *flag, t_write *writes, char *input_string)
{
	int				write_idx;
	int				idx;

	write_idx = 0;
	idx = 0;
	while (idx < writes->padding)
	{
		write(1, " ", 1);
		write_idx++;
		idx++;
	}
	write(1, input_string, flag->precision);
	write_idx += flag->str_len;
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
	int				prec;
	int				str_len;

	if (input_string == 0)
		input_string = ft_strdup("(null)");
	str_len = ft_strlen(input_string);
	if (flag->precision < 0 || flag->precision_remove == TRUE)
		flag->precision = str_len;
	prec = flag->precision < str_len ? flag->precision : str_len;
	width = flag->width > prec ? flag->width : prec;
	writes->padding = width - str_len;
	if (flag->left_range == TRUE)
		writes->padding = 0;
	writes->length = width;
	if (flag->precision >= 0)
		flag->precision = prec;
}

int			ft_string(char *data, va_list ap, t_flag *flag)
{
	t_write			*writes;
	char			*input_string;
	int				ret_value;

	if (!(writes = malloc(sizeof(t_write) * 1)))
		return (MALLOC_ERROR);
	input_string = va_arg(ap, char *);
	get_flag(data, flag, input_string);
	string_rule(flag, writes, input_string);
	ret_value = write_string(flag, writes, input_string);
	free(writes);
	free(flag);
	free(data);
	return (ret_value);
}
