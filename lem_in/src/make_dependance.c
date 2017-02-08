/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_dependance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 20:53:39 by bandre            #+#    #+#             */
/*   Updated: 2017/02/01 22:07:22 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	dep_find(t_path *path, t_path *path2)
{
	int		i;
	t_path	**new;
	t_path	**stock;

	stock = path->dependance;
	i = 1;
	while (path->dependance[i])
		i++;
	if (!(new = (t_path**)malloc((i + 2) * sizeof(t_path*))))
		return (0);
	i = 0;
	while (path->dependance[i])
	{
		new[i] = path->dependance[i];
		i++;
	}
	new[i] = path2;
	new[i + 1] = NULL;
	path->dependance = new;
	free(stock);
	return (1);
}

static int	add_dependance(t_path **list_path, int i, int u)
{
	int k;
	int m;

	k = 1;
	while (list_path[i]->path[k])
	{
		m = 1;
		while (list_path[u]->path[m])
		{
			if (!(list_path[u]->path[m + 1]))
				break ;
			if (list_path[i]->path[k] == list_path[u]->path[m])
				return (dep_find(list_path[i], list_path[u]));
			m++;
		}
		k++;
	}
	return (1);
}

int			make_dependance(t_path **list_path)
{
	int i;
	int u;

	i = 0;
	while (list_path[i])
	{
		u = 0;
		while (list_path[u])
		{
			if (!(list_path[u]))
				return (1);
			if ((add_dependance(list_path, i, u) == 0))
				return (0);
			u++;
		}
		i++;
	}
	return (1);
}
