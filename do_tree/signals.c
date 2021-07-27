#include "../minishell.h"

void	handlerInt(int signum)
{
	signum = 0;
	rl_on_new_line();
	rl_redisplay();
	write(1, "  \b\b\n", 5);
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
	set_exit_status(1);
}

void	sigHDHandle(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handlerIntHD);
}

void	sigProcHandle(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, handlerIntQuit);
	signal(SIGINT, handlerIntProc);
}

void	sigHandle(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handlerInt);
}
