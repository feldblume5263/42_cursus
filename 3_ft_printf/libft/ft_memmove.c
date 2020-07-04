/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:43:00 by junhpark          #+#    #+#             */
/*   Updated: 2020/04/13 22:09:29 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void *src, size_t n)
{
	if (src < dest && dest < src + n)
	{
		while (n > 0)
		{
			n--;
			((char*)dest)[n] = ((char*)src)[n];
		}
		return (dest + n);
	}
	return (ft_memcpy(dest, src, n));
}
