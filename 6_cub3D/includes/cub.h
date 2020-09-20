/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhpark <junhpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 14:24:11 by junhpark          #+#    #+#             */
/*   Updated: 2020/09/20 14:24:13 by junhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"

# define KEY_Q					12
# define KEY_W					13
# define KEY_E					14
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2
# define KEY_LEFT				123
# define KEY_RIGHT				124

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17

typedef struct	s_img
{
	void		*img;
	int			*data;
	int			bpp;
	int			size_l;
	int			endian;
	int			img_width;
	int			img_height;
}				t_img;

typedef struct	s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
}				t_game;

#endif
