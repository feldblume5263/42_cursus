/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:34:16 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/19 18:06:45 by junhpark         ###   ########.fr       */
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
# define MALLOC_ERROR 0

# define NLL '\0'

typedef struct	s_flag
{
	int			str_len;
	int			width;
	int			width_minus;
	int			precision;
	int			precision_remove;
	int			left_range;
	int			zero_fill;
	int			minus_flag;
	int			ischar;
}				t_flag;

typedef struct	s_write
{
	int			padding;
	int			zero;
	int			length;
}				t_write;

//prepare data
int				ft_printf(const char *format, ...);
int				write_by_conv(char *format, va_list ap);
int				inspect_chunk(char *chr, char *chunk);
char			*prepare_data(char *format, int data_len);
int				get_data_len(char *format);
int				wrirte_data_from_ap(char *data, va_list ap, int data_len);

//flag utils
void			prepare_flag(char *data, t_flag *flag, va_list ap);
void			get_flag(char *data, t_flag *flag, char *input_data);
int				get_width(char *data, t_flag *flag);
int				get_precision(char *data, t_flag *flag);
int				get_range(char *data, t_flag *flag);
int				get_zero(char *data, t_flag *flag);

//int & unsinged int
int				ft_int(char *data, va_list ap, t_flag *flag);
int				ft_unsigned_int(char *data, va_list ap, t_flag *flag);
void			int_rule(t_flag *flag, t_write *writes, char *input_string);
int				write_int(t_flag *flag, t_write *writes, char *input_string);
int				write_int_b(t_flag *flag, t_write *writes);

//char
int				ft_char(char *data, va_list ap, t_flag *flag);
void			char_rule(t_flag *flag, t_write *writes);
int				write_char(t_write *writes, char input_string);

//string
int				ft_string(char *data, va_list ap, t_flag *flag);
void			string_rule(t_flag *flag, t_write *writes, char *input_string);
int				write_string(t_flag *flag, t_write *writes, char *input_string);

//hexa
int				ft_hexa_low(char *data, va_list ap, t_flag *flag);
int				ft_hexa_up(char *data, va_list ap, t_flag *flag);
void			hexa_rule(t_flag *flag, t_write *writes, char *input_string);
int				write_hexa(t_flag *flag, t_write *writes, char *input_string);
int				write_hexa_b(t_flag *flag, t_write *writes);

//pointer
int				ft_pointer(char *data, va_list ap, t_flag *flag);
void			pointer_rule(t_flag *flag, t_write *writes, char *input_string);
int				write_pointer(t_flag *flag, t_write *writes, char *input_string);

//percent
int				ft_percent(char *data, t_flag *flag);
void			percent_rule(char *data, t_flag *flag, t_write *writes);
int				write_percent(t_write *writes, t_flag *flag);

#endif
