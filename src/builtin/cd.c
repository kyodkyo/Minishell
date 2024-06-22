/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:27:57 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/22 17:19:51 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd(t_cmd *cmd_list, t_list *env_list)
{
	int		res;
	char	*path;
	t_env	*env_home;

	if (!cmd_list->str[1])
	{
		env_home = find_by_key(env_list, "HOME");
		path = env_home->value;
	}
	else
		path = cmd_list->str[1];
	res = chdir(path);
	if (res == -1)
		printf("error\n");
}
