/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:29:13 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/22 17:19:51 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env(t_list *env_list, t_io *io_handler)
{
	char	*data;

	while (env_list)
	{
		if (((t_env *)(env_list->content))->value)
		{
			data = ((t_env *)(env_list->content))->data;
			write(io_handler->output_fd, data, ft_strlen(data));
			write(io_handler->output_fd, "\n", 1);
		}
		env_list = env_list->next;
	}
}
