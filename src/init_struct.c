/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 19:13:31 by scebula           #+#    #+#             */
/*   Updated: 2016/07/27 17:44:00 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

t_event			*init_event(void)
{
	t_event *e;

	e = (t_event *)malloc(sizeof(t_event));
	e->first_image = 1;
	e->forward = 0;
	e->backward = 0;
	e->turn = 0;
	e->strafe_right = 0;
	e->strafe_left = 0;
	e->move_forward_speed = 0.10234230;
	e->move_backward_speed = 0.05;
	e->turn_speed = 0.01;
	e->bounce = 0;
	return (e);
}

t_vector		*init_vector(double x, double y)
{
	t_vector *v;

	v = (t_vector *)malloc(sizeof(t_vector));
	v->x = x;
	v->y = y;
	return (v);
}

t_eye			*init_eye(void)
{
	t_eye *eye;

	eye = (t_eye *)malloc(sizeof(t_eye));
	eye->pos = init_vector(1.5, 1.5);
	eye->dir = init_vector(0.5, 0);
	eye->screen = init_vector(0, 1);
	eye->array = NULL;
	return (eye);
}

t_ray			*init_ray(t_eye *eye, int x)
{
	t_ray	*ray;
	double	width;

	width = WIDTH;
	ray = (t_ray *)malloc(sizeof(t_ray));
	ray->step = (2 * x / width) - 1;
	ray->pos = init_vector(eye->pos->x, eye->pos->y);
	ray->dir = init_vector(eye->dir->x + eye->screen->x *
			ray->step, eye->dir->y + eye->screen->y * ray->step);
	return (ray);
}

t_c_data		*init_c_data(int x, t_ray *ray)
{
	t_c_data *c;

	c = (t_c_data *)malloc(sizeof(t_c_data));
	c->x = x;
	c->y = 0;
	c->dist = init_vector(sqrt(1 + (ray->dir->y * ray->dir->y)
				/ (ray->dir->x * ray->dir->x)),
			sqrt(1 + (ray->dir->x * ray->dir->x) /
				(ray->dir->y * ray->dir->y)));
	c->step = init_vector(1, 1);
	c->wall = 0;
	c->dir = 0;
	c->next_dist = init_vector(0, 0);
	c->range = 0;
	c->precise_hit = 0;
	return (c);
}
