#include "tiny_shell.h"

char	*path_from_env(char **env)
{
	int		i;
	int		j;

	i = 0;
	while (env[i])
	{
		if (strncmp("PATH", env[i], 4) == 0)
		{
			j = 0;
			while (env[i][j] && env[i][j] != '=')
				j++;
			return (env[i] + j + 1);
		}
		i++;
	}
	return (NULL);
}

char	*get_full_path(char *cmnd, char **env)
{
	int		i;
	char	**s_paths;
	char	full_path[PATH_MAX];

	i = 0;
	s_paths = split_string(path_from_env(env), ':');
	while (s_paths[i])
	{
		sprintf(full_path, "%s/%s", s_paths[i], cmnd);
		if (access(full_path, F_OK | X_OK) == 0)
			return (free_array(s_paths), strdup(full_path));
		full_path[0] = '\0';
		i++;
	}
	free_array(s_paths);
	return (NULL);
}
