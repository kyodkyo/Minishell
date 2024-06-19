/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:27:57 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/19 16:31:22 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "utils.h"

void	cd(int argc, char **argv, char **envp, t_list *env_list)
{
	int		res;
	char	*path;
	t_env	*env_home;

	if (argc == 1)
	{
		env_home = find_by_key(env_list, "HOME");
		path = env_home->value;
	}
	else
		path = argv[1];
	res = chdir(path);
	if (res == -1)
		printf("error\n");
}
