/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Feldblume <Feldblume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 14:24:21 by junhpark          #+#    #+#             */
/*   Updated: 2020/11/17 16:55:14 by Feldblume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

char			*string_dup_until_nl(char *s, size_t size)
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
	str[idx] = '\0';
	return (str);
}

size_t			count_newline(char const *str)
{
	size_t		index;

	if (str == (char const *)'\0')
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

int				back_up_data(char **new, char **back_up, char *buf, int str_length)
{
	int			back_upidx;
	int			bufidx;

	back_upidx = 0;
	while (*back_up && (*back_up)[back_upidx] && back_upidx < str_length)
	{
		(*new)[back_upidx] = (*back_up)[back_upidx];
		back_upidx++;
	}
	bufidx = 0;
	while (buf && buf[bufidx] && (back_upidx + bufidx) < str_length)
	{
		(*new)[back_upidx + bufidx] = buf[bufidx];
		bufidx++;
	}
	(*new)[back_upidx + bufidx] = '\0';
	return (back_upidx + bufidx);
}

size_t			get_length(char const *str)
{
	size_t		count;

	if (str == (char const *)'\0')
		return ((size_t)'\0');
	count = 0;
	while (str[count])
		count++;
	return (count);
}

int				set_memory_null(void *str, size_t size)
{
	size_t		count;

	if (str == NULL)
	{
		return (ERROR);
	}
	count = 0;
	while (count < size)
	{
		((char *)str)[count] = '\0';
		count++;
	}
	return (count);
}
