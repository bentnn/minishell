FILES = ast_tree/ast_hf.c ast_tree/build_ast.c ast_tree/build_astHF.c ast_tree/print_ast.c do_tree/bash_cmd.c do_tree/do_tree.c do_tree/exit_status.c do_tree/help_node_func.c \
		do_tree/heredoc.c do_tree/nodes_func.c do_tree/pipe_node.c do_tree/signals.c do_tree/signals2.c do_tree/td_func.c main_func/builts.c main_func/builts_utils.c main_func/ft_cd.c \
		main_func/ft_export.c main_func/help_func.c main_func/main.c parcer/split_to_tokens.c parcer/split_to_tokens2.c parcer/split_to_tokens3.c \
		parcer/split_to_tokens_utils.c parcer/split_token.c parcer/split_token2.c parcer/split_token_utils.c parcer/work_with_env.c parcer/work_with_env2.c
OFILES = $(patsubst %.c,%.o,$(FILES))
VPATH = do_tree/:main_func/:ast_tree/:parcer/:.
FLAGS = -Wall -Wextra -Werror -lreadline -L/Users/$(USER)/.brew/opt/readline/lib -I/Users/$(USER)/.brew/opt/readline/include -L Libft -lft
NAME = minishell
HEADER = minishell.h
HEADERAST = ast_tree/ast.h
FONT99 = \033[0m #сброс цвета
FONT00 = \033[1m #жирный шрифт
FONT01 = \033[4m #подчеркивание
COLOR0 = \033[47m #серый цвет фона
FONT3 = \033[44m #синий цвет шрифта
FONT4 = \033[33m #желтый цвет шрифта
COLOR5 = \033[42m #зелёный цвет фона
FONT5 = \033[32m #зелёный цвет шрифта
COLOR6 = \033[41m #красный цвет фона
FONT6 = \033[31m #красный цвет шрифта
all: 		$(NAME)
$(NAME): 	$(OFILES)
			@cd libft && make bonus && cd ..
			@gcc $(FILES) $(FLAGS) -o minishell
			@echo "$(COLOR0)$(FONT00)    BIGSHELL    $(FONT99)"
			@echo "$(FONT3)$(FONT00)      is        $(FONT99)"
			@echo "$(COLOR6)$(FONT00)     READY     $(FONT6)"
%.o:		%.c Makefile $(HEADER) $(HEADERAST)
			gcc -c $< -o $@
clean:
			rm -rf $(DEPS)
			rm -rf $(OFILES)
			cd libft && make clean && cd ..
fclean:	clean
			rm -rf $(NAME)
			rm -rf ./minishell
			cd libft && make fclean && cd ..

re: fclean all

.PHONY: all clean fclean re
