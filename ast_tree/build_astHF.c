#include "ast.h"

t_ast	*fNodePR(t_ast **ast, t_ast *new, t_ast *tmp, char *content)
{
	if (ft_rcmp((*ast)->content) == 1 || strcmp(content, "|") == 0)
	{
		new->left = *ast;
		return (new);
	}
	else
	{
		while (tmp->left != NULL && ft_rcmp(tmp->left->content) == 0)
			tmp = tmp->left;
		new->left = tmp->left;
		tmp->left = new;
		return (*ast);
	}
}

t_ast	*firstNodeLaunchin(t_ast **ast, t_ast *new, t_ast *tmp, char *content)
{
	if (strcmp(content, "|") == 0 || ft_rcmp(content) == 0)
		return (fNodePR(ast, new, tmp, content));
	if (ft_rcmp((*ast)->content) == 0)
	{
		while (tmp->left != NULL && ft_rcmp(tmp->left->content) == 0)
			tmp = tmp->left;
		if (tmp->right == NULL)
			tmp->right = new;
		else
			tmp->left = new;
		return (*ast);
	}
	while (tmp->left != NULL)
		tmp = tmp->left;
	tmp->left = new;
	return (*ast);
}
