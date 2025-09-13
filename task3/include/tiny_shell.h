#ifndef TYNY_SHELL_H
# define TYNY_SHELL_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>
# include <sys/wait.h>
# include <sys/param.h>

//				utils
void	empty_command(char *command);
void	execution_error(char *message, char **s_cmnd);
void	free_array(char **array);
int		open_outfile(char *filename);

//				split
char	**split_string(char const *s, char c);

//				get path
char	*path_from_env(char **env);
char	*get_full_path(char *cmnd, char **env);

//				execute
void	execute_script(char **s_cmnd, char **env);
void	execute_command(char *arg, char **env);
void	execve_child(char **argv, int *pipefd, char **env);
void	execve_child2(char **argv, int *pipefd, char **env);

#endif