/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 16:35:33 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/02 16:39:56 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len_llbase(long long num)
{
	size_t				len;
	unsigned long long	cp_num;

	len = 0;
	cp_num = num;
	while (cp_num >= 16)
	{
		len++;
		cp_num /= 16;
	}
	return (++len);
}

char			*ft_lltoa_base(long long num)
{
	size_t				len;
	size_t				idx;
	unsigned long long	cp_num;
	char				*result;

	len = get_len_llbase(num);
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	result[len] = 0;
	idx = 0;
	cp_num = (unsigned long long)num;
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
