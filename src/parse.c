/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 19:26:15 by scebula           #+#    #+#             */
/*   Updated: 2016/07/24 22:31:32 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		ft_count(char *s, char c)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (s[i] == c)
	{
		i++;
	}
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			n++;
		i++;
	}
	if (s[i - 1] != c && !s[i])
		n++;
	return (n);
}

char			*ft_strsplitc(char const *s, char c)
{
	char	*ss;
	int		i;
	int		index;

	i = 0;
	index = 0;
	ss = (char *)malloc(sizeof(char) * (ft_count((char *)s, c) + 1));
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		ss[index++] = s[i];
		i++;
	}
	ss[index] = '\0';
	return (ss);
}

static char		**ft_from_list_to_tab(t_list **list)
{
	t_list	*l;
	int		i;
	int		j;
	char	**split;

	l = *list;
	i = ft_listlen(l);
	j = 0;
	split = (char **)malloc(sizeof(char *) * (i + 1));
	while (l)
	{
		split[j++] = ft_strsplitc(l->content, ' ');
		l = l->next;
	}
	split[j] = NULL;
	return (split);
}

char			**ft_parse(int fd)
{
	char		*s;
	t_list		*list;
	int			i;
	char		**split;

	list = NULL;
	while ((i = get_next_line(fd, &s)))
	{
		if (i < 0)
			return (NULL);
		ft_lst_pushback(&list, s, ft_strlen(s) + 1);
		free(s);
		s = NULL;
	}
	if ((split = ft_from_list_to_tab(&list)) == NULL)
	{
		ft_list_clear(&list);
		return (NULL);
	}
	if (list == NULL)
		return (NULL);
	ft_list_clear(&list);
	return (split);
}
