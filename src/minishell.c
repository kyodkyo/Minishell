/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:18:10 by woonshin          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/06/22 20:29:46 by dakyo            ###   ########.fr       */
=======
/*   Updated: 2024/06/22 19:13:55 by woonshin         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
<<<<<<< HEAD

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
=======

void	minishell(int argc, char **argv, char **envp)
{
	char	*input;
	t_mini	mini;
	int		result;
>>>>>>> main

	mini.env_list = init_envp(envp);
	while (1)
	{
		input = readline("minishell> ");
		if (input)
		{
<<<<<<< HEAD
			parse(&mini, input);
			init_io_handler(&io_handler);
			execute_tree(mini.astree_root, mini.env_list, &io_handler);
=======
			result = parse(&mini, input);
			if (result != 0)
			{
				printf("parse error\n");
				free(input);
				continue ;
			}
			print_ast(mini.astree_root, 0);
			// execute(command, env_list);
			free_ast(mini.astree_root);
>>>>>>> main
		}
		else
			break ;
		if (cmp_str(input, ""))
			add_history(input);
		free(input);

		// 실행
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
