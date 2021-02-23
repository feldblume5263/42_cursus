/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark </var/mail/junhpark>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 01:32:38 by junhpark          #+#    #+#             */
/*   Updated: 2021/02/24 01:35:41 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int			ft_strlen(char const *str);
char		*ft_strcpy(char *dest, char const *src);
int			ft_strcmp(char const *dest, char const *src);
ssize_t		ft_write(int fd, void const *buf, size_t nbyte);
ssize_t		ft_read(int fd, void const *buf, size_t nbyte);
char		*ft_strdup(char const *ptr);

#endif
