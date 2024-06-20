/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:27:15 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/21 02:22:02 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_t.h"

int	built_in(t_cmd *cmd_list, t_list *env_list, t_io *io_handler)
{
	if (cmd_list->str[0])
		return (-1);
	to_lowercase(cmd_list->str[0]);
	if (compare_str(cmd_list->str[0], "cd", 2) == 0)
		cd(cmd_list, env_list);
	else if (compare_str(cmd_list->str[0], "echo", 4) == 0)
		echo(cmd_list, io_handler);
	else if (compare_str(cmd_list->str[0], "env", 3) == 0)
		env(env_list, io_handler);
	else if (compare_str(cmd_list->str[0], "exit", 4) == 0)
		built_in_exit(cmd_list);
	else if (compare_str(cmd_list->str[0], "export", 6) == 0)
		export(cmd_list, env_list, io_handler);
	else if (compare_str(cmd_list->str[0], "pwd", 3) == 0)
		pwd(io_handler);
	else if (compare_str(cmd_list->str[0], "unset", 5) == 0)
		unset(cmd_list, env_list);
	else
		return (-1);
	return (0);
}
