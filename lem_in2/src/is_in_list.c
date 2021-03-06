/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:46:50 by bandre            #+#    #+#             */
/*   Updated: 2017/01/05 13:49:19 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_in_list(t_struct **list, t_struct *add)
{
	int i;

	i = 0;
	while (list[i])
	{
		if (!(ft_strcmp(list[i]->name, add->name)))
			return (1);
		i++;
	}
	return (0);
}
