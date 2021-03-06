/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afficher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 20:43:48 by bandre            #+#    #+#             */
/*   Updated: 2017/02/15 18:12:05 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		afficher(t_struct **list_salles)
{
	int i;

	i = 0;
	ft_putendl("###############");
	while (list_salles[i])
	{
		ft_putendl((list_salles[i])->name);
		i++;
	}
	ft_putendl("###############");
	return (1);
}

int		afficher_road(t_path **path)
{
	int i;

	i = 0;
	ft_putendl("##############################");
	while (path[i])
	{
		afficher(path[i]->path);
		i++;
	}
	ft_putendl("###############################");
	ft_putendl("");
	return (1);
}

void	afficher_error(void)
{
	ft_putendl("ERROR");
	exit(0);
}

void	afficher_error_path(t_path **path, t_struct **graph, char *fichier)
{
	ft_putendl("ERROR");
	ft_free_list_t_struct(graph);
	ft_free_list_t_path(path);
	free(fichier);
	exit(0);
}
