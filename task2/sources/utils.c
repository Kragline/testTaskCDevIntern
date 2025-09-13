#include "custom_ls.h"

void	print_entity(const char *name, bool is_dir, int tabulation)
{
	for (int i = 0; i < tabulation; ++i)
		printf("\t");
	if (is_dir)
		printf(BLUE "%s/\n" WHITE, name);
	else if (!access(name, X_OK))
		printf(GREEN "%s\n" WHITE, name);
	else
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
		printf(YELLOW "%s\n" WHITE, buffer);
	else
		perror("getcwd");
}
