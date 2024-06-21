/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:18:10 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/18 13:39:22 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	main(int argc, char **argv, char **envp)
{
	char	*input;
	t_token	*token_lst;

	while (1)
	{
		input = readline("minishell> ");
		if (input)
			token_lst = parse(input);
		else
			break ;
		free(input);

		// 실행
	}
	return (0);
}
