/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astree.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 07:41:28 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/25 16:10:34 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTREE_H
# define ASTREE_H
# include "token.h"
# include "libft.h"
# include "structure.h"

int			astree(t_mini *mini, t_token *tokens);
void		print_ast(t_ASTNode *mini, int level);

// utiles
int			is_redirect(t_token *token);
t_ASTNode	*create_node(int type, char *value);
int			add_redirection(t_ASTNode *command_node, t_token **token);
int			add_argument(t_ASTNode *command_node, t_token *token, int *cmd_set);

void		free_cmd(t_cmd *cmd);
void		free_ast(t_ASTNode *node);

int			astree_counter(t_ASTNode *node);

// cmd
void		new_cmd(t_ASTNode *node);

#endif