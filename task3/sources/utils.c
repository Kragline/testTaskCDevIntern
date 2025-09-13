#include "tiny_shell.h"

void	empty_command(char *command)
{
	if (!command || !*command)
	{
		perror("empty command");
		exit (1);
	}
}

void	execution_error(char *message, char **s_cmnd)
{
	fprintf(stderr, "tiny shell: %s", message);
	if (s_cmnd)
	{
		fprintf(stderr, ": %s", s_cmnd[0]);
		free_array(s_cmnd);
	}
	fprintf(stderr, "\n");
	exit(1);
}

void	free_array(char **tab)
{
	int	i;

	if (!*tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	open_outfile(char *filename)
{
	if (access(filename, F_OK) != 0)
		return (open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777));
	if (access(filename, W_OK) != 0)
	{
		fprintf(stderr, "tiny shell: permission denied: %s\n", filename);
		return (-1);
	}
	return (open(filename, O_WRONLY | O_TRUNC));
}
