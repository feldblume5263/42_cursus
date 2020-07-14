/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 17:28:25 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/14 22:39:22 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		int_rule(t_flag *flag, t_write *write, char *input_string)
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
	/*if (flag->minus_flag == TRUE)
		str_len++;
	prec = flag->precision > str_len ? flag->precision : str_len;
	width = flag->width > prec ? flag->width : prec;
	write->padding = width - prec;
	write->zero = prec - flag->str_len;*/
}

int			ft_int(char *data, va_list ap, t_flag *flag)
{
	t_write			*write;
	char			*input_string;
	int				num;

	if (!(write = malloc(sizeof(t_write) * 1)))
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
	int_rule(flag, write, input_string);
	return (0);
}
