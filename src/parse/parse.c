/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 00:34:07 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/22 15:09:46 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdio.h>

t_token	*parse(t_mini *mini, char *input)
{
	t_token	*token_lst;
	t_token	*tmp;
	t_ASTNode *ast;

	token_lst = NULL;
	tokenize(mini, &token_lst, input);
	tmp = token_lst;
	while (tmp)
	{
		printf("%d %s -> ", tmp->type, tmp->str);
		tmp = tmp->next;
	}
	printf("\n");
	
	ast = astree(token_lst);
	print_ast(ast, 0);

	free_ast(ast);

	return (token_lst);
}
