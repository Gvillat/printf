#include "../includes/ft_memory.h"

LD *ft_create_dir(char *name)
{
	LD *new;

	if (!(new = (LD*)malloc(sizeof(LD))))
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->path = tool_checkdirname(name);
	new->name = fpf_strsub(name, 0, ft_strlen(name) + 1);
	new->file = NULL;
	return (new);
}

LF *ft_create_file(char *name)
{
	LF *new;

	if (!(new = (LF*)malloc(sizeof(LF))))
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->name = fpf_strsub(name, 0, ft_strlen(name) + 1);
	// new->name = name;
	new->info = NULL;
	return (new);
}

LD *ft_add_begin_dir(char *name, LD **curr)
{
	LD *tmp;

	if (!*curr)
		return (*curr = ft_create_dir(name));
	tmp = *curr;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_create_dir(name);
	tmp->next->prev = tmp;
	return((*curr)->next);
}

void ft_add_end_dir(char *name, LD **curr)
{
	LD *tmp;

	if (!*curr)
		(*curr = ft_create_dir(name));
	tmp = *curr;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_create_dir(name);
	tmp->next->path = ft_strjoin((*curr)->path, tmp->next->path);
	tmp->next->prev = tmp;
}

LF *ft_add_end_file(char *name, LF **curr)
{
	LF *tmp;

	if (!*curr)
		return (*curr = ft_create_file(name));
	tmp = *curr;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_create_file(name);
	tmp->next->prev = tmp;
	return((*curr)->next);
}
