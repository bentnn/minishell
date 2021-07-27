#include "../minishell.h"

void	redir_left(t_ast *tree, t_tree_data *td, t_data *data)
{
	int	i;

	i = open((char *)tree->right->content, O_RDONLY);
	if (i == -1)
	{
		ft_putstr_fd(OUR_SHELL": ", STDERR_FILENO);
		ft_putstr_fd((char *)tree->right->content, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd(strerror(errno), STDERR_FILENO);
		td->end = 1;
	}
	else
	{
		add_new_files(td, i);
		td->in = i;
		do_node(tree->left, td, data);
	}
}

void	redir_right(t_ast *tree, t_tree_data *td, t_data *data)
{
	int	i;

	i = open((char *)tree->right->content, O_CREAT | O_TRUNC | O_WRONLY,
			 S_IRUSR | S_IRGRP | S_IWUSR | S_IROTH);
	if (i == -1)
	{
		ft_putstr_fd(OUR_SHELL": ", STDERR_FILENO);
		ft_putstr_fd((char *)tree->right->content, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd(strerror(errno), STDERR_FILENO);
		td->end = 1;
	}
	else
	{
		add_new_files(td, i);
		td->out = i;
		do_node(tree->left, td, data);
	}
}

void	double_redir_right(t_ast *tree, t_tree_data *td, t_data *data)
{
	int	i;

	i = open((char *)tree->right->content, O_CREAT | O_APPEND | O_WRONLY,
			 S_IRUSR | S_IRGRP | S_IWUSR | S_IROTH);
	if (i == -1)
	{
		ft_putstr_fd(OUR_SHELL": ", STDERR_FILENO);
		ft_putstr_fd((char *)tree->right->content, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd(strerror(errno), STDERR_FILENO);
		td->end = 1;
	}
	else
	{
		add_new_files(td, i);
		td->out = i;
		do_node(tree->left, td, data);
	}
}

void	heredoc_node(t_ast *tree, t_tree_data *td, t_data *data)
{
	int	i;

	i = open("/tmp/.aboba", O_RDONLY);
	add_new_files(td, i);
	td->in = i;
	do_node(tree->left, td, data);
	close(i);
}

void	empty_node(t_ast *tree, t_tree_data *td, t_data *data)
{
	if (data->pid == 0)
	{
		delete_data(data);
		delete_td(td);
		free_ast(&tree);
		exit(0);
	}
	else
		return ;
}
