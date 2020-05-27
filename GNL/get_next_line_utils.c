/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 14:24:21 by junhpark          #+#    #+#             */
/*   Updated: 2020/05/27 16:20:50 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*string_dup_until_nl(char *s, size_t size)
{
	char		*str;
	size_t		idx;

	if (!(str = malloc(sizeof(char) * (size + 1))))
		return ((char *)ERROR);
	idx = 0;
	while (idx < size)
	{
		str[idx] = s[idx];
		idx++;
	}
	str[idx] = NU;
	return (str);
}

size_t		countNewline(char const *str)
{
	size_t			index;

	if (str == (char const *)NU)
		return (ERROR);
	index = 0;
	while (str[index])
	{
		if (str[index] == NL)
			return (index);
		index++;
	}
	return (ERROR);
}

int			back_up_data(char **new, char **backUp, char *buf, int strLength)
{
	int			backUpidx;
	int			bufidx;

	backUpidx = 0;
	while (*backUp && (*backUp)[backUpidx] && backUpidx < strLength)
	{
		(*new)[backUpidx] = (*backUp)[backUpidx];
		backUpidx++;
	}
	bufidx = 0;
	while (buf && buf[bufidx] && (backUpidx + bufidx) < strLength)
	{
		(*new)[backUpidx + bufidx] = buf[bufidx];
		bufidx++;
	}
	(*new)[backUpidx + bufidx] = NU;
	return (backUpidx + bufidx);
}

size_t		get_length(char const *str)
{
	size_t			count;

	if (str == (char const *)NU)
		return ((size_t)NU);
	count = 0;
	while (str[count])
		count++;
	return (count);
}

int			set_memory_null(void *str, size_t size)
{
	size_t			count;

	if (str == NU)
	{
		return (ERROR);
	}
	count = 0;
	while (count < size)
	{
		((char *)str)[count] = NU;
		count++;
	}
	return (count);
}
