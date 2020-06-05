/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:34:16 by junhpark          #+#    #+#             */
/*   Updated: 2020/06/05 21:18:56 by junhpark         ###   ########.fr       */
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

# define NLL '\0'

typedef struct	s_flag
{
	int		width;
	int		str_len;
	int		left_range;
	int		zero_fill;
	int		padding_left;
	int		padding_right;
}				t_flag;

int			ft_printf(const char *format, ...);
int			allocate_write_by_conv(char *format, va_list ap);
int			inspect_chunk(char *chr, char *chunk);
char		*prepare_data(char *format, int data_len);
int			get_data_len(char *format);

# endif
