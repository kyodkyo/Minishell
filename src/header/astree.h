/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astree.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 07:41:28 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/24 19:18:42 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTREE_H
# define ASTREE_H
# include "token.h"
# include "libft.h"
# include "structure.h"

int			astree(t_mini *mini, t_token *tokens);
void		print_ast(t_ASTNode *mini, int level);
void		free_ast(t_ASTNode *node);

// utiles
int			is_redirect(t_token *token);
t_ASTNode	*create_node(int type, char *value);
int			add_redirection(t_ASTNode *command_node, t_token **token);
int			add_argument(t_ASTNode *command_node, t_token *token, int *cmd_set);
void		free_ast(t_ASTNode *node);

int			astree_counter(t_ASTNode *node);

// cmd
void	new_cmd(t_ASTNode *node);

#endif