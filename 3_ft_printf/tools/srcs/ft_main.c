/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 17:25:41 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/15 19:55:13 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int			main(void)
{
	//printf("mein Name ist Noah\n", 3);
	ft_printf("mein Name ist Noah%cabc%s%c%d\n", 'a', "abc", 'a', 42);
	printf("mein Name ist Noah%cabc%s%c%d\n", 'a', "abc", 'a', 42);
}
