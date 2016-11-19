#include "../includes/ft_memory.h"

static char ft_get_type(INFO *curr, STAT sb)
{
	if (S_ISFIFO(sb.st_mode))
		return (curr->type = 'p');
	else if (S_ISCHR(sb.st_mode))
		return (curr->type = 'c');
	else if (S_ISDIR(sb.st_mode))
		return (curr->type = 'd');
	else if (S_ISBLK(sb.st_mode))
		return (curr->type = 'b');
	else if (S_ISREG(sb.st_mode))
		return (curr->type = '-');		
	else if (S_ISLNK(sb.st_mode))
		return (curr->type = 'l');
	else if (S_ISSOCK(sb.st_mode))
		return (curr->type = 's');
	else
		return (curr->type);
}

static char *ft_get_permission(char *perm, STAT sb)
{
	perm[1] = (sb.st_mode & S_IRUSR) ? 'r' : '-';
	perm[2] = (sb.st_mode & S_IWUSR) ? 'w' : '-';
	perm[3] = (sb.st_mode & S_IXUSR) ? 'x' : '-';
	if (sb.st_mode & S_ISUID)
		perm[3] = (perm[3] == 'x') ? 's' : 'S';
	perm[4] = (sb.st_mode & S_IRGRP) ? 'r' : '-';
	perm[5] = (sb.st_mode & S_IWGRP) ? 'w' : '-';
	perm[6] = (sb.st_mode & S_IXGRP) ? 'x' : '-';
	if (sb.st_mode & S_ISGID)
		perm[6] = (perm[6] == 'x') ? 's' : 'S';
	perm[7] = (sb.st_mode & S_IROTH) ? 'r' : '-';
	perm[8] = (sb.st_mode & S_IWOTH) ? 'w' : '-';
	perm[9] = (sb.st_mode & S_IXOTH) ? 'x' : '-';
	if (sb.st_mode & S_ISVTX)
		perm[9] = (perm[9] == 'x') ? 't' : 'T';
	return(perm);
}

static void	ft_display_permission(mode_t st_mode)
{
	fpf_printf("%c", st_mode & S_IRUSR ? 'r' : '-');
	fpf_printf("%c", st_mode & S_IWUSR ? 'w' : '-');
	if (st_mode & S_ISUID)
		fpf_printf("%c", st_mode & S_IXUSR ? 's' : 'S');
	else
		fpf_printf("%c", st_mode & S_IXUSR ? 'x' : '-');
	fpf_printf("%c", st_mode & S_IRGRP ? 'r' : '-');
	fpf_printf("%c", st_mode & S_IWGRP ? 'w' : '-');
	if (st_mode & S_ISGID)
		fpf_printf("%c", st_mode & S_IXGRP ? 's' : 'S');
	else
		fpf_printf("%c", st_mode & S_IXGRP ? 'x' : '-');
	fpf_printf("%c", st_mode & S_IROTH ? 'r' : '-');
	fpf_printf("%c", st_mode & S_IWOTH ? 'w' : '-');
	if (st_mode & S_ISVTX)
		fpf_printf("%c", st_mode & S_IXOTH ? 't' : 'T');
	else
		fpf_printf("%c", st_mode & S_IXOTH ? 'x' : '-');
	fpf_printf(" ");
}

static void	ft_display_time(STAT sb)
{
    char *s;
    int i;

    s = ctime(&sb.st_mtime);
    i = 4;
    while (i < 16)
    {
      ft_putchar(s[i]);
      i++;
    }
    ft_putchar(' ');

}


static INFO *ft_ls_l(STAT sb)
{
	INFO *info;
	struct passwd *psswd;
	struct group *grp;

	if (!(info = (INFO*)malloc(sizeof(INFO))))
		return	(NULL);

	info->type = ft_get_type(info, sb);
	info->nb_link = sb.st_nlink;
	psswd = getpwuid(sb.st_uid);
	grp = getgrgid(sb.st_gid);
	info->uid = psswd->pw_name;
	info->major = ft_itoa((int)((char)((int32_t)(((u_int32_t)(sb.st_rdev) >> 24) & 0xff))));
	info->minor = ft_itoa((int)((char)sb.st_rdev));
	info->guid = grp->gr_name;
	info->size = sb.st_size;
	info->mtime = ctime(&sb.st_mtime);
	return (info);
}

LF *ft_display(LF *tmp, char *path)
{
	STAT sb;
	char *path2;
	int n;

	n = 0;
	if (!tmp)
		fpf_printf("(null)\n");
	while (tmp)
	{
		if (opt_l)
		{
			path2 = ft_strjoin(path, tmp->name);
			if (stat(path2, &sb) == -1)
			    {
			        perror("teub ");
			        exit(EXIT_SUCCESS);
			    }
			tmp->info = ft_ls_l(sb);
			fpf_printf("%c", tmp->info->type);
			ft_display_permission(sb.st_mode);
			fpf_printf(" %3d %s %s ", tmp->info->nb_link, tmp->info->uid, tmp->info->guid);
			if (S_ISBLK(sb.st_mode) || S_ISCHR(sb.st_mode))
				fpf_printf("%*s, %*s ", ft_strlen(tmp->info->major) +1, tmp->info->major, ft_strlen(tmp->info->minor) +1 , tmp->info->minor);
			else 
				fpf_printf("%6D ", tmp->info->size);
			ft_display_time(sb);
			ft_putstr(tmp->name);
			ft_putchar('\n');
		}
		else
			fpf_printf("%s\n", tmp->name);
		tmp = tmp->next;
	}
	fpf_printf("\n");
	fpf_printf("\n");
	return (tmp);
}