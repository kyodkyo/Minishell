/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 23:20:52 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/15 03:04:24 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	error(void)
{
	printf("error");
}

void	redirection(t_redir *redir)
{
	t_io	*io;

	// io_initialize(&io);
	if (redir->type == IN)
		redir_in(redir, io);
	else if (redir->type == OUT)
		redir_out(redir, io);
	else if (redir->type == HEREDOC)
		redir_heredoc(redir, io);
	else if (redir->type == OUT_APPEND)
		redir_out_append(redir, io);
}
