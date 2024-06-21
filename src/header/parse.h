/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 00:36:29 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/18 01:31:53 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PARSE_H
# define PARSE_H
# include <stdlib.h>
# include <stdio.h>
# include "tokenize.h"
# include "astree.h"

t_token	*parse(char *input);

#endif