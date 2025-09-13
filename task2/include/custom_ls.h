#ifndef CUSTOM_LS_H
# define CUSTOM_LS_H

# include <stdio.h>
# include <unistd.h>
# include <dirent.h>
# include <string.h>
# include <stdbool.h>
# include <sys/stat.h>
# include <sys/param.h>

void	print_entity(const char *name, int tabulation);
bool	is_valid_entity(const char *path);
bool	is_directory(const char *path);
void	print_working_dir();

#endif