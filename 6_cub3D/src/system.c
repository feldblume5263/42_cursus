/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:44:18 by junhpark          #+#    #+#             */
/*   Updated: 2020/11/07 14:48:30 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void			exit_with_error(char *message)
{
	int			size;

	size = ft_strlen(message);
	write(1, message, size);
	exit(0);
}
