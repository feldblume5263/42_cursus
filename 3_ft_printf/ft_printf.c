/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 14:57:54 by junhpark          #+#    #+#             */
/*   Updated: 2020/06/04 16:40:47 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_put_string(char **format)
{
	char			**str;
	size_t			idx;

	idx = 0;
	while (*format[idx])
	{
		if (*format[idx] == '%')
		{
			idx++;
			convert_to_string();
		}
		idx++;
	}
}

int			ft_printf(const char *format, ...)
{
	char			*res_string;
	va_list			ap;

	va_start(ap, format);
	res_string = ft_put_string(&(*format));
	va_end(ap);
}
