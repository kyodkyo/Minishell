/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:27:15 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/06 01:59:06 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

int	built_in(int argc, char **argv, char **envp)
{
	t_list	*env_list;

	if (!argv[0])
		return (-1);
	env_list = init_envp(envp);
	if (ft_strncmp(argv[0], "echo", 4) == 0)
		echo(argc, argv, envp);
	else if (ft_strncmp(argv[0], "cd", 2) == 0)
		cd(argc, argv, envp, env_list);
	else if (ft_strncmp(argv[0], "pwd", 3) == 0)
		pwd(argc, argv, envp);
	else if (ft_strncmp(argv[0], "export", 6) == 0)
		export(argc, argv, envp, env_list);
	else if (ft_strncmp(argv[0], "unset", 5) == 0)
		unset(argc, argv, envp, env_list);
	else if (ft_strncmp(argv[0], "env", 3) == 0)
		env(argc, argv, envp, env_list);
	else if (ft_strncmp(argv[0], "exit", 4) == 0)
		built_in_exit(argc, argv, envp);
	else
		return (-1);
	return (0);
}

void	error()
{
	printf("error");
}