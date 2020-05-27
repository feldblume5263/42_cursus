/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 16:43:00 by junhpark          #+#    #+#             */
/*   Updated: 2020/05/27 16:20:51 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			return_value(int readByte, char **line, char **backUp, char **buf)
{
	if (readByte < 0)
	{
		free(*buf);
		return (ERROR);
	}
	if (make_string_except_nl(line, &(*backUp)) == LINE)
	{
		free(*buf);
		return (LINE);
	}
	free(*backUp);
	free(*buf);
	*backUp = 0;
	return (ENDOFFILE);
}

int			make_string_except_nl(char **line, char **backUp)
{
	char		*temp;
	int			sizeBeforeNL;
	int			backUp_size;

	if ((sizeBeforeNL = count_newline(*backUp)) == ERROR)
	{
		*line = string_dup_until_nl(*backUp, get_length(*backUp));
		return (ENDOFFILE);
	}
	*line = string_dup_until_nl(*backUp, sizeBeforeNL);
	backUp_size = get_length(&(*backUp)[sizeBeforeNL + 1]);
	temp = string_dup_until_nl(&(*backUp)[sizeBeforeNL + 1], backUp_size);
	free(*backUp);
	*backUp = temp;
	return (LINE);
}

int			copy_buf_to_backup(char **backUp, char *buf, int readByte)
{
	char			*new;
	int				strLength;

	strLength = get_length(*backUp) + readByte;
	if (!(new = malloc(sizeof(char) * (strLength + 1))))
	{
		free(buf);
		return (ERROR);
	}
	back_up_data(&new, backUp, buf, strLength);
	free(*backUp);
	*backUp = new;
	return (strLength);
}

int			inspect_input_validation(int fd, char **line, char **buf)
{
	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0 ||\
		!(*buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (ERROR);
	return (set_memory_null(*buf, BUFFER_SIZE + 1));
}

int			get_next_line(int fd, char **line)
{
	static char		*backUp[OPEN_MAX] = { 0, };
	char			*buf;
	int				readByte;

	if (inspect_input_validation(fd, line, &buf) == ERROR)
		return (ERROR);
	while ((readByte = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if (copy_buf_to_backup(&(backUp[fd]), buf, readByte) == ERROR)
			return (ERROR);
		if (count_newline(backUp[fd]) != (size_t)ERROR)
		{
			free(buf);
			return (make_string_except_nl(line, &(backUp[fd])));
		}
	}
	return (return_value(readByte, line, &(backUp[fd]), &buf));
}
