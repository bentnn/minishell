#include "../minishell.h"

void	add_new_files(t_tree_data *td, int fd)
{
	int	*new;
	int	i;

	i = 0;
	if (td->files)
	{
		while (td->files[i] != -1)
			i++;
	}
	new = malloc(sizeof(int) * (i + 2));
	if (i != 0)
	{
		i = 0;
		while (td->files[i] != -1)
		{
			new[i] = td->files[i];
			i++;
		}
		free(td->files);
	}
	new[i++] = fd;
	new[i] = -1;
	td->files = new;
}

void	close_and_clear_all_shit(t_ast *tree, t_tree_data *td)
{
	free_ast(&tree);
	delete_td(td);
}

char	*create_path_for_cmd(const char *path, const char *cmd)
{
	int		i;
	int		j;
	char	*res;

	res = malloc(sizeof(char) * (ft_strlen(path) + ft_strlen(cmd) + 2));
	i = 0;
	j = 0;
	while (path[i])
	{
		res[j] = path[i];
		j++;
		i++;
	}
	res[j++] = '/';
	i = 0;
	while (cmd[i])
	{
		res[j] = cmd[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}

void	if_no_array(t_ast *tree, t_tree_data *td, t_data *data, char **array)
{
	free(array);
	empty_node(tree, td, data);
}
