/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 17:28:25 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/15 19:27:14 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			write_int_b(t_flag *flag, t_write *writes)
{
	int				idx;
	int				write_idx;

	write_idx = 0;
	idx = -1;
	while ((flag->zero_fill == FALSE || (flag->precision_remove == FALSE \
			&& flag->precision >= 0)) && ++idx < writes->padding)
	{
		write(1, " ", 1);
		write_idx++;
	}
	if (flag->minus_flag == TRUE)
	{
		write(1, "-", 1);
		write_idx++;
	}
	idx = -1;
	while ((flag->precision_remove == TRUE || flag->precision < 0) \
		&& flag->zero_fill == TRUE && ++idx < writes->padding)
	{
		write(1, "0", 1);
		write_idx++;
	}
	return (write_idx);
}

int			write_int(t_flag *flag, t_write *writes, char *input_string)
{
	int				write_idx;
	int				idx;

	write_idx = write_int_b(flag, writes);
	idx = 0;
	while (idx < writes->zero)
	{
		write(1, "0", 1);
		write_idx++;
		idx++;
	}
	write(1, input_string, flag->str_len);
	write_idx += flag->str_len;
	while (write_idx < writes->length)
	{
		write(1, " ", 1);
		write_idx++;
	}
	return (write_idx);
}

void		int_rule(t_flag *flag, t_write *writes, char *input_string)
{
	int				num;
	int				width;
	int				prec;
	int				str_len;

	num = ft_atoi(input_string);
	str_len = flag->str_len;
	if (num == 0 && flag->precision == 0 && flag->precision_remove == FALSE)
	{
		input_string = ft_strdup("");
		flag->str_len = 0;
		str_len = 0;
	}
	prec = flag->precision > str_len ? flag->precision : str_len;
	width = flag->width > prec ? flag->width : prec;
	if (flag->minus_flag == TRUE)
		if (flag->width < str_len + 1)
			width = str_len + 1;
	writes->padding = width - prec;
	if (flag->minus_flag == TRUE)
		writes->padding--;
	if (flag->left_range == TRUE)
		writes->padding = 0;
	writes->zero = prec - str_len;
	writes->length = width;
}

int			ft_unsigned_int(char *data, va_list ap, t_flag *flag)
{
	t_write			*writes;
	char			*input_string;
	unsigned int	num;
	int				ret_value;

	if (!(writes = malloc(sizeof(t_write) * 1)))
		return (MALLOC_ERROR);
	num = va_arg(ap, int);
	input_string = ft_utoa(num);
	get_flag(data, flag, input_string);
	int_rule(flag, writes, input_string);
	ret_value = write_int(flag, writes, input_string);
	free(writes);
	return (ret_value);
}

int			ft_int(char *data, va_list ap, t_flag *flag)
{
	t_write			*writes;
	char			*input_string;
	int				num;
	int				ret_value;

	if (!(writes = malloc(sizeof(t_write) * 1)))
		return (MALLOC_ERROR);
	num = va_arg(ap, int);
	input_string = ft_itoa(num);
	if (*input_string == '-')
	{
		*input_string = '\0';
		input_string++;
		flag->minus_flag = TRUE;
	}
	get_flag(data, flag, input_string);
	int_rule(flag, writes, input_string);
	ret_value = write_int(flag, writes, input_string);
	free(writes);
	return (ret_value);
}
