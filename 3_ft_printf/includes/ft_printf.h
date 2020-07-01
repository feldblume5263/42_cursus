/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:34:16 by junhpark          #+#    #+#             */
/*   Updated: 2020/06/30 18:02:24 by junhpark         ###   ########.fr       */
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
	int		minus_flag;
}				t_flag;

int			ft_printf(const char *format, ...);
int			write_by_conv(char *format, va_list ap);
int			inspect_chunk(char *chr, char *chunk);
char		*prepare_data(char *format, int data_len);
int			get_data_len(char *format);
int			wrirte_data_from_ap(char *data, va_list ap, int data_len);
int			get_width(char *data, int flag_width, int str_len);
int			get_range(char *data, int flag_width);
int			get_precision(char *data, int str_len, t_flag *data_flag);
int			find_zero(char *data);
int			write_int_with_flag(char *input_string, t_flag *data_flag);
int			ft_int(char *data, va_list ap, t_flag *data_flag);
void		make_int_flag(t_flag *data_flag, char *data, int flag_width, char *input_string);
int			get_padding(t_flag *data_flag);
int			write_padding(int padding);
int			write_zero(t_flag *data_flag, int str_len);
int			ft_unsigned_int(char *data, va_list ap, t_flag *data_flag);
int			ft_char(char *data, va_list ap, t_flag *data_flag);
void		make_char_flag(t_flag *data_flag, char *data, int flag_width);
int			write_char_with_flag(char ret_char, t_flag *data_flag);
int			ft_string(char *data, va_list ap, t_flag *data_flag);
void		make_string_flag(t_flag *data_flag, char *data, int flag_width, char *input_string);
int			write_string_with_flag(char *input_string, t_flag *data_flag);
int			get_str_precision(char *data, int str_len, t_flag *data_flag);
int			ft_hexa_u(char *data, va_list ap, t_flag *data_flag);
void		make_hexa_u_flag(t_flag *data_flag, char *data, int flag_width, char *input_string);
int			write_hexa_u_with_flag(char *input_string, t_flag *data_flag);
int			ft_hexa_l(char *data, va_list ap, t_flag *data_flag);
void		make_hexa_l_flag(t_flag *data_flag, char *data, int flag_width, char *input_string);
int			write_hexa_l_with_flag(char *input_string, t_flag *data_flag);

# endif
