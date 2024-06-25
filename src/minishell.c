/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:18:10 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/25 21:06:06 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_add_history(char *input)
{
	if (cmp_str(input, ""))
		add_history(input);
}

void	minishell(int argc, char **argv, char **envp)
{
	char		*input;
	t_mini		mini;
	int			origin_fd[2];

	mini.env_list = init_envp(envp);
	while (1)
	{
		origin_fd[0] = dup(STDIN_FILENO);
		origin_fd[1] = dup(STDOUT_FILENO);
		input = readline("minishell> ");
		if (!input)
			break ;
		if (parse(&mini, input) != 0)
		{
			ft_putendl_fd("parsing error", 1);
			free(input);
			continue ;
		}
		set_cmd_path(mini.astree_root, mini.env_list);
		execute(mini.astree_root, mini.env_list);
		dup2(origin_fd[0], STDIN_FILENO);
		dup2(origin_fd[1], STDOUT_FILENO);
		cmd_add_history(input);
		free(input);
	}
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
