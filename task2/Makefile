NAME = custom_ls
CC = cc

CCFLAGS = -Wall -Wextra -Werror -g3

HEADER_DIR = include/
SOURCES_DIR = sources/
OBJECTS_DIR = objects/

FILENAMES = main utils

SOURCES = $(addsuffix .c, $(addprefix $(SOURCES_DIR), $(FILENAMES)))
OBJECTS = $(addsuffix .o, $(addprefix $(OBJECTS_DIR), $(FILENAMES)))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS) Makefile
	$(CC) $(CCFLAGS) -I$(HEADER_DIR) $(OBJECTS) -o $(NAME)

$(OBJECTS_DIR)%.o: $(SOURCES_DIR)%.c
	mkdir -p $(dir $@)
	$(CC) -c $(CCFLAGS) -I$(HEADER_DIR) $< -o $@

clean:
	rm -rf $(OBJECTS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
