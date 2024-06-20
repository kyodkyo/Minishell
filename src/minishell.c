/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:18:10 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/20 18:28:03 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "execute.h"

typedef struct s_redirection {
	int		type;
	char	*filename;
	t_redir	*next;
}	t_redir;

void	minishell(int argc, char **argv, char **envp)
{
	char		*input;
	t_list		*env_list;
	t_command	*command;

	env_list = init_envp(envp);
	while (1)
	{
		input = readline("minishell> ");
		if (input)
		{
			parse(input);
			execute(command);
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
