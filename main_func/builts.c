#include "../minishell.h"

void	ft_pwd(char **args, int out)
{
	char	*path;

	path = getcwd(0, 0);
	ft_putendl_fd(path, out);
	free(path);
	clear_str_array(args);
	set_exit_status(0);
}

void	ft_echo(char **args, int out)
{
	int	i;
	int	n;

	i = 1;
	n = 0;
	if (args[1] && ft_strncmp(args[1], "-n", 3) == 0)
	{
		n = 1;
		while (args[i] && ft_strncmp(args[i], "-n", 3) == 0)
			i++;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], out);
		if (args[i + 1])
			ft_putstr_fd(" ", out);
		i++;
	}
	if (n != 1)
		ft_putstr_fd("\n", out);
	clear_str_array(args);
	set_exit_status(0);
}

void	ft_unset(char **args, t_data *data)
{
	int	i;

	if (data->env)
	{
		i = 0;
		while (args[i])
		{
			delete_one_env(&data->env, args[i]);
			i++;
		}
	}
	clear_str_array(args);
	set_exit_status(0);
}

void	ft_env(char **args, t_data *data, int out)
{
	t_list	*iter;

	iter = data->env;
	while (iter)
	{
		if (ft_strchr((char *)iter->content, '='))
			ft_putendl_fd((char *)iter->content, out);
		iter = iter->next;
	}
	clear_str_array(args);
	set_exit_status(0);
}

void	ft_exit(char **args, int id)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	if (id != 0)
		ft_putendl_fd("exit", STDERR_FILENO);
	if (i > 1)
	{
		if (!is_int(args[1]))
			ft_exit_error(args);
		else if (i > 2)
		{
			ft_putendl_fd(OUR_SHELL": exit: too many arguments", STDERR_FILENO);
			set_exit_status(1);
			return ;
		}
		else
			exit((int) ft_exit_atoi(args[1]));
	}
	else
		exit(0);
}
