#include "../includes/ft_memory.h"

static int	sort_alpha(char *one, char *two)
{
	return (ft_strcmp(one, two) > 0 ? 1 : 0);
}

static int	sort_ralpha(char *one, char *two)
{
	return (ft_strcmp(one, two) < 0 ? 1 : 0);
}

// int	sort_time(char *one, char *two, char *path)
// {
// 	STAT st1;
// 	STAT st2;
// 	char *pathone;
// 	char *pathtwo;

// 	pathone = ft_strjoin(path, one);
// 	pathtwo = ft_strjoin(path, two);

// fpf_printf("ONE %s                 two %s \n", pathone, pathtwo);

// 	lstat(pathone, &st1);
// 	lstat(pathtwo, &st2);
// 	return (st1.st_mtimespec.tv_sec <= st2.st_mtimespec.tv_sec);
// }

// int	sort_rtime(char *one, char *two, char *path)
// {
// 	STAT st1;
// 	STAT st2;
// 	char *pathone;
// 	char *pathtwo;

// 	pathone = ft_strjoin(path, one);
// 	pathtwo = ft_strjoin(path, two);

// fpf_printf("ONE %s                 two %s \n", pathone, pathtwo);
// 	lstat(pathone, &st1);
// 	lstat(pathtwo, &st2);
// 	return (st1.st_mtimespec.tv_sec > st2.st_mtimespec.tv_sec);
// }

static int ft_choose_sort(char *s1, char *s2)
{
	// if (opt_t && opt_r)
	// {
	// 	// sort_ralpha
	// 	return (!sort_time(s1,s2, path));
	// }
	// else if (opt_t)
	// 	return (sort_time(s1,s2, path));
	if (opt_r)
		return (sort_ralpha(s1,s2));
	else
		return (sort_alpha(s1,s2));
}

static void	swap_file(LF **one, LF **two)
{
	LF *temp;

	temp = *one;
	*one = *two;
	*two = temp;
}

static void	swap(char **one, char **two)
{
	char *temp;

	temp = *one;
	*one = *two;
	*two = temp;
}

int ft_sort_args(LD **curr)
{
	static LD *head = NULL;
	LD *tmp;

 	if (!head)
		head = *curr;
	if (!(tmp = *curr) || !(*curr)->next)
	{
		head = NULL;
		return (1);
	}
	while (1)
	{
		if (sort_alpha(tmp->path, tmp->next->path))
		{
			swap(&tmp->name, &tmp->next->name);
			swap(&tmp->path, &tmp->next->path);
			swap_file(&tmp->file, &tmp->next->file);
			if (tmp != head)
				return(0);
		}
		if (ft_sort_args(&tmp->next))
			return(1);
	}
}

int ft_sort(LF **curr)
{
	static LF *head = NULL;
	LF *tmp;

 	if (!head)
		head = *curr;
	if (!(tmp = *curr) || !(*curr)->next)
	{
		head = NULL;
		return (1);
	}
	while (1)
	{
		if (ft_choose_sort(tmp->name, tmp->next->name))
		{
			swap(&tmp->name, &tmp->next->name);
			if (tmp != head)
				return(0);
		}
		if (ft_sort(&tmp->next))
			return(1);
	}
}