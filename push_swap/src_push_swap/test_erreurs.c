/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_erreurs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 21:34:59 by bandre            #+#    #+#             */
/*   Updated: 2017/01/13 17:35:44 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valide(char *value)
{
	int i;

	i = 0;
	if (value[i] == '+' || value[i] == '-')
	{
		if (ft_isdigit(value[i + 1]))
			i++;
		else
			return (-1);
	}
	while (value[i])
	{
		if (ft_isdigit(value[i]))
			i++;
		else
			return (-1);
	}
	return (1);
}

int			*verif_entier(char *argv, int *ptr)
{
	ssize_t value;

	if (ft_strlen(argv) > 13)
		return (NULL);
	if (is_valide(argv) == -1)
		return (NULL);
	value = ft_atoi(argv);
	if (value >= (ssize_t)INT_MIN && value <= (ssize_t)INT_MAX)
	{
		*ptr = (int)value;
		return (ptr);
	}
	return (NULL);
}
