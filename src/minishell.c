/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:18:10 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/22 20:29:46 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_io_handler(t_io *io_handler)
{
	io_handler->input_fd = STDIN_FILENO;
	io_handler->output_fd = STDOUT_FILENO;
	io_handler->next_pipe = 0;
	io_handler->prev_pipe = 0;
	io_handler->pipe_read_fd = STDIN_FILENO;
	io_handler->pipe_write_fd = STDOUT_FILENO;
}

void	minishell(int argc, char **argv, char **envp)
{
	char		*input;
	t_io		io_handler;
	t_mini		mini;

	mini.env_list = init_envp(envp);
	while (1)
	{
		input = readline("minishell> ");
		if (input)
		{
			parse(&mini, input);
			init_io_handler(&io_handler);
			execute_tree(mini.astree_root, mini.env_list, &io_handler);
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
