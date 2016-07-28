/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 19:07:36 by scebula           #+#    #+#             */
/*   Updated: 2016/07/25 18:06:02 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				set_data(t_ray *ray, t_c_data *c, t_vector *array)
{
	if (ray->dir->x < 0)
	{
		c->step->x = -1;
		c->next_dist->x = (ray->pos->x - array->x) * c->dist->x;
	}
	else
		c->next_dist->x = (array->x + 1.0 - ray->pos->x) * c->dist->x;
	if (ray->dir->y < 0)
	{
		c->step->y = -1;
		c->next_dist->y = (ray->pos->y - array->y) * c->dist->y;
	}
	else
		c->next_dist->y = (array->y + 1 - ray->pos->y) * c->dist->y;
	return (1);
}

void			searching_for_wall(t_ray *ray, t_c_data *c,
		t_vector *array, t_data *d)
{
	int i;
	int w;

	w = WIDTH;
	i = 0;
	while (c->wall == 0)
	{
		if (c->next_dist->x < c->next_dist->y)
		{
			c->next_dist->x += c->dist->x;
			array->x += c->step->x;
			c->dir = 0;
		}
		else
		{
			c->next_dist->y += c->dist->y;
			array->y += c->step->y;
			c->dir = 1;
		}
		if (d->map[(int)array->y][(int)array->x] != '0')
			c->wall = d->map[(int)array->y][(int)array->x] - '0';
		if (c->x == (w >> 1) && d->text_gun == 11 && i++ == 0)
			d->map[(int)array->y][(int)array->x] = '1';
	}
}

int				dda_algorithm(t_ray *ray, t_c_data *c,
		t_vector *array, t_data *d)
{
	int w;

	w = WIDTH;
	searching_for_wall(ray, c, array, d);
	if (c->x == (w >> 1) && d->text_gun == 0 &&
			((int)array->x != 0 && (int)array->y != 0) &&
			((int)array->x != (d->sizex - 1) &&
			(int)array->y != (d->sizey - 1)))
		d->map[(int)array->y][(int)array->x] = 0 + '0';
	else if (c->x == (w >> 1) && d->text_gun > 0 && d->text_gun < 11)
		d->map[(int)array->y][(int)array->x] = d->text_gun + '0';
	if (c->dir == 0)
		c->range = (array->x - ray->pos->x + (1 - c->step->x) / 2) /
			ray->dir->x;
	else
		c->range = (array->y - ray->pos->y + (1 - c->step->y) / 2) /
			ray->dir->y;
	return (0);
}
