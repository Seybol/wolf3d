/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 19:14:30 by scebula           #+#    #+#             */
/*   Updated: 2016/07/24 22:31:23 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

void		test_forward(t_data *d)
{
	if (d->e->forward)
	{
		fire_forward(d);
		if (d->map[(int)(d->eye->pos->y)][(int)(d->eye->pos->x +
					d->eye->dir->x * d->e->move_forward_speed)] == '0')
			d->eye->pos->x += d->eye->dir->x * d->e->move_forward_speed;
		else if (d->m->shift)
			handle_bounce(d);
		if (d->map[(int)(d->eye->pos->y + d->eye->dir->y *
					d->e->move_forward_speed)][(int)(d->eye->pos->x)] == '0')
			d->eye->pos->y += d->eye->dir->y * d->e->move_forward_speed;
		else if (d->m->shift)
			handle_bounce(d);
	}
}

void		test_backward(t_data *d)
{
	if (d->e->backward)
	{
		fire_backward(d);
		if (d->map[(int)(d->eye->pos->y)][(int)(d->eye->pos->x -
					d->eye->dir->x * d->e->move_backward_speed)] == '0')
			d->eye->pos->x -= d->eye->dir->x * d->e->move_backward_speed;
		if (d->map[(int)(d->eye->pos->y - d->eye->dir->y *
					d->e->move_backward_speed)][(int)(d->eye->pos->x)] == '0')
			d->eye->pos->y -= d->eye->dir->y * d->e->move_backward_speed;
	}
}

void		test_turn(t_data *d)
{
	double tmp_dirx;
	double tmp_screen;

	if (d->e->turn)
	{
		tmp_dirx = d->eye->dir->x;
		tmp_screen = d->eye->screen->x;
		d->eye->dir->x = d->eye->dir->x * cos(-d->e->turn_speed) -
			d->eye->dir->y * sin(-d->e->turn_speed);
		d->eye->dir->y = tmp_dirx * sin(-d->e->turn_speed) +
			d->eye->dir->y * cos(-d->e->turn_speed);
		d->eye->screen->x = d->eye->screen->x *
			cos(-d->e->turn_speed) - d->eye->screen->y * sin(-d->e->turn_speed);
		d->eye->screen->y = tmp_screen * sin(-d->e->turn_speed) +
			d->eye->screen->y * cos(-d->e->turn_speed);
	}
}

void		test_strafe_right(t_data *d)
{
	if (d->e->strafe_right)
	{
		fire_strafe_right(d);
		if (d->map[(int)(d->eye->pos->y)][(int)(d->eye->pos->x +
					d->eye->screen->x * d->e->move_forward_speed)] == '0')
			d->eye->pos->x += d->eye->screen->x * d->e->move_forward_speed;
		if (d->map[(int)(d->eye->pos->y + d->eye->screen->y *
					d->e->move_forward_speed)][(int)(d->eye->pos->x)] == '0')
			d->eye->pos->y += d->eye->screen->y * d->e->move_forward_speed;
	}
}

void		test_strafe_left(t_data *d)
{
	if (d->e->strafe_left)
	{
		fire_strafe_left(d);
		if (d->map[(int)(d->eye->pos->y)][(int)(d->eye->pos->x -
					d->eye->screen->x * d->e->move_forward_speed)] == '0')
			d->eye->pos->x -= d->eye->screen->x * d->e->move_forward_speed;
		if (d->map[(int)(d->eye->pos->y - d->eye->screen->y *
					d->e->move_forward_speed)][(int)(d->eye->pos->x)] == '0')
			d->eye->pos->y -= d->eye->screen->y * d->e->move_forward_speed;
	}
}
