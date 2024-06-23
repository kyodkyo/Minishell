/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:29:26 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/23 17:21:37 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	built_in_exit(t_ASTNode *node)
{
	int	exit_code;

	write(2, "exit\n", 5);
	if (!node->cmd->argv[1])
		exit(0);
	exit_code = ft_atoi(node->cmd->argv[1]);
	if (node->cmd->argv[2])
	{
		write(1, "exit: too many arguments", 24);
		return ;
	}
	else
	{
		if (exit_code < 0 || 255 < exit_code)
		{
			write(1, "exit: numeric argument required", 30);
			exit(1);
		}
		exit(exit_code);
	}
}
