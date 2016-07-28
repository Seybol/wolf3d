/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 19:08:24 by scebula           #+#    #+#             */
/*   Updated: 2016/07/24 22:30:53 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				ft_mouse_julia(int x, int y, void *param)
{
	t_data		*i;
	int			diffx;
	static int	f = 1;

	i = (t_data *)param;
	if (i->mouse)
	{
		if (f)
		{
			i->mx = x;
			f = 0;
		}
		diffx = i->mx - x;
		i->e->turn_speed = (diffx > 0) ? 0.08 : -0.08;
		if (diffx == 0)
			i->e->turn_speed = 0;
		i->e->turn = 1;
		display(i);
		i->e->turn = 0;
		i->mx = x;
		(void)y;
	}
	return (1);
}
