/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:32:46 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/21 02:22:25 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_t.h"

void	pwd(t_io *io_handler)
{
	char	*current;

	current = getcwd(NULL, 0);
	if (current)
	{
		write(io_handler->output_fd, current, ft_strlen(current));
		write(io_handler->output_fd, "\n", 1);
	}
	else
		printf("error\n");
	free(current);
}
