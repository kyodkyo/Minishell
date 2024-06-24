/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astree_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:13:58 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/24 16:19:33 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astree.h"

int	astree_counter(t_ASTNode *node)
{
	int	count;

	if (node == NULL)
		return (0);
	count = 0;

	if (node->type == T_PIPE)
	{
		count += 1;
		count += astree_counter(node->left);
		count += astree_counter(node->right);
	}
	else
		count += 1;
	return (count);
}