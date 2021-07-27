#include "../minishell.h"

void	lounch_cmd(t_ast *tree, t_tree_data *td, t_data *data)
{
	char	**array;

	array = split_token((char *)tree->content, data->env);
	if (!array[0])
		if_no_array(tree, td, data, array);
	if (ft_strncmp(array[0], "cd", 3) == 0)
		ft_cd(array, data, td->out);
	else if (ft_strncmp(array[0], "pwd", 4) == 0)
		ft_pwd(array, td->out);
	else if (ft_strncmp(array[0], "env", 4) == 0)
		ft_env(array, data, td->out);
	else if (ft_strncmp(array[0], "echo", 5) == 0)
		ft_echo(array, td->out);
	else if (ft_strncmp(array[0], "export", 7) == 0)
		ft_export(array, data, td->out);
	else if (ft_strncmp(array[0], "unset", 6) == 0)
		ft_unset(array, data);
	else if (ft_strncmp(array[0], "exit", 5) == 0)
		ft_exit(array, data->pid);
	else
		lounch_bash_cmd(tree, td, data, array);
	if (data->pid == 0)
		exit(get_exit_status());
}

void	do_node(t_ast *tree, t_tree_data *td, t_data *data)
{
	if (!tree)
		empty_node(tree, td, data);
	else if (ft_strncmp((char *)tree->content, "<", 2) == 0)
		redir_left(tree, td, data);
	else if (ft_strncmp((char *)tree->content, ">", 2) == 0)
		redir_right(tree, td, data);
	else if (ft_strncmp((char *)tree->content, ">>", 3) == 0)
		double_redir_right(tree, td, data);
	else if (ft_strncmp((char *)tree->content, "<<", 3) == 0)
		heredoc_node(tree, td, data);
	else if (ft_strncmp((char *)tree->content, "|", 2) == 0)
		pipe_node(tree, td, data);
	else
	{
		lounch_cmd(tree, td, data);
		td->end = 1;
	}
}

void	open_all_heredoc(t_ast *tree, t_data *data)
{
	int	i;

	if (!tree)
		return ;
	if (ft_strncmp((char *)tree->content, "<<", 3) == 0)
	{
		i = open("/tmp/.aboba", O_CREAT | O_TRUNC | O_WRONLY,
				S_IRUSR | S_IRGRP | S_IWUSR | S_IROTH);
		hereIs(i, tree->right->content, data->env);
		close(i);
	}
	open_all_heredoc(tree->left, data);
	open_all_heredoc(tree->right, data);
}

void	do_tree(t_ast *tree, t_data *data, int her)
{
	int			id;
	int			i;
	t_tree_data	*td;

	if (her)
	{
		id = fork();
		signal(SIGINT, SIG_IGN);
		if (id == 0)
		{
			sigHDHandle();
			open_all_heredoc(tree, data);
			exit(0);
		}
		waitpid(id, &i, 0);
		if (WTERMSIG(i) == SIGINT)
			set_exit_status(1);
		else
			set_exit_status(i / 256);
	}
	td = create_td();
	do_node(tree, td, data);
	delete_td(td);
}
