/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_lstclear.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:08:08 by averdon           #+#    #+#             */
/*   Updated: 2022/11/02 16:48:26 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_tok.h"

void	ft_tokclear(t_tok **lst, void (*del_tok)(char*))
{
	t_tok	*buffer;
	t_tok	*next;

	if (!lst || !del_tok)
		return ;
	buffer = *lst;
	while (buffer != NULL)
	{
		next = buffer->next;
		ft_tokdelone(buffer, del_tok);
		buffer = next;
	}
	(*lst) = NULL;
}
