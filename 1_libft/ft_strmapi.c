/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 18:50:21 by junhpark          #+#    #+#             */
/*   Updated: 2020/04/08 17:07:31 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	if (!(s))
		return (0);
	i = 0;
	if (!(result = ft_strdup(s)))
		return (0);
	while (i < ft_strlen(result))
	{
		result[i] = f(i, result[i]);
		i++;
	}
	return (result);
}
