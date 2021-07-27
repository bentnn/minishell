#ifndef MINISHELL_H
# define MINISHELL_H
# define OUR_SHELL "\U0001F33B\U0001F33B\U0001F33B\U0001F33B\U0001F33B"
# include <stdio.h>
# include <sys/stat.h>
# include "libft/libft.h"
# include <errno.h>
# include "ast_tree/ast.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>

typedef struct s_data
{
	t_list	*env;
	int		pid;
	int		fd_output;
	int		fd_input;
	int		view;
}	t_data;

typedef struct s_tree_data
{
	int	*pipes;
	int	*files;
	int	out;
	int	in;
	int	end;
}	t_tree_data;

void		rl_replace_line(const char *text, int clear_undo);
void		rl_clear_history(void);
char		**split_to_tokens(char *str);
void		replace_content(t_list *node, const char *new);
t_list		*find_env(t_list *env, const char *name);
t_list		*push_env_to_list(char **env);
char		**split_token(char *string, t_list *env);
char		*str_plus_str(char *dst, const char *src);
void		delete_one_env(t_list **env, const char *name);
char		**env_to_array(t_list *env);
char		*get_env_value(t_list *env, const char *name);
char		*get_env_name(const char *str);
void		replace_or_add_new_env(t_list **env, const char *name, char *new);
int			cmp_env_and_name(t_list *node, const char *name);
int			is_pipe(const char *str, int i);
int			is_redirect(const char *str, int i);
int			is_not_cmd(const char *str);
char		**add_token_to_array(char **array, char *str);
int			last_is_redir(char **array);
char		*append_symbol(char *str, char ch);
char		*append_dollar(const char *str, char *res, int st, t_list *env);
void		ft_pwd(char **args, int out);
void		ft_echo(char **args, int out);
void		ft_unset(char **args, t_data *data);
void		ft_env(char **args, t_data *data, int out);
void		ft_exit(char **args, int id);
void		ft_cd(char **args, t_data *data, int out);
void		ft_export(char **args, t_data *data, int out);
void		clear_str_array(char **args);
char		**sort_array_env(char **array);
void		do_tree(t_ast *tree, t_data *data, int her);
char		**if_multi_redir(char **array, int i);
char		**check_multi_redir_and_pipes(char **array);
char		**if_pipe_stt(char **res);
char		**if_redir_stt(char **res, int *i_stt, char *str);
void		hereIs(int fd, char *key, t_list *env);
char		**change_args(char **array);
void		delete_data(t_data *data);
int			get_exit_status(void);
void		set_exit_status(int new);
void		sigHDHandle(void);
void		sigProcHandle(void);
void		sigHandle(void);
void		change_shlvl(t_data *data);
t_data		*create_data(char **env, int argc, char **argv);
void		delete_data(t_data *data);
int			is_there_her(char **token);
void		work_with_tree(t_data *data, char **token);
char		*push_content(t_list *env, char *temp, char *res);
char		*check_simb(char *str);
char		**add_str_to_array(char **array, char *str);
char		*push_content(t_list *env, char *temp, char *res);
char		*if_one_q(char *res, int *i_st, char *str);
char		*if_two_q(char *res, int *i_st, char *str);
char		*if_single_q(char *str, int i, int *simb_st, char *res);
char		**sort_array_env(char **array);
int			is_int(const char *str);
long long	ft_exit_atoi(const char *str);
void		ft_exit_error(char **args);

void		do_node(t_ast *tree, t_tree_data *td, t_data *data);
void		redir_left(t_ast *tree, t_tree_data *td, t_data *data);
void		redir_right(t_ast *tree, t_tree_data *td, t_data *data);
void		double_redir_right(t_ast *tree, t_tree_data *td, t_data *data);
void		heredoc_node(t_ast *tree, t_tree_data *td, t_data *data);
void		empty_node(t_ast *tree, t_tree_data *td, t_data *data);
void		pipe_node(t_ast *tree, t_tree_data *td, t_data *data);
void		lounch_bash_cmd(t_ast *tree, t_tree_data *td,
				t_data *data, char **array);
char		*create_path_for_cmd(const char *path, const char *cmd);
t_tree_data	*create_td(void);
void		update_td_without_pipes(t_tree_data *td);
void		update_td(t_tree_data *td);
void		delete_td(t_tree_data *td);
void		add_new_pipes(t_tree_data *td, int fd);
void		delete_td(t_tree_data *td);
void		update_td_without_pipes(t_tree_data *td);
void		update_td(t_tree_data *td);
void		add_new_pipes(t_tree_data *td, int fd);
void		add_new_files(t_tree_data *td, int fd);
void		close_and_clear_all_shit(t_ast *tree, t_tree_data *td);

void		handlerInt(int signum);
void		sigHDHandle(void);
void		sigProcHandle(void);
void		sigHandle(void);
void		handlerIntQuit(int signum);
void		handlerIntProc(int signum);
void		handlerIntHD(int signum);
void		add_new_files(t_tree_data *td, int fd);
void		close_and_clear_all_shit(t_ast *tree, t_tree_data *td);
char		*create_path_for_cmd(const char *path, const char *cmd);
void		if_no_array(t_ast *tree, t_tree_data *td,
				t_data *data, char **array);
#endif
