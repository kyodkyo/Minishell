/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:28:45 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/23 17:19:18 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo(t_ASTNode *node, t_io *io_handler)
{
	int	i;
	int	option;

	i = 1;
	option = 0;
	if (node->cmd->argv && compare_str(node->cmd->argv[1], "-n", 2) == 0)
	{
		i++;
		option = 1;
	}
	while (node->cmd->argv[i])
	{
		write(io_handler->output_fd, node->cmd->argv[i],
			ft_strlen(node->cmd->argv[i]));
		if (node->cmd->argv[i + 1])
			write(io_handler->output_fd, " ", 1);
		i++;
	}
	if (!option)
		write(io_handler->output_fd, "\n", 1);
}
