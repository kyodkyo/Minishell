/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:29:26 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/21 02:22:20 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_t.h"

void	built_in_exit(t_cmd *cmd_list)
{
	int	exit_code;

	write(2, "exit\n", 5);
	if (!cmd_list->str[1])
		exit(0);
	exit_code = atoi(cmd_list->str[1]);
	if (cmd_list->str[2])
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
