/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:27:57 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/23 02:29:50 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd(t_ASTNode *node, t_list *env_list)
{
	int		res;
	char	*path;
	t_env	*env_home;

	if (!node->value[1])
	{
		env_home = find_by_key(env_list, "HOME");
		path = env_home->value;
	}
	else
		path = &node->value[1];
	res = chdir(path);
	if (res == -1)
		printf("error\n");
}
