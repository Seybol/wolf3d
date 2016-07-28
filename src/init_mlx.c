/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 19:13:18 by scebula           #+#    #+#             */
/*   Updated: 2016/07/25 18:06:31 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_img		*ft_data_img(t_data *i, int length, int heigth)
{
	t_img *a;

	a = (t_img*)malloc(sizeof(t_img));
	a->img = mlx_new_image(i->mlx, length, heigth);
	a->data = mlx_get_data_addr(a->img, &(a->bpp), &(a->sl),
			&(a->endian));
	return (a);
}

static void	init_textures(t_data *data)
{
	int i;

	i = -1;
	while (++i < 9)
		data->textures[i] = ft_init_img(data, ft_strcat_new("textures/",
					ft_strcat_new(ft_itoa(i), ".XPM")), "wall");
	data->textures[9] = ft_init_img(data, "textures/0.XPM", "pikachu");
	data->textures[10] = ft_init_img(data, "textures/9.XPM", "pikachu");
	data->textures[11] = ft_init_img(data, "textures/0.XPM", "pikachu");
	data->weapon = ft_init_img(data, "xpm/weapon", "weapon");
	data->pointer = ft_init_img(data, "xpm/pointer", "pointer");
	data->hud = ft_init_img(data, "xpm/hud1", "hud1");
	data->hud2 = ft_init_img(data, "xpm/hud2", "hud2");
	data->gameover = ft_init_img(data, "xpm/gameover", "gameover");
	black_transparency(data->hud);
	black_transparency(data->hud2);
	data->gif1 = (char **)malloc(sizeof(char *) * 33);
	data->commands = ft_init_img(data, "xpm/commands", "commands");
	i = -1;
	while (++i < 32)
		data->gif1[i] = ft_strcat_new(ft_strcat_new(
					"40a8db2f22d24867e13a9a188f63ccf2-", ft_itoa(i)), ".xpm");
	data->gif1[i] = NULL;
}

t_modifiers	*init_modifiers(void)
{
	t_modifiers *m;

	m = (t_modifiers *)malloc(sizeof(t_modifiers));
	m->shift = 0;
	return (m);
}

t_data		*ft_data_window(char **map)
{
	t_data	*data;
	int		i;

	i = 0;
	data = (t_data *)malloc(sizeof(t_data));
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "WOLF3D");
	data->eye = init_eye();
	data->e = init_event();
	data->map = map;
	data->sizex = tab_length(map);
	data->sizey = tab_height(map);
	init_textures(data);
	gettimeofday(&data->actual_time, NULL);
	gettimeofday(&data->actual_time2, NULL);
	data->m = init_modifiers();
	data->run = 0;
	data->text_gun = -1;
	data->fire = 0;
	data->mouse = 0;
	data->mouseon = 0;
	data->keys = 0;
	fill_borders(data->map);
	return (data);
}
