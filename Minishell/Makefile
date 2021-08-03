MINISHELL		=	minishell

SRCS			=	srcs/lst/ft_lst_add.c\
					srcs/lst/ft_lst_new.c\
					srcs/parse/inputs.c\
					srcs/utils/ft_strlen.c\
					srcs/utils/get_next_line.c\
					srcs/utils/get_next_line_utils.c\
					srcs/utils/libft.c\
					srcs/utils/msg_error.c\
					srcs/minishell.c\

SANITIZE		=	-fsanitize=address

#########################################################

CFLAGS			= -Werror -Wextra -Wall -g3

GCC 			= gcc

RED 			= \033[0;31m
PURPLE			= \033[0;35m
GREEN			= \033[1;32m
YELLOW			= \033[1;33m
GRIS			= \033[1;30m
CYAN			= \033[0;36m
RESET			= \033[0m

$(MINISHELL):
	$(GCC) $(CFLAGS) $(SRCS) -o $(MINISHELL)

all:	$(MINISHELL)

fclean:	clean

clean :
	rm -f $(MINISHELL)
	@echo "\033[0;31m[BORRANDO EJECUTABLE...]\033[1;32m"

re:		fclean all

.PHONY:	clean all fclean re
