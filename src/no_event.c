/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 19:25:41 by scebula           #+#    #+#             */
/*   Updated: 2016/07/24 23:48:57 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	gif_creation(t_data *d)
{
	static int			i = 0;

	gettimeofday(&d->actual_time, NULL);
	i = (i < 31) ? (i + 1) : 0;
	mlx_destroy_image(d->mlx, d->textures[9]->img);
	d->textures[9] = ft_init_img(d, ft_strcat_new("gif/",
				d->gif1[i]), "fire");
	remove_transparency(d->textures[9]);
}

void	weapon_movement(t_data *d)
{
	static int			incr = -1;

	gettimeofday(&d->actual_time2, NULL);
	if (d->run < -102 && incr < 0)
		incr = 1;
	else if (d->run > 3 && incr > 0)
		incr = -1;
	d->run = (d->m->shift) ? (d->run + (d->m->shift * 3 * incr))
		: (d->run + incr);
}

int		noevent(void *p)
{
	t_data				*d;
	struct timeval		current;

	gettimeofday(&current, NULL);
	d = (t_data*)p;
	if ((current.tv_usec - d->actual_time.tv_usec > 100000 ||
				current.tv_sec > d->actual_time.tv_sec))
		gif_creation(d);
	if ((current.tv_usec - d->actual_time2.tv_usec > 100 ||
				current.tv_sec > d->actual_time2.tv_sec))
		weapon_movement(d);
	if (d->e->first_image == 1)
		d->e->first_image = 0;
	display(d);
	return (0);
}
