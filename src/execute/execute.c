/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:14:14 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/22 19:39:47 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_redir(t_redir *redir, t_io	*io)
{
	if (redir->type == R_IN)
		redir_in(redir, io);
	else if (redir->type == R_OUT)
		redir_out(redir, io);
	else if (redir->type == R_HEREDOC)
		redir_heredoc(redir, io);
	else if (redir->type == R_OUT_APPEND)
		redir_out_append(redir, io);
}

void	exec_fork(t_command *cur, t_cmd *cmd_list,
		t_list *env_list, t_io *io_handler)
{
	pid_t	pid;

	if (pipe(io_handler->pipe) < 0)
		printf("error\n");
	pid = fork();
	if (pid == -1)
		printf("error\n");
	else if (pid == 0)
	{
		if (!cur->next)
			exit(1);
		set_signal(DEFAULT, DEFAULT);
		// child_process();
		// exec_child_cmd();
	}
	else
	{
		set_signal(IGNORE, IGNORE);
		// parent_process();
	}
}

void	exec_child_cmd()
{
	
}

void	exec_cmd(t_command *command, t_list *env_list)
{
	t_cmd		*cmd_list;
	t_io		*io_handler;
	t_command	*cur_cmd;

	cur_cmd = command;
	while (cur_cmd)
	{
		cmd_list = command->cmd_lst;
		io_handler = command->io_handler;
		if (!cur_cmd->next && built_in(cmd_list, env_list, io_handler))
			return ;
		else
			exec_fork(cur_cmd, cmd_list, env_list, io_handler);
		if (cur_cmd->next)
			cur_cmd = cur_cmd->next;
	}
	// g_status_code = set_status_cde();
}

void	execute(t_command *command, t_list *env_list)
{
	t_redir		*list;
	t_command	*cur;

	// io_init();
	cur = command;
	while (cur)
	{
		list = command->redir_lst;
		while (list)
		{
			exec_redir(list, cur->io_handler);
			if (list->next)
				list = list->next;
		}
		if (cur->next)
			cur = cur->next;
	}
	exec_cmd(command, env_list);
	//다 끝나면 fd 원상복구
}
