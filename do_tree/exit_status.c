#include "../minishell.h"

static int	our_status(const int *new)
{
	static int	status;

	if (new)
		status = *new;
	return (status);
}

int	get_exit_status(void)
{
	return (our_status(NULL));
}

void	set_exit_status(int new)
{
	our_status(&new);
}
