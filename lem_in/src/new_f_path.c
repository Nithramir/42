/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_f_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 20:51:05 by bandre            #+#    #+#             */
/*   Updated: 2017/01/15 20:51:39 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

f_path	*new_f_path(g_struct **add)
{
	f_path	*new;

	if (!(new = (f_path*)malloc(sizeof(f_path))))
		return (NULL);
	if (!(new->dependance = (f_path**)malloc(sizeof(f_path*))))
		return (NULL);
	new->dependance[0] = NULL;
	new->path = add;
	new->nb_fourmis = 0;
	return (new);
}
