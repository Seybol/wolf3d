/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_t.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 19:07:56 by scebula           #+#    #+#             */
/*   Updated: 2016/07/24 23:09:50 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

static t_draw	*init_draw(double range)
{
	t_draw	*draw;

	draw = (t_draw *)malloc(sizeof(t_draw));
	draw->line_height = (int)(HEIGHT / range);
	draw->start = -draw->line_height / 2 + (HEIGHT >> 1);
	draw->end = draw->line_height / 2 + (HEIGHT >> 1);
	draw->color = 0xffffff;
	if (draw->start < 0)
		draw->start = 0;
	if (draw->end >= HEIGHT)
		draw->end = HEIGHT - 1;
	return (draw);
}

static void		calculate_precise_hit(t_thread *t)
{
	t_data *d;

	d = (t_data *)t->i;
	if (t->c->dir == 1)
		t->c->precise_hit = t->ray->pos->x + ((t->array->y - t->ray->pos->y +
					(1 - t->c->step->y) / 2) / t->ray->dir->y) * t->ray->dir->x;
	else
		t->c->precise_hit = t->ray->pos->y + ((t->array->x - t->ray->pos->x +
					(1 - t->c->step->x) / 2) / t->ray->dir->x) * t->ray->dir->y;
	t->c->precise_hit -= floor((t->c->precise_hit));
}

static int		calculate_precise_texture_x(t_thread *t)
{
	t_data	*d;
	int		text_x;

	d = (t_data *)t->i;
	text_x = (int)(t->c->precise_hit * d->textures[t->c->wall - 1]->x);
	if (t->c->dir == 0 && t->ray->dir->x > 0)
		text_x = d->textures[t->c->wall - 1]->x - text_x - 1;
	if (t->c->dir == 1 && t->ray->dir->y < 0)
		text_x = d->textures[t->c->wall - 1]->x - text_x - 1;
	return (text_x);
}

static void		draw_textures(t_thread *t, int text_x)
{
	t_data	*d;
	t_draw	*draw;
	int		text_y;

	d = (t_data *)t->i;
	draw = init_draw(t->c->range);
	t->c->y = draw->start;
	while (t->c->y < draw->end)
	{
		text_y = (int)fabs(((t->c->y << 1) - HEIGHT + draw->line_height) *
				(d->textures[t->c->wall - 1]->y >> 1) / draw->line_height);
		draw->color = getpixel(text_x, text_y, d->textures[t->c->wall - 1]);
		if (t->c->dir == 1)
			draw->color = (draw->color >> 1) & 0x707070;
		putpixel(t->c->x, t->c->y, draw->color, d->img);
		t->c->y++;
	}
	while (t->c->y < HEIGHT)
	{
		putpixel(t->c->x, t->c->y, 0, d->img);
		putpixel(t->c->x, HEIGHT - t->c->y - 1, 0, d->img);
		t->c->y += 1;
	}
}

int				draw_image_textures(t_thread *t)
{
	calculate_precise_hit(t);
	draw_textures(t, calculate_precise_texture_x(t));
	return (0);
}
