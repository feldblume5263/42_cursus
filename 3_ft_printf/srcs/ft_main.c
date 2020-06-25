/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 14:18:42 by junhpark          #+#    #+#             */
/*   Updated: 2020/06/25 15:12:24 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"
#include <stdio.h>

int			main(void)
{
	int		result_f;
	int		result_r;

	int		number = 343;

	printf("\n");
	result_f = ft_printf("f = [%d]\n", number);
	result_r =    printf("r = [%d]\n", number);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%d]\n", 123);
	result_r =    printf("r = [%d]\n", 123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%10.5d]\n", 123);
	result_r =    printf("r = [%10.5d]\n", 123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%d]\n", -1);
	result_r =    printf("r = [%d]\n", -1);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%10.5d]\n", -123);
	result_r =    printf("r = [%10.5d]\n", -123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%10.5d]\n", -123);
	result_r =    printf("r = [%10.5d]\n", -123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%d]\n", -143);
	result_r =    printf("r = [%d]\n", -143);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f결과 = [%d]\n", -143);
	result_r =    printf("r결과 = [%d]\n", -143);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);

}
