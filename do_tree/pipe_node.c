#include "../minishell.h"

void	child_to_do(t_ast *tree, t_tree_data *td, t_data *data)
{
	data->pid = 0;
	do_node(tree, td, data);
}

void	end_of_pipes(t_tree_data *td, t_data *data, int *id)
{
	int	i;

	i = 0;
	while (td->pipes[i] != -1)
	{
		close(td->pipes[i]);
		i++;
	}
	waitpid(id[0], 0, 0);
	waitpid(id[1], &i, 0);
	set_exit_status(i / 256);
	if (data->pid == 0)
		exit(get_exit_status());
}

void	pipe_node(t_ast *tree, t_tree_data *td, t_data *data)
{
	int	i;
	int	fd[2];
	int	id[2];

	i = pipe(fd);
	if (i == -1)
	{
		ft_putendl_fd("Pipe error", STDERR_FILENO);
		return ;
	}
	add_new_pipes(td, fd[1]);
	add_new_pipes(td, fd[0]);
	td->out = fd[1];
	id[0] = fork();
	if (id[0] == 0)
		child_to_do(tree->left, td, data);
	update_td_without_pipes(td);
	td->in = fd[0];
	id[1] = fork();
	if (id[1] == 0)
		child_to_do(tree->right, td, data);
	end_of_pipes(td, data, id);
}
