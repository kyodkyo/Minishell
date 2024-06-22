/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:26:42 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/22 15:14:22 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_H
# define TOKENIZE_H

# include "minishell.h"
# include "token.h"
# include "utils.h"

void	tokenize(t_mini *mini, t_token **token_lst, char *line);

// token lst
void	add_token(t_token **token_lst, t_token *token);
t_token	*new_token(char *line, int l, int r);
t_token	*token_lst_back(t_token *token_lst);
void	token_lst_free(t_token **token_lst);
void	token_free(t_token *token);

// utils
int		is_quotation_str(char *str, int l, int r);
int		is_delimiter(char c);
int		ft_strcmp(const char *s1, char *s2);
int		get_token_type(const char *str);

// dollar 
int	tokenize_expend(t_mini *mini, t_token **token_lst, t_token *token);

#endif