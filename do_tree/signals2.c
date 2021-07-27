#include "../minishell.h"

void	handlerIntQuit(int signum)
{
	(void)signum;
	printf("Quit: 3\n");
	set_exit_status(131);
}

void	handlerIntProc(int signum)
{
	(void)signum;
	set_exit_status(130);
	printf("\n");
	rl_on_new_line();
}

void	handlerIntHD(int signum)
{
	signum = 0;
	rl_on_new_line();
	rl_redisplay();
	write(1, "  \b\b\n", 5);
	exit(1);
}
