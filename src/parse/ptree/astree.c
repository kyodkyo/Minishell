/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 07:42:06 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/22 19:23:20 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astree.h"
#include <stdio.h>


int is_redirect(t_token *token) {
	if (token->type == T_REDIR_IN || token->type == T_REDIR_OUT ||
		token->type == T_REDIR_APPEND || token->type == T_REDIR_HERE ||
		token->type == T_REDIR_ERR)
		return 1;
	return 0;
}

t_ASTNode *parse_command(t_token **current_token) {
	t_ASTNode *command_node = (t_ASTNode *)ft_calloc(1, sizeof(t_ASTNode));
	command_node->type = T_CMD;
	command_node->value = NULL;
	command_node->left = NULL;
	command_node->right = NULL;

	t_ASTNode *arg_node = NULL;
	t_ASTNode *redir_node = NULL;

	t_token *token = *current_token;
	int cmd_set = 0;  // 명령어가 설정되었는지 여부

	while (token && token->type != T_PIPE) {
		if (is_redirect(token)) {
			redir_node = (t_ASTNode *)ft_calloc(1, sizeof(t_ASTNode));
			redir_node->type = token->type;
			token = token->next;
			if (token == NULL)
				exit(1);
			redir_node->value = token->str;
			redir_node->left = NULL;
			redir_node->right = NULL;

			redir_node->left = command_node->left;
			command_node->left = redir_node;
			// t_ASTNode *current_redirect = command_node;
			// while (current_redirect->left)
			// 	current_redirect = current_redirect->left;
			// current_redirect->left = redir_node;

		} else {
			arg_node = (t_ASTNode *)ft_calloc(1, sizeof(t_ASTNode));
			arg_node->type = T_ARG;
			arg_node->value = token->str;
			arg_node->left = NULL;
			arg_node->right = NULL;

			if (command_node->right == NULL) {
				command_node->right = arg_node;
			} else {
				t_ASTNode *current_arg = command_node->right;
				while (current_arg->next) {
					current_arg = current_arg->next;
				}
				current_arg->next = arg_node;
			}

			if (!cmd_set) {
				command_node->value = token->str;
				cmd_set = 1;
			}
		}
		*current_token = token->next;
		token = *current_token;
	}
	return command_node;
}

t_ASTNode *parse_pipeline(t_token **current_token) {
	t_ASTNode *left_command = parse_command(current_token);
	t_ASTNode *pipe_node;

	while (*current_token && (*current_token)->type == T_PIPE) {
		pipe_node = (t_ASTNode *)ft_calloc(1, sizeof(t_ASTNode));
		pipe_node->type = T_PIPE;
		pipe_node->left = left_command;
		pipe_node->right = NULL;

		*current_token = (*current_token)->next;
		pipe_node->right = parse_command(current_token);
		left_command = pipe_node;
	}

	return left_command;
}

t_ASTNode *astree(t_token *tokens) {
	t_token *current_token = tokens;
	return parse_pipeline(&current_token);
}

void print_ast(t_ASTNode *node, int level) {
	if (!node) return;
	for (int i = 0; i < level; i++)
		printf("  ");
	printf("Type: %d, Value: %s\n", node->type, node->value);

	if (node->left) {
		printf("Left:\n");
		print_ast(node->left, level + 1);
	}

	if (node->right) {
		printf("Right:\n");
		print_ast(node->right, level + 1);
	}

	if (node->next) {
		printf("Next:\n");
		print_ast(node->next, level + 1);
	}
}

// 메모리 해제 함수
void free_ast(t_ASTNode *node) {
}

void free_tokens(t_token *tokens) {
	while (tokens) {
		t_token *next = tokens->next;
		free(tokens->str);
		free(tokens);
		tokens = next;
	}
}