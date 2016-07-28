/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 19:11:15 by scebula           #+#    #+#             */
/*   Updated: 2016/07/24 23:47:59 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_img	*ft_init_img(t_data *d, char *dir, char *name)
{
	t_img	*img;

	img = (t_img*)malloc(sizeof(t_img));
	img->img = mlx_xpm_file_to_image(d->mlx, dir, &(img->x), &(img->y));
	img->data = mlx_get_data_addr(img->img, &(img->bpp),
			&(img->sl), &(img->endian));
	img->name = strdup(name);
	return (img);
}
