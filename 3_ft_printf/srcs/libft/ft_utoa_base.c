/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 16:37:17 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/02 16:32:37 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_ulen_base(unsigned int num)
{
	size_t				len;
	unsigned long long	cp_num;

	len = 0;
	cp_num = (unsigned long long)num;
	while (cp_num >= 16)
	{
		len++;
		cp_num /= 16;
	}
	return (++len);
}

char			*ft_utoa_base(unsigned int num)
{
	size_t				len;
	size_t				idx;
	unsigned long long	cp_num;
	char				*result;

	len = get_ulen_base(num);
	cp_num = (unsigned long long)num;
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	result[len] = 0;
	idx = 0;
	while (idx < len)
	{
		if (cp_num % 16 >= 0 && cp_num % 16 <= 9)
			result[len - idx - 1] = cp_num % 16 + '0';
		else if (cp_num % 16 >= 10 && cp_num % 16 <= 15)
			result[len - idx - 1] = cp_num % 16 - 10 + 'a';
		cp_num /= 16;
		idx++;
	}
	return (result);
}
