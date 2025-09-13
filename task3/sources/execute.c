#include "tiny_shell.h"

void	execute_script(char **s_cmnd, char **env)
{
	if (access(s_cmnd[0], F_OK) == -1)
		execution_error("no such file or directory", s_cmnd);
	if (access(s_cmnd[0], X_OK) == -1)
		execution_error("permission denied", s_cmnd);
	if (execve(s_cmnd[0], s_cmnd, env) == -1)
	{
		free_array(s_cmnd);
		exit(1);
	}
}

void	execute_command(char *arg, char **env)
{
	char	**s_cmnd;
	char	*path_to_cmnd;

	empty_command(arg);
	s_cmnd = split_string(arg, ' ');
	if (!s_cmnd || !*s_cmnd)
	{
		free_array(s_cmnd);
		exit(1);
	}
	if (strchr(s_cmnd[0], '/'))
		execute_script(s_cmnd, env);
	else
	{
		path_to_cmnd = get_full_path(s_cmnd[0], env);
		if (!path_to_cmnd)
			execution_error("command not found", s_cmnd);
		execve(path_to_cmnd, s_cmnd, env);
		free(path_to_cmnd);
		execution_error("execve failed", s_cmnd);
	}
}

void	execve_child(char **argv, int *pipefd, char **env)
{
	dup2(pipefd[1], 1);
	close(pipefd[0]);
	close(pipefd[1]);
	execute_command(argv[2], env);
}

void	execve_child2(char **argv, int *pipefd, char **env)
{
	int	outfile;

	outfile = open_outfile(argv[4]);
	if (outfile == -1)
		exit(1);
	dup2(outfile, 1);
	dup2(pipefd[0], 0);
	close(outfile);
	close(pipefd[0]);
	close(pipefd[1]);
	execute_command(argv[3], env);
}
