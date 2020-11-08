/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 16:49:42 by junhpark          #+#    #+#             */
/*   Updated: 2020/04/12 15:55:52 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*p;
	t_list		*ret;

	p = 0;
	while (lst && f)
	{
		if (p)
		{
			if (!(p->next = ft_lstnew(f(lst->content))))
			{
				ft_lstclear(&ret, del);
				return (NULL);
			}
			p = p->next;
		}
		else
		{
			if (!(p = ft_lstnew(f(lst->content))))
				return (NULL);
			ret = p;
		}
		p->next = NULL;
		lst = lst->next;
	}
	return (ret);
}
