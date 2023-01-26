/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_lstdelone.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:53:21 by averdon           #+#    #+#             */
/*   Updated: 2022/10/19 18:45:11 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_tok.h"

void	ft_tokdelone(t_tok *lst, void (*del_tok)(char*))
{
	if (!lst || !del_tok)
		return ;
	del_tok(lst->token);
	free(lst);
}
