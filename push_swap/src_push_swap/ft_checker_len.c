/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 18:04:32 by bandre            #+#    #+#             */
/*   Updated: 2016/12/11 18:05:58 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_checker_len(t_checker *src)
{
	int i;

	i = 0;
	while (src)
	{
		i++;
		src = src->next;
	}
	return (i);
}
