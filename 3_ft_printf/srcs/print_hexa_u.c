/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 14:39:41 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/15 20:10:15 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			write_hexa_u_with_flag(char *input_string, t_flag *flag)
{
	int				padding;
	int				write_idx;
	int				str_len;

	str_len = ft_strlen(input_string);
	padding = get_padding(flag);
	write_idx = write_padding(padding);
	write_idx += write_zero(flag, str_len);
	if (!(ft_atoi(input_string) == 0 && flag->precision == 0 \
		&& flag->precision_remove == FALSE))
	{
		write(1, input_string, str_len);
		write_idx += str_len;
	}
	while (write_idx < flag->width)
	{
		write(1, " ", 1);
		write_idx++;
	}
	return (write_idx);
}

void		make_hexa_u_flag(t_flag *flag, char *data, char *input_string)
{
	int				str_len;

	flag->real_zero = FALSE;
	str_len = ft_strlen(input_string);
	if (*input_string == '0')
		flag->real_zero = TRUE;
	flag->left_range = get_range(data, flag);
	flag->zero_fill = find_zero(data);
	flag->precision = get_precision(data, str_len, flag);
	flag->width = get_width(data, str_len, flag);
}

int			ft_hexa_u(char *data, va_list ap, t_flag *flag)
{
	char			*input_string;
	unsigned int	num;
	int				ret;

	get_star(data, flag, ap);
	num = va_arg(ap, unsigned int);
	flag->minus_flag = FALSE;
	input_string = ft_utoa_base_up(num);
	make_hexa_u_flag(flag, data, input_string);
	ret = write_hexa_l_with_flag(input_string, flag);
	free(flag);
	return (ret);
}
