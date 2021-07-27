#include "../minishell.h"

static void	print_error_cmd(char **array, t_data *data, char **array_env)
{
	ft_putstr_fd(OUR_SHELL": ", STDERR_FILENO);
	ft_putstr_fd(array[0], STDERR_FILENO);
	ft_putendl_fd(": command not found", STDERR_FILENO);
	clear_str_array(array_env);
	clear_str_array(array);
	delete_data(data);
	exit(127);
}

static void	cmd_with_absolut_path(char **array, char **array_env)
{
	execve(array[0], array, array_env);
	ft_putstr_fd(OUR_SHELL": ", STDERR_FILENO);
	ft_putstr_fd(array[0], STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(strerror(errno), STDERR_FILENO);
	clear_str_array(array);
	clear_str_array(array_env);
	exit(errno);
}

static void	cmd_with_not_absolut_path(char **array,
										 char **array_env, char *path)
{
	char	**paths;
	int		i;
	char	*str;

	paths = ft_split(path, ':');
	free(path);
	i = 0;
	while (paths[i])
	{
		str = create_path_for_cmd(paths[i], array[0]);
		execve(str, array, array_env);
		free(str);
		i++;
	}
	clear_str_array(paths);
}

static int	start_bash_cmd(t_data *data)
{
	int	id;

	id = 1;
	if (data->pid != 0)
	{
		id = fork();
		if (id == -1)
		{
			ft_putendl_fd("Fork error", STDERR_FILENO);
			set_exit_status(228);
		}
	}
	return (id);
}

void	lounch_bash_cmd(t_ast *tree, t_tree_data *td,
						t_data *data, char **array)
{
	char	*path;
	char	**array_env;
	int		i;
	int		id;

	sigProcHandle();
	id = start_bash_cmd(data);
	if (id == -1)
		return ;
	if (data->pid == 0 || id == 0)
	{
		path = get_env_value(data->env, "PATH");
		dup2(td->out, STDOUT_FILENO);
		dup2(td->in, STDIN_FILENO);
		close_and_clear_all_shit(tree, td);
		array_env = env_to_array(data->env);
		if (ft_strchr(array[0], '/') || array[0][0] == '.')
			cmd_with_absolut_path(array, array_env);
		else if (path != NULL)
			cmd_with_not_absolut_path(array, array_env, path);
		print_error_cmd(array, data, array_env);
	}
	waitpid(id, &i, 0);
	set_exit_status(i / 256);
	clear_str_array(array);
}
