/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 00:02:26 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/25 20:29:55 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	heredoc_child_process(int fd, char *delimiter);

void	redir_in(t_ASTNode *node)
{
	int	fd;

	fd = open(node->value, O_RDONLY);
	if (fd < 0)
	{
		file_open_error(node->value);
		return ;
	}
	close(STDIN_FILENO);
	dup2(fd, STDIN_FILENO);
}

void	redir_out(t_ASTNode *node)
{
	int	fd;

	fd = open(node->value, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
	{
		file_open_error(node->value);
		return ;
	}
	close(STDOUT_FILENO);
	dup2(fd, STDOUT_FILENO);
}

void	redir_heredoc(t_ASTNode *node)
{
	int	fd;

	fd = open(node->value, O_RDONLY);
	if (fd < 0)
	{
		file_open_error(node->value);
		return ;
	}
	close(STDIN_FILENO);
	dup2(fd, STDIN_FILENO);
}

void	redir_out_append(t_ASTNode *node)
{
	int	fd;

	fd = open(node->value, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd < 0)
	{
		file_open_error(node->value);
		return ;
	}
	close(STDOUT_FILENO);
	dup2(fd, STDOUT_FILENO);
}
