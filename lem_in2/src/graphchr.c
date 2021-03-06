/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphchr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 22:14:32 by bandre            #+#    #+#             */
/*   Updated: 2017/01/15 21:34:59 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_struct	*graphchr(t_struct **list_salles, char *name)
{
	int i;

	i = 0;
	while (list_salles[i])
	{
		if (ft_strcmp((list_salles[i])->name, name) == 0)
			return (list_salles[i]);
		i++;
	}
	return (NULL);
}
