/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:35:21 by junhpark          #+#    #+#             */
/*   Updated: 2020/04/05 15:45:49 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j] && (long int)(i + j) < (long int)(n - 1))
	{
		dest[i + j] = src[j];
		j++;
	}
	if (n != 0)
		dest[i + j] = 0;
	while (src[j])
		j++;
	return (n > i ? (i + j) : (j + n));
}
