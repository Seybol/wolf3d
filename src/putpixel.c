/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 19:28:39 by scebula           #+#    #+#             */
/*   Updated: 2016/07/24 22:31:38 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	putpixel(int x, int y, unsigned int color, t_img *img)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char t;

	b = (color & 0xFF) >> 0;
	g = (color & 0xFF00) >> 8;
	r = (color & 0xFF0000) >> 16;
	t = (color & 0xFF000000) >> 24;
	if (img->endian == 0)
	{
		img->data[(y * img->sl) + x * (img->bpp >> 3)] = b;
		img->data[(y * img->sl) + x * (img->bpp >> 3) + 1] = g;
		img->data[(y * img->sl) + x * (img->bpp >> 3) + 2] = r;
		img->data[(y * img->sl) + x * (img->bpp >> 3) + 3] = t;
	}
	else
	{
		img->data[y * img->sl + x * img->bpp / 8] = (color & 0xFF) >> 0;
		img->data[y * img->sl + x * img->bpp / 8 + 1] = (color & 0xFF00) >> 8;
		img->data[y * img->sl + x * img->bpp / 8 + 2] =
			(color & 0xFF0000) >> 16;
	}
}

int		getpixel(int x, int y, t_img *img)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char t;

	r = img->data[(y * img->sl) + x * (img->bpp >> 3)];
	g = img->data[(y * img->sl) + x * (img->bpp >> 3) + 1];
	b = img->data[(y * img->sl) + x * (img->bpp >> 3) + 2];
	t = img->data[(y * img->sl) + x * (img->bpp >> 3) + 3];
	return ((int)(r) + (int)(g << 8) + (int)(b << 16) + (int)(t << 24));
}
