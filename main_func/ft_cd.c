#include "../minishell.h"

void	write_error_for_cd(char *str)
{
	ft_putstr_fd(OUR_SHELL, STDERR_FILENO);
	ft_putstr_fd(": cd: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(strerror(errno), STDERR_FILENO);
}

void	ft_cd_home(char *pwd, t_data *data)
{
	char	*home;
	char	*path;

	home = get_env_value(data->env, "HOME");
	set_exit_status(1);
	if (!home)
	{
		ft_putstr_fd(OUR_SHELL, STDERR_FILENO);
		ft_putendl_fd(": cd: HOME not set", STDERR_FILENO);
	}
	else
	{
		if (chdir(home) == -1)
			write_error_for_cd(home);
		else
		{
			replace_or_add_new_env(&data->env, "OLDPWD", pwd);
			path = getcwd(0, 0);
			replace_or_add_new_env(&data->env, "PWD", path);
			free(path);
			set_exit_status(0);
		}
		free(home);
	}
}

void	ft_cd_oldpwd(char *pwd, t_data *data, int out)
{
	char	*home;
	char	*path;

	home = get_env_value(data->env, "OLDPWD");
	set_exit_status(1);
	if (!home)
	{
		ft_putstr_fd(OUR_SHELL, STDERR_FILENO);
		ft_putendl_fd(": cd: OLDPWD not set", STDERR_FILENO);
	}
	else
	{
		if (chdir(home) == -1)
			write_error_for_cd(home);
		else
		{
			path = getcwd(0, 0);
			ft_putendl_fd(path, out);
			replace_or_add_new_env(&data->env, "OLDPWD", pwd);
			replace_or_add_new_env(&data->env, "PWD", path);
			free(path);
			set_exit_status(0);
		}
		free(home);
	}
}

void	ft_cd(char **args, t_data *data, int out)
{
	int		res;
	char	*path;
	char	*pwd;

	pwd = getcwd(0, 0);
	if (args[1] == NULL)
		ft_cd_home(pwd, data);
	else if (ft_strncmp(args[1], "-", 2) == 0)
		ft_cd_oldpwd(pwd, data, out);
	else
	{
		res = chdir(args[1]);
		if (res != -1)
		{
			path = getcwd(0, 0);
			replace_or_add_new_env(&data->env, "OLDPWD", pwd);
			replace_or_add_new_env(&data->env, "PWD", path);
			free(path);
		}
		else
			write_error_for_cd(args[1]);
		set_exit_status(res == -1);
	}
	free(pwd);
	clear_str_array(args);
}
