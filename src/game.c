/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 19:09:42 by scebula           #+#    #+#             */
/*   Updated: 2016/07/25 16:13:51 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	fire_forward(t_data *d)
{
	if (d->map[(int)(d->eye->pos->y)][(int)(d->eye->pos->x +
				d->eye->dir->x * d->e->move_forward_speed)] == 10 + '0')
		d->fire = 1;
	if (d->map[(int)(d->eye->pos->y + d->eye->dir->y *
				d->e->move_forward_speed)][(int)(d->eye->pos->x)] == 10 + '0')
		d->fire = 1;
}

void	fire_backward(t_data *d)
{
	if (d->map[(int)(d->eye->pos->y)][(int)(d->eye->pos->x -
				d->eye->dir->x * d->e->move_backward_speed)] == 10 + '0')
		d->fire = 1;
	if (d->map[(int)(d->eye->pos->y - d->eye->dir->y *
				d->e->move_backward_speed)][(int)(d->eye->pos->x)] == 10 + '0')
		d->fire = 1;
}

void	fire_strafe_right(t_data *d)
{
	if (d->map[(int)(d->eye->pos->y)][(int)(d->eye->pos->x +
				d->eye->screen->x * d->e->move_forward_speed)] == 10 + '0')
		d->fire = 1;
	if (d->map[(int)(d->eye->pos->y + d->eye->screen->y *
				d->e->move_forward_speed)][(int)(d->eye->pos->x)] == 10 + '0')
		d->fire = 1;
}

void	fire_strafe_left(t_data *d)
{
	if (d->map[(int)(d->eye->pos->y)][(int)(d->eye->pos->x -
				d->eye->screen->x * d->e->move_forward_speed)] == 10 + '0')
		d->fire = 1;
	if (d->map[(int)(d->eye->pos->y - d->eye->screen->y *
				d->e->move_forward_speed)][(int)(d->eye->pos->x)] == 10 + '0')
		d->fire = 1;
}

void	handle_bounce(t_data *d)
{
	d->e->backward = 1;
	d->e->turn = 0;
	d->e->strafe_right = 0;
	d->e->strafe_left = 0;
	d->e->bounce = 10;
	d->e->move_backward_speed = 0.3;
	d->m->shift = 0;
	d->e->move_forward_speed = 0.10234230;
}
