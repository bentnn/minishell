#include "../minishell.h"

char	*check_dollar(char *str, char *line, t_list *env)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '$')
			str = append_symbol(str, line[i]);
		else
		{
			str = append_dollar(line, str, i, env);
			i++;
			while (line[i] && line[i] != '\''
				&& line[i] != '\"' && line[i] != ' ' && line[i] != '$')
				i++;
			i -= (line[i] == '$'
					|| line[i] == '\'' || line[i] == '\"' || line[i] == ' ');
		}
		if (line[i])
			i++;
	}
	str = append_symbol(str, '\n');
	free(line);
	return (str);
}

void	print_her(char *str, int fd)
{
	int	i;

	rl_redisplay();
	i = 0;
	while (str[i] != '\0')
		write(fd, &str[i++], 1);
	free(str);
}

void	hereIs(int fd, char *key, t_list *env)
{
	char	*line;
	char	*str;
	int		i;

	str = malloc(sizeof(char));
	*str = '\0';
	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			print_her(str, fd);
			return ;
		}
		if (ft_strcmp(line, key) == 0)
		{
			i = 0;
			while (str[i] != '\0')
				write(fd, &str[i++], 1);
			free(str);
			free(line);
			break ;
		}
		str = check_dollar(str, line, env);
	}
}
