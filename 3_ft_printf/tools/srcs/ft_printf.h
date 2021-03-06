/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:34:16 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/14 17:41:37 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

# define CONV "cspdiuxX%"
# define FLAG ".-*0"

# define TRUE 1
# define FALSE 0
# define ERROR -1

# define NLL '\0'

typedef struct	s_flag
{
	int			width;
	int			precision;
	int			precision_remove;
	int			left_range;
	int			zero_fill;
	int			minus_flag;
	int			real_zero;
	int			x_flag;
	int			zero_minus;
}				t_flag;

int				ft_printf(const char *format, ...);
int				write_by_conv(char *format, va_list ap);
int				inspect_chunk(char *chr, char *chunk);
char			*prepare_data(char *format, int data_len);
int				get_data_len(char *format);
int				wrirte_data_from_ap(char *data, va_list ap, int data_len);
int				get_width(char *data, int str_len, t_flag *flag);
int				get_range(char *data, t_flag *flag);
int				get_precision(char *data, int str_len, t_flag *flag);
int				find_zero(char *data);
int				write_int_with_flag(char *input_string, t_flag *flag);
int				ft_int(char *data, va_list ap, t_flag *flag);
void			make_int_flag(t_flag *flag, \
								char *data, char *input_string);
int				get_padding(t_flag *flag);
int				write_padding(int padding);
int				write_zero(t_flag *flag, int str_len);
int				ft_unsigned_int(char *data, va_list ap, t_flag *flag);
int				ft_char(char *data, va_list ap, t_flag *flag);
void			make_char_flag(t_flag *flag, char *data);
int				write_char_with_flag(char ret_char, t_flag *flag);
int				ft_string(char *data, va_list ap, t_flag *flag);
void			make_string_flag(t_flag *flag, \
								char *data, char *input_string);
int				write_string_with_flag(char *input_string, t_flag *flag);
int				get_str_precision(char *data, t_flag *flag);
int				ft_hexa_u(char *data, va_list ap, t_flag *flag);
void			make_hexa_u_flag(t_flag *flag, \
								char *data, char *input_string);
int				write_hexa_u_with_flag(char *input_string, t_flag *flag);
int				ft_hexa_l(char *data, va_list ap, t_flag *flag);
void			make_hexa_l_flag(t_flag *flag, \
								char *data, char *input_string);
int				write_hexa_l_with_flag(char *input_string, t_flag *flag);
int				ft_pointer(char *data, va_list ap, t_flag *flag);
void			make_pointer_flag(t_flag *flag, \
								char *data, char *input_string);
int				write_pointer_with_flag(char *input_string, t_flag *flag);
int				ft_percent(char *data, va_list ap, t_flag *flag);
void			make_percent_flag(t_flag *flag, char *data);
int				write_percent_with_flag(char ret_char, t_flag *flag);
void			get_star(char *data, t_flag *flag, va_list ap);
int				get_str_width(char *data, t_flag *flag);
void			make_str_flag(t_flag *flag, int str_len);
void			zero_minus_flag(char *data, t_flag *flag);

#endif
