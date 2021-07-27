#include "../minishell.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

char	**sort_array_env(char **array)
{
	int		i;
	int		j;
	int		max;
	char	*temp;

	i = 0;
	while (array[i] != NULL)
	{
		j = i + 1;
		while (array[j] != NULL)
		{
			max = ft_max((int)ft_strlen(array[i]), (int)ft_strlen(array[j]));
			if (ft_strncmp(array[i], array[j], max) > 0)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (array);
}

int	is_int(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
	{
		if (str[1] == '\0')
			return (0);
		i++;
		if (ft_strlen(str) > 20
			|| ft_strncmp(str, "-9223372036854775808", 20) > 0)
			return (0);
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (ft_strlen(str) > 20 || ft_strncmp(str, "9223372036854775807", 20) > 0)
		return (0);
	return (1);
}

long long	ft_exit_atoi(const char *str)
{
	int						minus;
	unsigned long long		result;

	minus = 1;
	result = 0;
	while (*str && (*str == ' ' || *str == '\t' || *str == '\r' || *str == '\n'
			|| *str == '\v' || *str == '\f'))
		str++;
	if (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			minus = -1;
		str++;
	}
	while (*str && *str >= 48 && *str <= 57)
	{
		if (result > LLONG_MAX && minus == 1)
			return (-1);
		if (result > LLONG_MAX && minus == -1)
			return (0);
		result = result * 10 + (*str - 48);
		str++;
	}
	return ((long long)result * minus);
}

void	ft_exit_error(char **args)
{
	ft_putstr_fd(OUR_SHELL": exit: ", STDERR_FILENO);
	ft_putstr_fd(args[1], STDERR_FILENO);
	ft_putendl_fd(": numeric argument required", STDERR_FILENO);
	clear_str_array(args);
	exit(255);
}
