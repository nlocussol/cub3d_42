/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tok.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:39:50 by averdon           #+#    #+#             */
/*   Updated: 2022/11/28 17:46:48 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TOK_H
# define FT_TOK_H

# include<stdlib.h>

typedef struct s_tok
{
	char			*token;
	int				type;
	struct s_tok	*prev;
	struct s_tok	*next;
}			t_tok;

void			ft_tokadd_back(t_tok **lst, t_tok *new);
void			ft_tokadd_front(t_tok **lst, t_tok *new);
void			ft_tokclear(t_tok **lst, void (*del)(char*));
void			ft_tokdelone(t_tok *lst, void (*del)(char*));
t_tok			*ft_toklast(t_tok *lst);
t_tok			*ft_toknew(char *content, int type);
int				ft_toksize(t_tok *list);

#endif
