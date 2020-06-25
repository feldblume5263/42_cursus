/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 19:14:52 by junhpark          #+#    #+#             */
/*   Updated: 2020/04/07 14:15:13 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	t_list			*new;
	unsigned int	count;

	new = lst;
	count = 0;
	while (new)
	{
		new = new->next;
		count++;
	}
	return (count);
}
