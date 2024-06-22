/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:28:45 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/23 02:29:52 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo(t_ASTNode *node, t_io *io_handler)
{
	int	i;
	int	option;

	i = 1;
	option = 0;
	if (&node->value[1] && compare_str(&node->value[1], "-n", 2) == 0)
	{
		i++;
		option = 1;
	}
	while (node->value[i])
	{
		write(io_handler->output_fd, &node->value[i],
			ft_strlen(&node->value[i]));
		if (&node->value[i + 1])
			write(io_handler->output_fd, " ", 1);
		i++;
	}
	if (!option)
		write(io_handler->output_fd, "\n", 1);
}
