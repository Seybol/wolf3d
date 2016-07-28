/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 19:07:47 by scebula           #+#    #+#             */
/*   Updated: 2016/07/24 23:47:13 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void			refresh(t_data *d)
{
	test_forward(d);
	test_backward(d);
	test_turn(d);
	test_strafe_right(d);
	test_strafe_left(d);
}

static void			*thread(void *p)
{
	t_thread		*t;
	int				len;
	t_data			*d;
	int				x;

	t = (t_thread *)p;
	d = (t_data *)t->i;
	len = t->threads * WIDTH >> 3;
	x = ((t->threads - 1) * WIDTH >> 3) - 1;
	while (++x < len)
	{
		t->ray = init_ray(d->eye, x);
		t->array = init_vector((int)t->ray->pos->x, (int)t->ray->pos->y);
		t->c = init_c_data(x, t->ray);
		set_data(t->ray, t->c, t->array);
		dda_algorithm(t->ray, t->c, t->array, d);
		draw_image_textures(t);
		free_all(t);
	}
	pthread_exit(0);
}

static void			display_images(t_data *d)
{
	int w;

	w = WIDTH;
	if (!d->fire)
	{
		mlx_put_image_to_window(d->mlx, d->win, d->img->img, 0, 0);
		mlx_put_image_to_window(d->mlx, d->win, d->weapon->img, (w >> 1) +
				d->run, HEIGHT - 243);
		if (d->m->shift)
			mlx_put_image_to_window(d->mlx, d->win, d->hud2->img, 0, 0);
		else
			mlx_put_image_to_window(d->mlx, d->win, d->hud->img, 0, 0);
		mlx_put_image_to_window(d->mlx, d->win, d->pointer->img, (w >> 1) -
				(d->pointer->x >> 1), (HEIGHT / 2));
		if (d->keys)
			mlx_put_image_to_window(d->mlx, d->win, d->commands->img, 0, 0);
		mlx_destroy_image(d->mlx, d->img->img);
	}
	else if (d->fire == 1)
	{
		mlx_put_image_to_window(d->mlx, d->win, d->gameover->img, 0, 0);
		mlx_destroy_image(d->mlx, d->img->img);
	}
	free(d->img);
}

void				display(t_data *d)
{
	int i;

	d->img = ft_data_img(d, WIDTH, HEIGHT);
	refresh(d);
	i = -1;
	while (++i < 8)
	{
		d->th[i].threads = i + 1;
		d->th[i].i = (t_data *)d;
		pthread_create(&d->th[i].t, NULL, thread, &d->th[i]);
	}
	i = -1;
	while (++i < 8)
		pthread_join(d->th[i].t, NULL);
	display_images(d);
	if (d->e->bounce)
	{
		d->e->bounce--;
		d->e->backward = (d->e->bounce == 0) ? 0 : 1;
		d->e->move_backward_speed = (d->e->bounce == 0) ? 0.05 : 0.3;
		d->m->shift = 0;
		d->e->move_forward_speed = 0.10234230;
	}
}
