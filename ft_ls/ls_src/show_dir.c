/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 20:50:13 by bandre            #+#    #+#             */
/*   Updated: 2017/05/15 16:58:45 by bandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "stdio.h"

static void print_droit(struct stat info)
{
	ft_printf("%c", S_IRUSR == (info.st_mode & S_IFMT) ? '-' : 'r');
	ft_printf("%c", S_IWUSR == (info.st_mode & S_IFMT) ? '-' : 'w');
	ft_printf("%c", S_IXUSR == (info.st_mode & S_IFMT) ? '-' : 'x');
	ft_printf("%c", S_IRGRP == (info.st_mode & S_IFMT) ? '-' : 'r');
	ft_printf("%c", S_IWGRP == (info.st_mode & S_IFMT) ? '-' : 'w');
	ft_printf("%c", S_IXGRP == (info.st_mode & S_IFMT) ? '-' : 'x');
	ft_printf("%c", S_IROTH == (info.st_mode & S_IFMT) ? '-' : 'r');
	ft_printf("%c", S_IWOTH == (info.st_mode & S_IFMT) ? '-' : 'w');
	ft_printf("%c ", S_IXOTH == (info.st_mode & S_IFMT) ? '-' : 'x');
}

static void	print_type(struct stat info)
{

	if (S_ISDIR(info.st_mode))
		ft_printf("d");
	else if (S_ISLNK(info.st_mode))
		ft_printf("l");
	else if (S_ISREG(info.st_mode))
		ft_printf("-");
	else if (S_ISCHR(info.st_mode))
		ft_printf("c");
	else if (S_ISBLK(info.st_mode))
		ft_printf("b");
	else
		ft_putendl("erreurcnnaitpas");
}

static void print_hour(struct stat info)
{
	char **split;

	split = ft_strsplit(ctime(&(info.st_mtime)), ' ');
	ft_printf("%s. %s %s ", split[1], split[2], split[3]);

}

static void print_l(struct stat info, char *file, char stock[4097], int ptr)
{
	struct passwd *uid;
	struct group *gid;
	char buff[256];
	int nb_carac;

	print_type(info);
	print_droit(info);
	ft_printf("%d ", info.st_nlink);
	uid = getpwuid(info.st_uid);
	ft_printf("%s ", uid->pw_name);
	gid = getgrgid(info.st_gid);
	ft_printf("%s ", gid->gr_name);
	ft_printf("%d ", info.st_size);
	print_hour(info);
	if (S_ISLNK(info.st_mode))
	{
		file[ft_strlen(file) - 1] = '\0';
		ft_strcpy(&stock[ptr], file);
		if ((nb_carac = readlink(stock, buff, 255)) == -1)
		{
			ft_putendl("erreur print_l");
			perror("");
		}
		buff[nb_carac] = '\0';
		ft_printf("%s -> %s\n", file, buff);
	}
	else
		ft_putendl(file);
}

void	show_dir(t_file *first, char stock[4097], int ptr, t_option option)
{
	int yolo;

	ptr--;
	while (first)
	{
		if (option.l)
			print_l(first->info, first->file, stock, ptr);
		else
			ft_putendl(first->file);
		yolo = 1;
		first = first->next;
	}
}
