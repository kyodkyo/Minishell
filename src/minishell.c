/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:18:10 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/19 18:07:37 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef struct s_redirection {
	int		type;
	char	*filename;
	t_redir	*next;
}	t_redir;

void	init_signal(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	signal(SIGQUIT, SIG_IGN);
}

void	execute(t_redir *redir_list)
{
	t_redir	*cur;

	cur = redir_list;
	while (cur)
	{
		execute_heredoc();
		if (cur->next)
			cur = cur->next;
	}
}

void	minishell(int argc, char **argv, char **envp)
{
	char	*input;
	t_list	*env_list;
	t_redir	*redir_list;

	env_list = init_envp(envp);
	while (1)
	{
		input = readline("minishell> ");
		if (input)
		{
			parse(input);
			execute(redir_list);
		}
		else
			break ;
		if (cmp_str(input, ""))
			add_history(input);
		free(input);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	struct termios	term;

	if (argc >= 2)
	{
		printf("argv error");
		exit(0);
	}
	tcgetattr(STDIN_FILENO, &term);
	init_signal();
	minishell(argc, argv, envp);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
