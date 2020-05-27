/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 16:09:10 by junhpark          #+#    #+#             */
/*   Updated: 2020/05/27 16:20:45 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# define OPEN_MAX 256

# define NL '\n'
# define NU '\0'

# define LINE 1
# define ENDOFFILE 0
# define ERROR -1

int			get_next_line(int fd, char **line);
int			inspect_input_validation(int fd, char **line, char **buf);
int			set_memory_null(void *str, size_t size);
int			copy_buf_to_backup(char **backUp, char *buf, int readByte);
size_t		get_length(char const *str);
int			back_up_data(char **new, char **backUp, char *buf, int strLength);
size_t		count_newline(char const *str);
int			make_string_except_nl(char **line, char **backUp);
char		*string_dup_until_nl(char *s, size_t size);
int			return_value(int readByte, char **line, char **backUp, char **buf);

#endif
