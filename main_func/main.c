#include "../minishell.h"

void	clear_str_array(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

int	end_of_main(t_data *data)
{
	rl_clear_history();
	delete_data(data);
	unlink("/tmp/.aboba");
	return (0);
}

char	*start_loop(void)
{
	sigHandle();
	unlink("/tmp/.aboba");
	return (readline(OUR_SHELL": "));
}

char	**work_with_tokens(char *str)
{
	char	**token;

	add_history(str);
	token = split_to_tokens(str);
	free(str);
	return (token);
}

int	main(int argc, char **argv, char **env)
{
	char	*str;
	char	**token;
	t_data	*data;

	data = create_data(env, argc, argv);
	while (1)
	{
		str = start_loop();
		if (!str)
		{
			ft_putendl_fd("exit", STDOUT_FILENO);
			break ;
		}
		if (str[0] == '\0')
		{
			free(str);
			continue ;
		}
		token = work_with_tokens(str);
		if (!token)
			continue ;
		work_with_tree(data, token);
	}
	return (end_of_main(data));
}
