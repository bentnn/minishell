#include "../minishell.h"

void	change_shlvl(t_data *data)
{
	t_list	*temp;
	char	*str;
	int		i;

	temp = find_env(data->env, "SHLVL");
	if (temp)
	{
		str = get_env_value(data->env, "SHLVL");
		i = ft_atoi(str);
		if (i < 0)
			i = 0;
		else
			i++;
		free(str);
		str = ft_itoa(i);
		replace_content(temp, str);
		free(str);
	}
	else
	{
		temp = ft_lstnew(ft_strdup("SHLVL=1"));
		ft_lstadd_back(&data->env, temp);
	}
}

t_data	*create_data(char **env, int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->env = push_env_to_list(env);
	data->fd_input = dup(STDIN_FILENO);
	data->fd_output = dup(STDOUT_FILENO);
	data->pid = 1;
	delete_one_env(&data->env, "OLDPWD");
	change_shlvl(data);
	data->view = (argc > 1 && ft_strncmp(argv[1], "-jopa", 6) == 0);
	return (data);
}

void	delete_data(t_data *data)
{
	ft_lstclear(&data->env, free);
	free(data);
}

int	is_there_her(char **token)
{
	int	her;
	int	i;

	her = 0;
	i = 0;
	while (token[i])
	{
		if (ft_strncmp(token[i], "<<", 3) == 0)
		{
			her = 1;
			break ;
		}
		i++;
	}
	return (her);
}

void	work_with_tree(t_data *data, char **token)
{
	int		her;
	t_ast	*ast;

	her = is_there_her(token);
	ast = generate_ast(token);
	if (data->view)
	{
		print_ast(ast);
		write(1, "\n", 1);
	}
	do_tree(ast, data, her);
	free_ast(&ast);
}
