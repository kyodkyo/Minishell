/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:32:21 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/20 16:27:29 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	child_process(char *delimiter, t_io *io)
{
	char	*line;

	set_signal(HEREDOC, IGNORE);
	while (1)
	{
		line = readline("heredoc> ");
		if (line)
		{
			if (!cmp_str(line, delimiter))
			{
				status_code = 1;
				break ;
			}
			write(io->input_fd, line, ft_strlen(line));
			write(io->input_fd, "\n", 1);
			free(line);
		}
		else
			break ;
	}
	free(line);
	exit(0);
}
