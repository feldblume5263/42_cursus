/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:34:16 by junhpark          #+#    #+#             */
/*   Updated: 2020/06/04 15:16:32 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define CONV "cspdiuxX%"
# define FLAG "-0.*"

# define TRUE 1
# define FALSE 0
# define ERROR -1

# define NULL '\0'

typedef struct	s_flag
{
	int		width;
	int		str_len;
	int		left_range;
	int		zero_fill;
	int		padding_left;
	int		padding_right;
}				t_flag;

# endif
