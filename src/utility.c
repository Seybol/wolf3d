/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 19:29:00 by scebula           #+#    #+#             */
/*   Updated: 2016/07/24 23:49:15 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		remove_transparency(t_img *img)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < img->y)
	{
		while (x < img->x)
		{
			img->data[(y * img->sl) + x * (img->bpp / 8) + 3] = 0;
			x++;
		}
		y++;
		x = 0;
	}
}

void		free_all(t_thread *t)
{
	free(t->c->step);
	free(t->c->dist);
	free(t->c->next_dist);
	free(t->c);
	free(t->ray->pos);
	free(t->ray->dir);
	free(t->ray);
	free(t->array);
}

void		black_transparency(t_img *img)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < img->y)
	{
		while (x < img->x)
		{
			if ((img->data[(y * img->sl) + x * (img->bpp / 8)] == 0) &&
					(img->data[(y * img->sl) + x * (img->bpp / 8) + 1] == 0) &&
					(img->data[(y * img->sl) + x * (img->bpp / 8) + 2] == 0)
					&& (img->data[(y * img->sl) + x * (img->bpp / 8) + 3] == 0))
				img->data[(y * img->sl) + x * (img->bpp / 8) + 3] = 0x33;
			x++;
		}
		y++;
		x = 0;
	}
}

int			is_between(char x, char a, char b)
{
	if (x < a || x > b)
		return (0);
	return (1);
}

int			check_tab(char **s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[j])
	{
		while (s[j][i])
		{
			if (!is_between(s[j][i], '0', 10 + '0'))
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}
