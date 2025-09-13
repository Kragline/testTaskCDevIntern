#ifndef CUSTOM_LS_H
# define CUSTOM_LS_H

# include <stdio.h>
# include <unistd.h>
# include <dirent.h>
# include <string.h>
# include <stdbool.h>
# include <sys/stat.h>
# include <sys/param.h>

# define WHITE "\033[0m"
# define BLUE "\033[1;34m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"

void	print_entity(const char *name, bool is_dir, int tabulation);
bool	is_valid_entity(const char *path);
bool	is_directory(const char *path);
void	print_working_dir();

#endif