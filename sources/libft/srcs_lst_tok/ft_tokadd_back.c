/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_lstadd_back.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:49:03 by averdon           #+#    #+#             */
/*   Updated: 2022/10/19 18:44:13 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_tok.h"

void	ft_tokadd_back(t_tok **lst, t_tok *new)
{
	t_tok	*buffer;

	if (!lst)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	buffer = *lst;
	while (buffer->next != NULL)
		buffer = buffer->next;
	buffer->next = new;
	new->prev = buffer;
}
