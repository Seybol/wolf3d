/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 19:08:06 by scebula           #+#    #+#             */
/*   Updated: 2016/07/24 23:47:38 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	fov(int keycode, t_data *d)
{
	if (keycode == KEY_COMMA && d->e->move_forward_speed < 0.2)
	{
		d->eye->dir->y *= 1 / 1.1;
		d->eye->dir->x *= 1 / 1.1;
		d->e->first_image = 1;
		d->e->move_forward_speed *= 1.1;
	}
	if (keycode == KEY_DOT && d->e->move_forward_speed > 0.1)
	{
		d->eye->dir->y *= 1.1;
		d->eye->dir->x *= 1.1;
		d->e->first_image = 1;
		d->e->move_forward_speed *= 1 / 1.1;
	}
}

static void	numb_key(int keycode, t_data *d)
{
	if (keycode == KEY_4)
		d->text_gun = 4;
	if (keycode == KEY_1)
		d->text_gun = 1;
	if (keycode == KEY_F)
		d->text_gun = 11;
	if (keycode == KEY_5)
		d->text_gun = 5;
	if (keycode == KEY_6)
		d->text_gun = 6;
	if (keycode == KEY_7)
		d->text_gun = 7;
	if (keycode == KEY_8)
		d->text_gun = 8;
	if (keycode == KEY_3)
		d->text_gun = 3;
	if (keycode == KEY_2)
		d->text_gun = 2;
	if (keycode == KEY_9)
		d->text_gun = 9;
	if (keycode == KEY_0)
		d->text_gun = 10;
}

static void	numb_key_release(int keycode, t_data *d)
{
	if (keycode == KEY_4 || keycode == KEY_1 || keycode == KEY_2)
		d->text_gun = -1;
	if (keycode == KEY_F)
		d->text_gun = -1;
	if (keycode == KEY_G)
	{
		d->text_gun = 0;
		display(d);
		d->text_gun = -1;
	}
	if (keycode == KEY_9)
		d->text_gun = -1;
	if (keycode == KEY_5)
		d->text_gun = -1;
	if (keycode == KEY_6)
		d->text_gun = -1;
	if (keycode == KEY_7)
		d->text_gun = -1;
	if (keycode == KEY_8)
		d->text_gun = -1;
	if (keycode == KEY_3)
		d->text_gun = -1;
	if (keycode == KEY_0)
		d->text_gun = -1;
}

int			ft_key_up(int keycode, t_data *d)
{
	numb_key_release(keycode, d);
	if (keycode == KEY_M)
		d->mouse = (d->mouse == 1) ? 0 : 1;
	if (keycode == KEY_ESC)
		ft_close(d, 1);
	if (keycode == KEY_W || keycode == KEY_UP)
		d->e->forward = 0;
	if (keycode == KEY_S || keycode == KEY_BOTTOM)
		d->e->backward = 0;
	if (keycode == KEY_D)
		d->e->strafe_right = 0;
	if (keycode == KEY_A)
		d->e->strafe_left = 0;
	if (keycode == KEY_J || keycode == KEY_L || keycode == KEY_LEFT ||
			keycode == KEY_RIGHT)
		d->e->turn = 0;
	if (keycode == KEY_TAB)
		d->keys = 0;
	if (keycode == KEY_SHIFTL)
	{
		d->m->shift = 0;
		d->e->move_forward_speed = 0.10234230;
	}
	return (1);
}

int			ft_key_press(int keycode, t_data *d)
{
	numb_key(keycode, d);
	fov(keycode, d);
	if (keycode == KEY_W || keycode == KEY_UP)
		d->e->forward = 1;
	if (keycode == KEY_S || keycode == KEY_BOTTOM)
		d->e->backward = 1;
	if (keycode == KEY_D)
		d->e->strafe_right = 1;
	if (keycode == KEY_TAB)
		d->keys = 1;
	if (keycode == KEY_A)
		d->e->strafe_left = 1;
	if (keycode == KEY_SHIFTL)
	{
		d->m->shift = 1;
		d->e->move_forward_speed = 0.20232344;
	}
	if (keycode == KEY_J || keycode == KEY_L || keycode == KEY_LEFT ||
			keycode == KEY_RIGHT)
	{
		d->e->turn = 1;
		d->e->turn_speed = (keycode == KEY_L || keycode == KEY_RIGHT)
			? -0.1 : 0.10;
	}
	return (1);
}
