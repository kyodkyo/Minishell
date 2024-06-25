/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:26:42 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/25 20:41:20 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_H
# define TOKENIZE_H

# include "structure.h"
# include "token.h"
# include "utils.h"

typedef struct s_tokenize_iter
{
	int	left;
	int	right;
	int	in_single_quote;
	int	in_double_quote;
}	t_token_iter;

int		tokenize(t_mini *mini, t_token **token_lst, char *line);

void	add_token(t_token **token_lst, t_token *token);
t_token	*new_token(char *line, int l, int r);
t_token	*token_lst_back(t_token *token_lst);
void	token_lst_free(t_token **token_lst);
void	token_free(t_token *token);

int		is_quotation_str(char *str, int l, int r);
int		is_delimiter(char c);
int		ft_strcmp(const char *s1, char *s2);
int		get_token_type(const char *str);

int		tokenize_expend(t_mini *mini, t_token **token_lst, t_token *token);
void	tokenize_remove_quotes(t_token *token_lst);

#endif