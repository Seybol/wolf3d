/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 19:07:11 by scebula           #+#    #+#             */
/*   Updated: 2016/07/25 16:26:35 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	free_textures(t_data *d)
{
	int i;

	i = 0;
	while (i < 12)
	{
		mlx_destroy_image(d->mlx, d->textures[i]->img);
		i++;
	}
	mlx_destroy_image(d->mlx, d->weapon->img);
	mlx_destroy_image(d->mlx, d->pointer->img);
	mlx_destroy_image(d->mlx, d->hud->img);
	mlx_destroy_image(d->mlx, d->hud2->img);
	mlx_destroy_image(d->mlx, d->commands->img);
	mlx_destroy_image(d->mlx, d->gameover->img);
}

void		ft_close(t_data *i, char error)
{
	if (i)
	{
		free_textures(i);
		mlx_destroy_window(i->mlx, i->win);
		free(i);
		i = NULL;
	}
	if (error == 1)
		ft_putstr("Program closed successfully.\n");
	else if (error == 2)
		ft_putstr("Error. Your position is out of the map.\n");
	else if (error == 3)
		ft_putstr("Error. Initial position is incorrect. Please try again.\n");
	else if (error == 4)
	{
		ft_putstr("Error. It can be :\n-Empty file\n-Map length or height is ");
		ft_putstr("incorrect\n-No 0 in map\n-Incorrect characters (Available");
		ft_putstr(": 0-9 and ':')\n");
	}
	exit(0);
}

int			ft_close_cross(void *data)
{
	t_data *i;

	i = (t_data *)data;
	if (i)
	{
		free_textures(i);
		mlx_destroy_window(i->mlx, i->win);
		free(i);
		i = NULL;
	}
	ft_putstr("Program closed successfully.\n");
	exit(0);
}
