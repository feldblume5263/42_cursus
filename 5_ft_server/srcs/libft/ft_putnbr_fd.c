/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:56:54 by junhpark          #+#    #+#             */
/*   Updated: 2020/03/26 02:28:12 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_putnbr_fd(int n, int fd)
{
	char		num;
	long long	cp_n;

	cp_n = (long long)n;
	if (cp_n < 0)
	{
		write(fd, "-", 1);
		cp_n *= (-1);
	}
	if (cp_n >= 0)
	{
		if (cp_n >= 10)
			ft_putnbr_fd((int)(cp_n / 10), fd);
		num = (cp_n % 10) + 48;
	}
	write(fd, &num, 1);
}
