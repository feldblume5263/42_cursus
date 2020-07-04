/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 14:18:42 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/04 19:41:46 by junhpark         ###   ########.fr       */
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
	char	*ptr = "abcde";
	ft_printf("\n");
	result_f = ft_printf("f = [%08d]\n", -12345);
	result_r =    printf("r = [%08d]\n", -12345);
	printf("result_f = %d\nresult_r = %d\n", result_f, result_r);
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
	result_f = ft_printf("f = [%d]\n", -2147483647);
	result_r =    printf("r = [%d]\n", -2147483647);
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
	result_f = ft_printf("f = [%c]\n", 'd');
	result_r =    printf("r = [%c]\n", 'd');
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%5.c]\n", 'd');
	result_r =    printf("r = [%5.c]\n", 'd');
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%3c]\n", 'd');
	result_r =    printf("r = [%3c]\n", 'd');
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%-3c]\n", 'd');
	result_r =    printf("r = [%-3c]\n", 'd');
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%*c]\n", -3, 'd');
	result_r =    printf("r = [%*c]\n", -3, 'd');
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%*c]\n", 3, 'd');
	result_r =    printf("r = [%*c]\n", 3, 'd');
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%s]\n", "life is 42");
	result_r =    printf("r = [%s]\n", "life is 42");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%15.s]\n", "life is 42");
	result_r =    printf("r = [%15.s]\n", "life is 42");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%15s]\n", "life is 42");
	result_r =    printf("r = [%15s]\n", "life is 42");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%-15s]\n", "life is 42");
	result_r =    printf("r = [%-15s]\n", "life is 42");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%*s]\n", -15, "life is 42");
	result_r =    printf("r = [%*s]\n", -15, "life is 42");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%*s]\n", 15, "life is 42");
	result_r =    printf("r = [%*s]\n", 15, "life is 42");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%*.4s]\n", -15, "life is 42");
	result_r =    printf("r = [%*.4s]\n", -15, "life is 42");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%*.4s]\n", 15, "life is 42");
	result_r =    printf("r = [%*.4s]\n", 15, "life is 42");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%s]\n", "사십이서울");
	result_r =    printf("r = [%s]\n", "사십이서울");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%X]\n", number);
	result_r =    printf("r = [%X]\n", number);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%X]\n", 123);
	result_r =    printf("r = [%X]\n", 123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%10.5X]\n", 123);
	result_r =    printf("r = [%10.5X]\n", 123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%X]\n", -1);
	result_r =    printf("r = [%X]\n", -1);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%X]\n", 132);
	result_r =    printf("r = [%X]\n", 132);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%10.5X]\n", 123332);
	result_r =    printf("r = [%10.5X]\n", 123332);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%10.5X]\n", -123);
	result_r =    printf("r = [%10.5X]\n", -123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%X]\n", 143);
	result_r =    printf("r = [%X]\n", 143);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f결과 = [%X]\n", 14323);
	result_r =    printf("r결과 = [%X]\n", 14323);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%x]\n", number);
	result_r =    printf("r = [%x]\n", number);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%x]\n", -123);
	result_r =    printf("r = [%x]\n", -123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%10.5x]\n", 123);
	result_r =    printf("r = [%10.5x]\n", 123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%x]\n", -1);
	result_r =    printf("r = [%x]\n", -1);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%x]\n", 1345);
	result_r =    printf("r = [%x]\n", 1345);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%10.5x]\n", 123);
	result_r =    printf("r = [%10.5x]\n", 123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%10.5x]\n", 12323);
	result_r =    printf("r = [%10.5x]\n", 12323);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%x]\n", 143);
	result_r =    printf("r = [%x]\n", 143);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f결과 = [%x]\n", 14332);
	result_r =    printf("r결과 = [%x]\n", 14332);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%p]\n", ptr);
	result_r =    printf("r = [%p]\n", ptr);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%20p]\n", ptr);
	result_r =    printf("r = [%20p]\n", ptr);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%-20p]\n", ptr);
	result_r =    printf("r = [%-20p]\n", ptr);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%20p]\n", ptr);
	result_r =    printf("r = [%20p]\n", ptr);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%-20p]\n", ptr);
	result_r =    printf("r = [%-20p]\n", ptr);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%-20p]\n", (void *)0);
	result_r =    printf("r = [%-20p]\n", (void *)0);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%-20p]\n", NULL);
	result_r =    printf("r = [%-20p]\n", NULL);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%-7.5d]\n", -1345);
	result_r =    printf("r = [%-7.5d]\n", -1345);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
}
