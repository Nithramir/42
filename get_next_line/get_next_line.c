/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 15:36:36 by bandre            #+#    #+#             */
/*   Updated: 2016/11/22 16:31:08 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

t_list	*add_read(int fd, int *ret)
{
	char buff[BUFF_SIZE + 1];
	t_list *firstelem;
	t_list *elemnext;

	firstelem = NULL;
	*ret = read(fd, buff, BUFF_SIZE);
	if (ret <= 0)
		return (NULL);
	buff[*ret] = '\0';
	firstelem = ft_lstnew(buff, BUFF_SIZE);
	elemnext = firstelem;
	firstelem->is_n = 0;
	if (ft_strchr(buff, '\n') == NULL)
	{
		*ret = read(fd, buff, BUFF_SIZE);
		if (ret <= 0)
			return (0);
		while (ft_strchr(buff, '\n') == NULL)
		{
			elemnext->next = ft_lstnew(buff, BUFF_SIZE);
			elemnext = elemnext->next;
			elemnext->is_n = 0;
			*ret = read(fd, buff, BUFF_SIZE);
			if (ret <= 0)
				return (NULL);
		}
		elemnext->next = ft_lstnew(buff, BUFF_SIZE);
		elemnext = elemnext->next;
	}
	return (firstelem);
}


int		need_new_read(int fd, t_list **firstelem)
{
	t_list *elem;
	int ret;
	char *chaine;

	elem = *firstelem;
	if (elem)
	{
		if (ft_strchr(&elem->content[elem->is_n], '\n') != NULL)
			return (1);
	}
	if (elem == NULL)
		elem = add_read(fd, &ret);
	else
		elem->next = add_read(fd, &ret);
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	static t_list *firstelem = NULL;
	static int fd2;
	int ret;

	ret = need_new_read(fd, &firstelem);
	ft_putendl("test");/*
	if (ret == 0)
	{
		affichage;
		liberation mem;
		firstelem = NULL;
		return (0);
	}*/
	if (ret == -1)
		return (-1);
	ft_putendl(firstelem->content);
	ft_putendl("test2");
	firstelem = firstelem->next;
	ft_putendl(firstelem->content);


	
	return (1);
	
}

int		main()
{
	int fd;
	char **ptr;

	fd = open("test", O_RDONLY);
	get_next_line(fd, ptr);
	ft_putendl(*ptr);
	return (0);
}