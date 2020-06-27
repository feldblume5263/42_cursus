/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 17:25:11 by junhpark          #+#    #+#             */
/*   Updated: 2020/06/27 15:57:56 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		make_u_ten(int count_ten)
{
	int				ten;

	ten = 1;
	while (count_ten > 0)
	{
		ten *= 10;
		count_ten--;
	}
	return (ten);
}

char	*pick_u_number(char *str, long long n, int count_ten, int minus_flag)
{
	int				i;

	i = 0;
	if (minus_flag == 1)
	{
		str[i] = '-';
		i++;
	}
	while (count_ten >= 0)
	{
		str[i] = (n / make_u_ten(count_ten)) + 48;
		n -= (str[i] - 48) * make_u_ten(count_ten);
		i++;
		count_ten--;
	}
	str[i] = '\0';
	return (str);
}

char	*make_str(long long n, int count_ten, int minus_flag)
{
	char			*str;
	int				i ;

	if (minus_flag == 0)
	{
		if (!(str = (char *)malloc(sizeof(char) * (count_ten + 2))))
			return (0);
	}
	else
	{
		if (!(str = (char *)malloc(sizeof(char) * (count_ten + 3))))
			return (0);
		n *= (-1);
	}
	i = 0;
	str = pick_u_number(str, n, count_ten, minus_flag);
	return (str);
}

char	*ft_u_itoa(unsigned int n)
{
	unsigned int	cp_n;
	int				count_ten;
	int				minus_flag;
	char			*str;

	count_ten = 0;
	cp_n = n;
	minus_flag = 0;
	if (cp_n < 0)
	{
		cp_n *= (-1);
		minus_flag++;
	}
	while (cp_n >= 10)
	{
		cp_n /= 10;
		count_ten++;
	}
	cp_n = n;
	str = make_str(cp_n, count_ten, minus_flag);
	return (str);
}
