#include "ft_ls.h"

static int add_param(s_param *param, char *chaine)
{
	int i;

	i = 1;
	while (chaine[i])
	{
		if (ft_strchr("alrRt", (int)chaine[i]))
		{
			if (chaine[i] == 'r' )
				param->r = 1;
			if (chaine[i] ==  'R')
				param->rmaj = 1;
			if (chaine[i] ==  'a')
				param->a = 1;
			if (chaine[i] ==  'l')
				param->l = 1;
			if (chaine[i] ==  't')
				param->t = 1;
		}
		else
			option_invalide((chaine + 1), param);
		i++;
	}
	return (1);
}

s_param		*recup_param(char **list_param)
{
	int i;
	s_param *param;

	i = 1;
	param = new_s_param();
	while (list_param[i])
	{
		if (list_param[i][0] == '-')
			add_param(param, list_param[i]);
		else
		{
			param->list_fichier = (char**)ft_ptradd((void*)param->
					list_fichier, list_param[i]);
		}
		i++;
	}
	return (param);
}
