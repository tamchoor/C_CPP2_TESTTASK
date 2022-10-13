NAME = finder

CC = gcc
# FLAGS = -Wall -Werror -Wextra -g
FLAGS = -Wall -Werror -Wextra -fsanitize=address

INCLUDES = -I$(HEADERS_DIRECTORY)

HEADER = find_file.h
HEADERS_DIRECTORY = .

SRCS_S = utils.c finder.c
SRCS_D = srcs/

DIR_SRC = $(OBJS_DIR)$(SRCS_D) 

SOURCES_S =  main.c \
			$(addprefix srcs/, $(SRCS_S)) 

OBJS = $(SOURCES_S:%.c=%.o)


GREEN = \033[0;32m
RED = \033[0;31m
CROSS = \033[9m
MARK = \033[7m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

ALL_OBJS_DIR = $(DIR_SRC)


$(NAME):  $(OBJS)
	@$(CC) $(FLAGS) $(INCLUDES)  $(LIBRARIES) $(OBJS) -o $(NAME)
	@echo "\n$(MARK) $(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(MARK) $(NAME): $(GREEN)$(NAME) was created$(RESET)"


%.o : %.c $(HEADER)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJS)
	@echo "$(NAME): $(RED) $(CROSS)object $(RED) files were deleted$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(CROSS) $(NAME) : $(RED)$(NAME) was deleted$(RESET)"

re: fclean all