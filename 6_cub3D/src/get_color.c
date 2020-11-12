/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 21:14:35 by junhpark          #+#    #+#             */
/*   Updated: 2020/11/12 21:17:46 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

char			*make_hexa(int n, char *base)
{
	int			div;
	int			len;
	int			base_len;
	char		*res;

	div = n;
	len = (n == 0) ? 1 : 0;
	base_len = (unsigned int)ft_strlen((char *)base);
	while (div != 0)
	{
		div = div / base_len;
		len++;
	}
	if (len == 1)
		len++;
	if (!(res = ft_calloc((len + 1), sizeof(char))))
		return (NULL);
	res[0] = '0';
	while (len > 0)
	{
		len--;
		res[len] = base[(n % base_len)];
		n = n / base_len;
	}
	return (res);
}

int				get_color_value(char *hexa)
{
	int			ret;
	int			idx;

	ret = 0;
	idx = 0;
	while (hexa[idx])
	{
		if (hexa[idx] >= '0' && hexa[idx] <= '9')
			ret = ret * 16 + hexa[idx] - '0';
		else if (hexa[idx] == 'a')
			ret = ret * 16 + 10;
		else if (hexa[idx] == 'b')
			ret = ret * 16 + 11;
		else if (hexa[idx] == 'c')
			ret = ret * 16 + 12;
		else if (hexa[idx] == 'd')
			ret = ret * 16 + 13;
		else if (hexa[idx] == 'e')
			ret = ret * 16 + 14;
		else if (hexa[idx] == 'f')
			ret = ret * 16 + 15;
		idx++;
	}
	return (ret);
}

int				make_color(char **num)
{
	int			idx;
	int			temp;
	char		*hexa;

	idx = 0;
	hexa = strdup("");
	while (idx < 3)
	{
		temp = ft_atoi(num[idx]);
		hexa = ft_strjoin(hexa, make_hexa(temp, "0123456789abcdef"));
		idx++;
	}
	return (get_color_value(hexa));
}
