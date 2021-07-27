#include "ast.h"

static void	print_tab(int pref_len)
{
	printf("|");
	while (pref_len--)
		printf("\t|");
}

static void	_print_ast(t_ast *root, int pref_len)
{
	if (root == NULL)
		return ;
	print_tab(pref_len);
	printf("Node data: %s\n", root->content);
	if (root->right != NULL)
	{
		print_tab(pref_len);
		printf("RIGHT {\n");
		_print_ast(root->right, pref_len + 1);
		print_tab(pref_len);
		printf("}\n");
	}
	if (root->left != NULL)
	{
		print_tab(pref_len);
		printf("LEFT {\n");
		_print_ast(root->left, pref_len + 1);
		print_tab(pref_len);
		printf("}\n");
	}
}

void	print_ast(t_ast *root)
{
	_print_ast(root, 0);
}
