/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:27:15 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/19 16:30:01 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "utils.h"

int	built_in(int argc, char **argv, char **envp)
{
	t_list	*env_list;

	if (!argv[0])
		return (-1);
	to_lowercase(argv[0]);
	if (compare_str(argv[0], "echo", 4) == 0)
		echo(argc, argv, envp);
	else if (compare_str(argv[0], "cd", 2) == 0)
		cd(argc, argv, envp, env_list);
	else if (compare_str(argv[0], "pwd", 3) == 0)
		pwd(argc, argv, envp);
	else if (compare_str(argv[0], "export", 6) == 0)
		export(argc, argv, envp, env_list);
	else if (compare_str(argv[0], "unset", 5) == 0)
		unset(argc, argv, envp, env_list);
	else if (compare_str(argv[0], "env", 3) == 0)
		env(argc, argv, envp, env_list);
	else if (compare_str(argv[0], "exit", 4) == 0)
		built_in_exit(argc, argv, envp);
	else
		return (-1);
	return (0);
}
