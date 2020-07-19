/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 15:57:21 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/04 20:57:46 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_ulen(unsigned int num)
{
	size_t					len;
	unsigned int			cp_num;

	len = 0;
	cp_num = (unsigned long long)num;
	if (cp_num < 0)
	{
		len++;
		cp_num *= -1;
	}
	while (cp_num >= 10)
	{
		len++;
		cp_num /= 10;
	}
	return (++len);
}

char			*ft_utoa(unsigned int num)
{
	size_t					len;
	size_t					idx;
	unsigned int			cp_num;
	char					*result;

	len = get_ulen(num);
	cp_num = (unsigned long long)num;
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	result[len] = 0;
	idx = 0;
	while (idx < len)
	{
		result[len - idx - 1] = cp_num % 10 + '0';
		cp_num /= 10;
		idx++;
	}
	return (result);
}
