/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 19:13:50 by scebula           #+#    #+#             */
/*   Updated: 2016/07/25 18:06:09 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	loop(t_data *data)
{
	mlx_loop_hook(data->mlx, &noevent, data);
	mlx_do_key_autorepeaton(data->mlx);
	mlx_hook(data->win, 2, 1, ft_key_press, data);
	mlx_hook(data->win, 3, 1, ft_key_up, data);
	mlx_hook(data->win, 17, (1L << 17), ft_close_cross, data);
	mlx_hook(data->win, 6, 1, ft_mouse_julia, data);
	mlx_loop(data->mlx);
}

void	read_from_file(char *file, int x, int y)
{
	t_data	*data;
	int		fd;
	char	**map;

	data = NULL;
	map = NULL;
	if (ft_strstr(file, "random") && ft_strequ(ft_strstr(file, "random"),
				"random"))
		ft_close(data, 1);
	fd = open(file, O_RDONLY);
	if (fd >= 3)
		map = ft_parse(fd);
	else
		exit(0);
	if (map == NULL || !tab_length(map) || !there_is_place(map) ||
			!check_tab(map))
		ft_close(data, 4);
	data = ft_data_window(map);
	if ((((data->sizex - 1) < x || x < 1) || ((data->sizey - 1) < y || y < 1)))
		ft_close(data, 2);
	if (data->map[y][x] != '0')
		ft_close(data, 3);
	data->eye->pos->x = x + 0.5;
	data->eye->pos->y = y + 0.5;
	loop(data);
}

void	create_arena(char *s1, char *s2, char *s3, char *s4)
{
	t_data	*data;
	char	**map;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if ((check_param(s1, s2, s3, s4)))
	{
		map = (char **)malloc(sizeof(char *) * (ft_atoi(s2) + 1));
		while (++i < ft_atoi(s2))
		{
			map[i] = (char *)malloc(sizeof(char) * (ft_atoi(s1) + 1));
			while (++j < ft_atoi(s1))
				map[i][j] = '0';
			map[i][j] = '\0';
			j = -1;
		}
		map[i] = NULL;
		data = ft_data_window(map);
		data->eye->pos->x = ft_atoi(s3) + 0.5;
		data->eye->pos->y = ft_atoi(s4) + 0.5;
		loop(data);
	}
	ft_putstr("Error. Wrong arguments.\n");
}

int		main(int argc, char **argv)
{
	if (argc == 4 && ft_isdigits(argv[2]) && ft_isdigits(argv[3]))
		read_from_file(argv[1], ft_atoi(argv[2]), ft_atoi(argv[3]));
	else if (argc == 5)
		create_arena(argv[1], argv[2], argv[3], argv[4]);
	else
		ft_putstr("Wrong number of arguments. Please try again\n");
	return (0);
}
