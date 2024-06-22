/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astree.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 07:41:28 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/18 02:23:31 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTREE_H
# define ASTREE_H
# include "token.h"
# include "libft.h"

typedef struct	s_ASTNode
{
	int					type;
	char				*value; // filename, cmd, arg, 등
	struct	s_ASTNode	*left;
	struct	s_ASTNode	*right;
	struct	s_ASTNode	*next;
} t_ASTNode;

t_ASTNode	*astree(t_token *tokens);
void print_ast(t_ASTNode *node, int level);
void free_ast(t_ASTNode *node);

#endif