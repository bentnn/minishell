#ifndef AST_H
# define AST_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_ast {
	void			*content;
	struct s_ast	*left;
	struct s_ast	*right;
}	t_ast;

t_ast	*fNodePR(t_ast **ast, t_ast *new, t_ast *tmp, char *content);
t_ast	*firstNodeLaunchin(t_ast **ast, t_ast *new, t_ast *tmp, char *content);
t_ast	*generate_ast(char **tokens);
void	launch_ast(t_ast *ast);
int		ft_rcmp(char *str);
int		countPipes(char **str);
void	print_ast(t_ast *root);
void	free_ast(t_ast **ast);
int		ft_strcmp(const char *s1, const char *s2);
#endif
