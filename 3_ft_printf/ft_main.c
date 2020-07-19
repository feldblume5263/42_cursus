/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 17:25:41 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/19 16:55:25 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int			main(void)
{
	char		*ptr = "abc";
	char		*void_ptr = NULL;

	ft_printf("|%0.4p|\n", ptr);
	   printf("|%0.4p|\n", ptr);
}
