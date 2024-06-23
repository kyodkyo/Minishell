/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:32:56 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/23 21:48:26 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	unset(t_ASTNode *node, t_list *env_list)
{
	int		i;
	char	*target_key;

	i = 1;
	if (!node->cmd->argv[1])
		return ;
	while (node->cmd->argv[i])
	{
		target_key = node->cmd->argv[i];
		if (is_valid_key(node->cmd->argv[i]))
			write(1, "unset: invalid key", 18);
		else
			unset_env(&env_list, target_key);
		i++;
	}
}
