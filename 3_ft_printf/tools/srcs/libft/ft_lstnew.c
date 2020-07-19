/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 14:48:35 by junhpark          #+#    #+#             */
/*   Updated: 2020/04/09 18:43:27 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list	*n_list;

	if (!(n_list = ft_calloc(1, sizeof(t_list))))
		return (0);
	n_list->content = content;
	n_list->next = 0;
	return (n_list);
}
