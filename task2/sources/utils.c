#include "custom_ls.h"

void	print_entity(const char *name, int tabulation)
{
	for (int i = 0; i < tabulation; ++i)
		printf("\t");
	printf("%s\n", name);
}

bool	is_valid_entity(const char *path)
{
	struct stat	statbuf;

	return (!stat(path, &statbuf));
}

bool	is_directory(const char *path)
{
	struct stat	statbuf;

	if (stat(path, &statbuf))
		return (false);
	return (S_ISDIR(statbuf.st_mode));
}

void	print_working_dir()
{
	char	buffer[PATH_MAX];

	if (getcwd(buffer, sizeof(buffer)))
		printf("%s\n", buffer);
	else
		perror("getcwd");
}
