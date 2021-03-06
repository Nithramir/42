/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 15:47:36 by bandre            #+#    #+#             */
/*   Updated: 2016/11/26 00:23:18 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 5
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct			s_listchain
{
	int					fd;
	t_list				*firstelem;
	int					n;
}						t_listchain;

int						get_next_line(const int fd, char **line);

#endif
