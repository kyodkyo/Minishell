/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:28:45 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/19 16:31:37 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "utils.h"

void	echo(int argc, char **argv, char **envp)
{
	int	i;
	int	option;

	i = 1;
	option = 0;
	if (argc > 1 && compare_str(argv[1], "-n", 2) == 0)
	{
		i++;
		option = 1;
	}
	while (argv[i])
	{
		write(1, argv[i], ft_strlen(argv[i]));
		if (argv[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (!option)
		write(1, "\n", 1);
}
