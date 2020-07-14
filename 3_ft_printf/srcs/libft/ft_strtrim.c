/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:44:16 by junhpark          #+#    #+#             */
/*   Updated: 2020/04/12 15:47:03 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ins(char str, char const *set)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (str == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;
	int		i;

	if (!(s1) || !(set))
		return (0);
	start = 0;
	end = 0;
	i = 0;
	while (s1[start] && ft_ins(s1[start], set) == 1)
		start++;
	if (!s1[start])
		return (str = ft_strdup(""));
	end = ft_strlen(s1) - 1;
	while (ft_ins(s1[end], set) == 1)
		end--;
	if (!(str = (char *)malloc(sizeof(char) * (end - start + 2))))
		return (0);
	while (start <= end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
