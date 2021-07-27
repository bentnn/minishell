#include "../minishell.h"

t_tree_data	*create_td(void)
{
	t_tree_data	*td;

	td = malloc(sizeof(t_tree_data));
	td->end = 0;
	td->in = 0;
	td->out = 1;
	td->pipes = NULL;
	td->files = NULL;
	return (td);
}

void	update_td_without_pipes(t_tree_data *td)
{
	int	i;

	if (td->files)
	{
		i = 0;
		while (td->files[i] != -1)
		{
			close(td->files[i]);
			i++;
		}
		free(td->files);
		td->files = NULL;
	}
	td->end = 0;
	td->in = 0;
	td->out = 1;
}

void	update_td(t_tree_data *td)
{
	int	i;

	if (td->pipes)
	{
		i = 0;
		while (td->pipes[i] != -1)
			close(td->pipes[i++]);
		free(td->pipes);
		td->pipes = NULL;
	}
	if (td->files)
	{
		i = 0;
		while (td->files[i] != -1)
			close(td->files[i++]);
		free(td->files);
		td->files = NULL;
	}
	td->end = 0;
	td->in = 0;
	td->out = 1;
}

void	delete_td(t_tree_data *td)
{
	update_td(td);
	free(td);
}

void	add_new_pipes(t_tree_data *td, int fd)
{
	int	*new;
	int	i;

	i = 0;
	if (td->pipes)
	{
		while (td->pipes[i] != -1)
			i++;
	}
	new = malloc(sizeof(int) * (i + 2));
	if (i != 0)
	{
		i = 0;
		while (td->pipes[i] != -1)
		{
			new[i] = td->pipes[i];
			i++;
		}
		free(td->pipes);
	}
	new[i++] = fd;
	new[i] = -1;
	td->pipes = new;
}
