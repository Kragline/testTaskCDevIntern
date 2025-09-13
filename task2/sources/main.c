#include "custom_ls.h"

static bool	print_content(const char *dir_name, int tabulation)
{
	DIR				*dir;
	struct dirent	*entity;
	char			full_path[PATH_MAX];
	bool			is_dir;

	dir = opendir(dir_name);
	if (!dir)
		return (perror("opendir"), false);
	while ((entity = readdir(dir)) != NULL)
	{
		if (!strcmp(".", entity->d_name) || !strcmp("..", entity->d_name))
			continue ;
		sprintf(full_path, "%s/%s", dir_name, entity->d_name);
		if (is_valid_entity(full_path))
		{
			is_dir = is_directory(full_path);
			print_entity(entity->d_name, is_dir, tabulation);
			if (is_dir)
				print_content(full_path, tabulation + 1);
		}
	}
	closedir(dir);
	return (true);
}

int	main()
{
	print_working_dir();
	if (!print_content(".", 1))
		return (1);
	return (0);
}
