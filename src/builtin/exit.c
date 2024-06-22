/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:29:26 by dakyo             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/06/23 01:30:01 by dakyo            ###   ########.fr       */
=======
/*   Updated: 2024/06/22 17:19:51 by woonshin         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	built_in_exit(t_ASTNode *node)
{
	int	exit_code;

	write(2, "exit\n", 5);
	if (!node->value[1])
		exit(0);
	exit_code = ft_atoi(&node->value[1]);
	if (node->value[2])
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
