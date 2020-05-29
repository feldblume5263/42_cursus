/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 16:17:26 by junhpark          #+#    #+#             */
/*   Updated: 2020/04/12 15:45:36 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list		*copy;
	t_list		*temp;

	copy = *lst;
	while (copy && del)
	{
		temp = copy->next;
		ft_lstdelone(copy, del);
		copy = temp;
	}
	*lst = NULL;
}
