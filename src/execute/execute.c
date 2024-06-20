/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:14:14 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/20 18:47:41 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	exec_redir(t_redir *redir, t_io	*io)
{
	if (redir->type == IN)
		redir_in(redir, io);
	else if (redir->type == OUT)
		redir_out(redir, io);
	else if (redir->type == HEREDOC)
		redir_heredoc(redir, io);
	else if (redir->type == OUT_APPEND)
		redir_out_append(redir, io);
}

void	exec_cmd(t_command *command)
{
	t_cmd	*list;

	list = command->cmd_lst;
	while (list)
	{
		// built_in 또는 fork 실행
		if (list->next)
			list = list->next;
	}
}

void	execute(t_command *command)
{
	t_redir		*list;
	t_command	*cur;

	io_init();
	cur = command;
	while (cur) // 입력받은 문장의 모든 redir을 파이프별로 먼저 실행
	{
		list = command->redir_lst;
		while (list)
		{
			exec_redir(list->type, cur->io_handler);
			if (list->next)
				list = list->next;
		}
		if (cur->next)
			cur = cur->next;
	}
	exec_cmd(command);
	//다 끝나면 fd 원상복구
}

void	error(void)
{
	printf("error");
}
