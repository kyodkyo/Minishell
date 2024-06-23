/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:27:57 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/23 17:18:10 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd(t_ASTNode *node, t_list *env_list)
{
	int		res;
	char	*path;
	t_env	*env_home;

	if (node->cmd->argc > 2)
		printf("error\n");
	if (!node->cmd->argv[1])
	{
		env_home = find_by_key(env_list, "HOME");
		path = env_home->value;
	}
	else
		path = node->cmd->argv[1];
	res = chdir(path);
	if (res == -1)
		printf("error\n");
}
