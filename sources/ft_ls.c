#include "../includes/ft_memory.h"

LS *ft_init_ls(int ac, char **av, int reste)
{
	LS *new;

	if (!(new = (LS*)malloc(sizeof(LS))))
		return(NULL);
	new->ac = ac;
	new->av = av;
	new->reste = reste;
	new->dir = NULL;
	new->file = NULL;
	return (new); 
}

LS *ft_check_args(int ac, char **av)
{
	LS *ls;
	char **args;
	int reste;
	int i = 0;

	reste = ft_fill_opt(av, ac);
	ls = ft_init_ls(ac, av, reste);
	if (reste < ac)
		ft_check_reste(ls);
	else
		ft_add_begin_dir(".", &ls->dir);
	return(ls);
}

void ft_start(LS *ls)
{
	LD *tmp;

	tmp = ls->dir;
	if (ls->file)
		ft_display(ls->file, tool_checkdirname(ls->file->name));
	while (tmp)
	{
		ft_read(tmp);
		tmp = tmp->next;
	}
}

int main(int ac, char **av)
{
	LS *ls;
	int i = 0;

	ls = ft_check_args(ac, av);
	ft_start(ls);
	if (opt_r == 0)
		ft_sort_args(&ls->dir);
	while (ls->dir)
	{
		fpf_printf("%s:\n", ls->dir->path);
		ft_display(ls->dir->file, ls->dir->path);
		ls->dir = ls->dir->next;
	}
	return (0);
}