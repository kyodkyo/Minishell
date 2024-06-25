/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:28:45 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/25 21:40:19 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	echo(t_ASTNode *node)
{
	int	i;
	int	option;

	i = 1;
	option = 0;
	if (1 < node->cmd->argc && node->cmd->argv
		&& cmp_str(node->cmd->argv[1], "-n") == 0)
	{
		i++;
		option = 1;
	}
	while (1 < node->cmd->argc && node->cmd->argv[i])
	{
		write(STDOUT_FILENO, node->cmd->argv[i],
			ft_strlen(node->cmd->argv[i]));
		if (node->cmd->argv[i + 1])
			write(STDOUT_FILENO, " ", 1);
		i++;
	}
	if (!option)
		write(STDOUT_FILENO, "\n", 1);
}
