/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:27:58 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/23 23:33:16 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msignal.h"

void	sig_shell(int sig)
{
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_status_code = 1;
}

void	sig_heredoc(int sig)
{
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	printf("\n");
	exit(1);
}

void	set_signal(int s_int, int s_quit)
{
	if (s_int == DEFAULT)
		signal(SIGINT, SIG_DFL);
	if (s_int == IGNORE)
		signal(SIGINT, SIG_IGN);
	if (s_int == SHELL)
		signal(SIGINT, sig_shell);
	if (s_int == HEREDOC)
		signal(SIGINT, sig_heredoc);
	if (s_quit == DEFAULT)
		signal(SIGQUIT, SIG_DFL);
	if (s_quit == IGNORE)
		signal(SIGQUIT, SIG_IGN);
	if (s_quit == SHELL)
		signal(SIGQUIT, SIG_IGN);
}

void	init_signal(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	set_signal(SHELL, SHELL);
}
