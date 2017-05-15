/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 18:44:20 by bandre            #+#    #+#             */
/*   Updated: 2017/05/15 17:06:08 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int main(int argc, char **argv)
{
	t_option	option;
	char		**files;
	int			i;
	char stock[4097];
	t_file		*new;

	i = get_option(argc, argv, &option);
//	printf_option(option);
	if (i < argc)
	{
		while (i < argc)
		{
			ft_strcpy(stock, argv[i]);
			if (!(new = create_file(stock, option, 0, argv[i])))
				i = i + 1 - 1;
			else if (!(S_ISDIR(new->info.st_mode)))
			{
				show_dir(new, stock, 1);
			}
			else
				path_mov(stock, option, ft_strlen(stock));
			i++;
		}
	}
	else
	{
		ft_strcpy(stock, ".");
		path_mov(stock, option, ft_strlen(stock));
	}

	return (0);
}
