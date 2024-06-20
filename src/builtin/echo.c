/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:28:45 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/21 02:22:13 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_t.h"

void	echo(t_cmd *cmd_list, t_io *io_handler)
{
	int	i;
	int	option;

	i = 1;
	option = 0;
	if (cmd_list->str[1] && compare_str(cmd_list->str[1], "-n", 2) == 0)
	{
		i++;
		option = 1;
	}
	while (cmd_list->str[i])
	{
		write(io_handler->output_fd, cmd_list->str[i],
			ft_strlen(cmd_list->str[i]));
		if (cmd_list->str[i + 1])
			write(io_handler->output_fd, " ", 1);
		i++;
	}
	if (!option)
		write(io_handler->output_fd, "\n", 1);
}
