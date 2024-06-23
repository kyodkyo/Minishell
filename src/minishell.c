/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:18:10 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/23 23:17:57 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	minishell(int argc, char **argv, char **envp)
{
	char		*input;
	t_mini		mini;
	int			result;

	mini.env_list = init_envp(envp);
	while (1)
	{
		input = readline("minishell> ");
		if (input)
		{
			result = parse(&mini, input);
			if (result != 0)
			{
				printf("parse error\n");
				free(input);
				continue ;
			}
			// print_ast(mini.astree_root, 0);
			set_cmd_path(mini.astree_root, mini.env_list);
			execute(mini.astree_root, mini.env_list);
			free_ast(mini.astree_root);
		}
		else
			break ;
		if (cmp_str(input, ""))
			add_history(input);
		free(input);
	}
	return ;
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
