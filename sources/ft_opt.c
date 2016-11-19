#include "../includes/ft_memory.h"

LS *ft_add_args(LF **tmp, LS *ls)
{
	LF *chibre;

	chibre = *tmp;
	while (chibre)
	{
		if (tool_stats(chibre->name) == 0)
			ft_add_end_file(chibre->name, &ls->file);
		else
			ft_add_begin_dir(chibre->name, &ls->dir);
		chibre = chibre->next;
	}
	//free tmp !!!!!!!!!!
	return(ls);
}

LS *ft_check_reste(LS *ls)
{
	LF *tmp = NULL;

	while (ls->reste < ls->ac)
	{
		ft_add_end_file(ls->av[ls->reste], &tmp);
		ls->reste++;		
	}
	ft_sort(&tmp);
	ft_add_args(&tmp, ls);
	return(ls);
}

void ft_error_opt(char c)
{
  fpf_printf("ls: illegal option -- %c\n",c );
  fpf_printf("usage: ls [-artlR] [file ...]\n" );
  exit(0);
}

int 	ft_check_opt(char c)
{
	if (c == 'a')
		return (opt_a = 1);
	else if (c == 'l')
		return (opt_l = 1);
	else if (c == 't')
		return (opt_t = 1);
	else if (c == 'r')
		return (opt_r = 1);
	else if (c == 'R')
		return (opt_R = 1);
	else
		ft_error_opt(c);
	return (0);
}

int	ft_fill_opt(char **av, int ac)
{
	int i;
	int c;

	i = 1;
	c = 1;
	if (av[i])
	{
		while(i < ac && av[i][0] == '-' && av[i][1])
		{
			while(av[i][c] && ft_check_opt(av[i][c]))
				c++;
			c = 1;
			i++;
		}
	}
	c = i;
	return(c);
}