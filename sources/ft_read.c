#include "../includes/ft_memory.h"


LF *ft_add_file_a(char *name, LF *file)
{
	if (opt_a)
		ft_add_end_file(name, &file);
	else if (name[0] != '.')
		ft_add_end_file(name, &file);		
	return(file);
}

LD *ft_check_files(LD *curr, char *path)
{
	LF *file;
	
	file = curr->file;
	while (file)
	{
		path = ft_strjoin(curr->path, file->name);
		if ((tool_stats(path) == 1) && (ft_strcmp(file->name, ".")) && (ft_strncmp(file->name, "..", 2)))
		{
		 	ft_add_end_dir(file->name, &curr);
		}
		file = file->next;
	}
	return (curr);
}

LD *ft_read(LD *curr)
{
	DIR *pdir;
	struct dirent *pdirent;

	if ((pdir = opendir(curr->path)))
	{

		while ((pdirent = readdir(pdir)))
		{

			if (opt_a == 0 && pdirent->d_name[0] == '.')
				continue;
			ft_add_end_file(pdirent->d_name, &curr->file);
		}
		ft_sort(&curr->file);
		if (opt_R)
			ft_check_files(curr, curr->path);
	}
	else
	{
  		fpf_printf("ls: %s: Permission denied\n",curr->path );
		// ft_error_perm(curr->path);
		return(curr);
	}
	closedir(pdir);
	return(curr);
}