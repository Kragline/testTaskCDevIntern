#include "tiny_shell.h"

static int	first_part(char **argv, char **env)
{
	int		status;
	pid_t	proc_id;

	proc_id = fork();
	if (proc_id == -1)
		execution_error("fork failed", NULL);
	if (proc_id == 0)
		execute_command(argv[1], env);
	waitpid(proc_id, &status, 0);
	return (WEXITSTATUS(status));
}

static int	second_part(char **argv, char **env)
{
	int		status;
	int		pipefd[2];
	pid_t	proc_id2;
	pid_t	proc_id3;

	if (pipe(pipefd) == -1)
		execution_error("pipe failed", NULL);
	proc_id2 = fork();
	if (proc_id2 == -1)
		execution_error("fork failed", NULL);
	if (proc_id2 == 0)
		execve_child(argv, pipefd, env);
	proc_id3 = fork();
	if (proc_id3 == -1)
		execution_error("fork failed", NULL);
	if (proc_id3 == 0)
		execve_child2(argv, pipefd, env);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(proc_id2, NULL, 0);
	waitpid(proc_id3, &status, 0);
	return (WEXITSTATUS(status));
}

int	main(int argc, char **argv, char **env)
{
	int		exit_code;

	if (argc != 5)
		execution_error("wrong number of arguments", NULL);
	if (!path_from_env(env))
		execution_error("path variable was not found", NULL);
	exit_code = first_part(argv, env);
	if (exit_code)
		return (exit_code);
	exit_code = second_part(argv, env);
	return (exit_code);
}
