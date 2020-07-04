/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:48:46 by junhpark          #+#    #+#             */
/*   Updated: 2020/07/01 17:23:08 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int				ft_atoi(const char *str);
char			*ft_itoa(int num);
char			*ft_itoa_base(int num);
char			*ft_itoa_base_ll(long long num);
char			*ft_itoa_base_u(unsigned int num);
char			*ft_itoa_base_u_up(unsigned int num);
char			*ft_itoa_ll(long long num);
char			*ft_itoa_u(unsigned int num);
size_t			ft_strlen(const char *str);

#endif
