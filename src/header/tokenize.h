/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:26:42 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/18 14:56:58 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_H
# define TOKENIZE_H
# include <stdlib.h>
# include "token.h"
# include "libft.h"
# include <stdio.h>

void tokenize(t_token **token_lst, char *line);

// tokenize_dollar
int	tokenize_expend(t_token *token_lst, t_token *token);

// token lst
void	add_token(t_token **token_lst, t_token *token);
t_token	*new_token(char *line, int l, int r);
t_token	*token_lst_back(t_token *token_lst);
void	token_lst_free(t_token **token_lst);
void	token_free(t_token *token);

// utils
int	is_quotation_str(char *str, int l, int r);
int	is_delimiter(char c);
int	ft_strcmp(const char *s1, char *s2);
int	get_token_type(const char *str);

// dollar 
int	tokenize_expend(t_token **token_lst, t_token *token);

#endif