#include "ast.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while (*a != '\0' || *b != '\0')
	{
		if (*a != *b)
			return (*a - *b);
		a++;
		b++;
	}
	return (0);
}

int	countPipes(char **str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (ft_strcmp(*str, "|") == 0)
			i++;
		str++;
	}
	return (i);
}

int	ft_rcmp(char *str)
{
	if (ft_strcmp(str, "<") == 0 || ft_strcmp(str, "<<") == 0
		|| ft_strcmp(str, ">") == 0 || ft_strcmp(str, ">>") == 0)
		return (0);
	return (1);
}

void	free_ast(t_ast **ast)
{
	if ((*ast)->left != NULL)
		free_ast(&(*ast)->left);
	if ((*ast)->right != NULL)
		free_ast(&(*ast)->right);
	free((*ast)->content);
	free(*ast);
	*ast = NULL;
}
