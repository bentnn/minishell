#include "../minishell.h"

char	**return_changed(char **array, int i, int j, int n)
{
	char	**res;

	while (i < n)
	{
		j += (array[i] != NULL);
		i++;
	}
	res = malloc(sizeof(char *) * (j + 1));
	i = 0;
	j = 0;
	while (i < n)
	{
		if (array[i] != NULL)
		{
			res[j] = array[i];
			j++;
		}
		i++;
	}
	res[j] = NULL;
	free(array);
	return (res);
}

void	set_nulls(char **array, int n, int j, int i)
{
	while (i < n)
	{
		if (is_redirect(array[i], 0))
			i += 2;
		else if (is_pipe(array[i], 0))
			i++;
		else
		{
			j = i + 1;
			while (j < n && array[j] && !is_pipe(array[j], 0))
			{
				if (!is_redirect(array[j], 0)
					&& !is_redirect(array[j - 1], 0))
				{
					array[i] = append_symbol(array[i], ' ');
					array[i] = str_plus_str(array[i], array[j]);
					free(array[j]);
					array[j] = NULL;
				}
				j++;
			}
			i = j + 1;
		}
	}
}

char	**change_args(char **array)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	j = 0;
	while (array[i])
	{
		if (is_redirect(array[i], 0) && array[i + 1]
			&& array[i + 2] && !is_redirect(array[i + 2], 0)
			&& !is_pipe(array[i + 2], 0))
		{
			j = 1;
			break ;
		}
		i++;
	}
	if (j == 0)
		return (array);
	n = 0;
	while (array[n])
		n++;
	set_nulls(array, n, 0, 0);
	return (return_changed(array, 0, 0, n));
}
