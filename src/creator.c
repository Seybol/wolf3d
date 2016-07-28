/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 19:07:24 by scebula           #+#    #+#             */
/*   Updated: 2016/07/25 15:22:01 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				there_is_place(char **s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[j])
	{
		while (s[j][i])
		{
			if (s[j][i] == '0')
				return (1);
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

void			fill_borders(char **s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[j])
	{
		while (s[j][i])
		{
			if ((j == 0 && s[j][i] == '0') || (i == 0 && s[j][i] == '0'))
				s[j][i] = '1';
			if ((!s[j + 1] && s[j][i] == '0'))
				s[j][i] = '1';
			i++;
		}
		i--;
		if (s[j][i] == '0')
			s[j][i] = '1';
		i = 0;
		j++;
	}
}

int				check_param(char *s1, char *s2, char *s3, char *s4)
{
	int x;
	int y;
	int a;
	int b;

	if (ft_isdigits(s1) && ft_isdigits(s2) && ft_isdigits(s3)
			&& ft_isdigits(s4))
	{
		x = ft_atoi(s1);
		y = ft_atoi(s2);
		a = ft_atoi(s3);
		b = ft_atoi(s4);
		if ((x <= 100 && y <= 100) && (x > 2 && y > 2))
		{
			if ((a > 0 && a < (x - 1)) && (b > 0 && b < (y - 1)))
				return (1);
		}
	}
	return (0);
}

int				tab_height(char **s)
{
	int i;
	int first;

	i = 0;
	first = 0;
	while (s[i] != NULL)
		i++;
	return (i);
}

int				tab_length(char **s)
{
	int i;
	int j;
	int first;

	first = 0;
	i = -1;
	j = -1;
	if (s[++j])
	{
		while (s[j][++i])
			first++;
		i = -1;
	}
	while (s[j])
	{
		while (s[j][++i])
			;
		if (i != first)
			return (0);
		i = -1;
		j++;
	}
	return (first);
}
