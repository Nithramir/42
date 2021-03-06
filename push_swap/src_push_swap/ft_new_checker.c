/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_chercker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 00:27:17 by bandre            #+#    #+#             */
/*   Updated: 2016/12/12 20:13:52 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_checker	*ft_new_checker(int nb, t_checker *previous)
{
	t_checker *new;

	if (!(new = (t_checker*)malloc(sizeof(t_checker))))
		return (NULL);
	new->nb = nb;
	new->next = NULL;
	new->previous = previous;
	return (new);
}
