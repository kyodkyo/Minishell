/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:29:26 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/25 18:35:18 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	built_in_exit(t_ASTNode *node)
{
	int	exit_code;

	ft_putendl_fd("exit", 2);
	if (!node->cmd->argv[1])
		exit(g_status_code);
	exit_code = ft_atoi(node->cmd->argv[1]);
	if (ft_strlen(node->cmd->argv[1]) > 3 || exit_code < 0 || 255 < exit_code)
	{
		ft_putendl_fd("exit: numeric argument required", 2);
		exit(255);
	}
	if (node->cmd->argv[2])
	{
		ft_putendl_fd("exit: too many arguments", 2);
		g_status_code = 1;
		return ;
	}
	else
		exit(exit_code);
}
