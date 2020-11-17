/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Feldblume <Feldblume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 16:43:00 by junhpark          #+#    #+#             */
/*   Updated: 2020/11/17 18:30:57 by Feldblume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int				return_value(int readbyte,
	char **line, char **back_up, char **buf)
{
	if (readbyte < 0)
	{
		free(*buf);
		return (ERROR);
	}
	if (make_string_except_nl(line, &(*back_up)) == LINE)
	{
		free(*buf);
		return (LINE);
	}
	free(*back_up);
	free(*buf);
	*back_up = 0;
	return (ENDOFFILE);
}

int				make_string_except_nl(char **line, char **back_up)
{
	char		*temp;
	int			size_before_nl;
	int			back_up_size;

	if ((size_before_nl = count_newline(*back_up)) == ERROR)
	{
		*line = string_dup_until_nl(*back_up, get_length(*back_up));
		return (ENDOFFILE);
	}
	*line = string_dup_until_nl(*back_up, size_before_nl);
	back_up_size = get_length(&(*back_up)[size_before_nl + 1]);
	temp = string_dup_until_nl(&(*back_up)[size_before_nl + 1], back_up_size);
	free(*back_up);
	*back_up = temp;
	return (LINE);
}

int				copy_buf_to_back_up(char **back_up, char *buf, int readbyte)
{
	char		*new;
	int			str_length;

	str_length = get_length(*back_up) + readbyte;
	if (!(new = malloc(sizeof(char) * (str_length + 1))))
	{
		free(buf);
		return (ERROR);
	}
	back_up_data(&new, back_up, buf, str_length);
	free(*back_up);
	*back_up = new;
	return (str_length);
}

int				inspect_input_validation(int fd, char **line, char **buf)
{
	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0 ||\
		!(*buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (ERROR);
	return (set_memory_null(*buf, BUFFER_SIZE + 1));
}

int				get_next_line(int fd, char **line)
{
	static char	*back_up[OPEN_MAX] = { 0, };
	char		*buf;
	int			readbyte;

	if (inspect_input_validation(fd, line, &buf) == ERROR)
		return (ERROR);
	while ((readbyte = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if (copy_buf_to_back_up(&(back_up[fd]), buf, readbyte) == ERROR)
			return (ERROR);
		if (count_newline(back_up[fd]) != (size_t)ERROR)
		{
			free(buf);
			return (make_string_except_nl(line, &(back_up[fd])));
		}
	}
	return (return_value(readbyte, line, &(back_up[fd]), &buf));
}
