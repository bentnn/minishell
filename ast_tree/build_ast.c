#include "ast.h"

static t_ast	*addNode(t_ast **ast, t_ast *new, t_ast *tmp, char *content)
{
	if (ft_rcmp(tmp->right->content) == 1 || ft_strcmp(content, "|") == 0)
	{
		new->left = tmp->right;
		tmp->right = new;
		return (*ast);
	}
	else
	{
		while (tmp->right != NULL && strcmp(tmp->right->content, "|") == 0)
			tmp = tmp->right;
		while (tmp->right != NULL && ft_rcmp(tmp->right->content) == 0)
			tmp = tmp->right;
		while (tmp->left != NULL && ft_rcmp(tmp->left->content) == 0)
			tmp = tmp->left;
		new->left = tmp->left;
		tmp->left = new;
		return (*ast);
	}
}

static t_ast	*addRedirToEnd(t_ast **ast, t_ast *new, t_ast *tmp)
{
	while (tmp->left != NULL && ft_rcmp(tmp->left->content) == 0)
		tmp = tmp->left;
	if (tmp->right == NULL)
		tmp->right = new;
	else
		tmp->left = new;
	return (*ast);
}

static t_ast	*add_node(void *content, t_ast **ast)
{
	t_ast	*new;
	t_ast	*tmp;

	new = (t_ast *)malloc(sizeof(t_ast));
	new->content = content;
	new->left = NULL;
	new->right = NULL;
	if (!*ast)
		return (new);
	tmp = *ast;
	if (ft_strcmp((*ast)->content, "|") == 0)
	{
		while (tmp->right != NULL)
		{
			if (((ft_strcmp(content, "|") == 0 || ft_rcmp(content) == 0))
				&& ft_strcmp(tmp->right->content, "|") != 0)
				return (addNode(ast, new, tmp, content));
			if (ft_rcmp(tmp->content) == 0)
				return (addRedirToEnd(ast, new, tmp));
			tmp = tmp->right;
		}
		tmp->right = new;
		return (*ast);
	}
	return (firstNodeLaunchin(ast, new, tmp, content));
}

t_ast	*generate_ast(char **tokens)
{
	t_ast	*ast;
	int		i;

	ast = NULL;
	i = 0;
	while (tokens[i])
	{
		ast = add_node(tokens[i], &ast);
		i++;
	}
	free(tokens);
	return (ast);
}
