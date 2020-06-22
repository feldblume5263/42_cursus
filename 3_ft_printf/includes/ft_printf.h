/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:34:16 by junhpark          #+#    #+#             */
/*   Updated: 2020/06/17 16:29:17 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define CONV "cspdiuxX%"
# define FLAG ".-*0"

# define TRUE 1
# define FALSE 0
# define ERROR -1

# define NLL '\0'

typedef struct	s_flag
{
	int		width;
	int		precision;
	int		left_range;
	int		zero_fill;
}				t_flag;

int			ft_printf(const char *format, ...);
int			write_by_conv(char *format, va_list ap);
int			inspect_chunk(char *chr, char *chunk);
char		*prepare_data(char *format, int data_len);
int			get_data_len(char *format);
int			wrirte_data_from_ap(char *data, va_list ap, int data_len);
int			get_width(char *data, int flag_width, char *input_string, int data_len);
int			get_range(char *data, int flag_width);
int			get_precision(char *data, char *input_string);
int			find_zero(char *data);
void		write_int_with_flag(char *input_string, t_flag *data_flag);
int			ft_int(char *data, va_list ap, int data_len, t_flag *data_flag);

# endif
