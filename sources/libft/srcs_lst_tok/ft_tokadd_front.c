/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_lstadd_front.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 09:58:27 by averdon           #+#    #+#             */
/*   Updated: 2022/10/20 16:04:46 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_tok.h"

void	ft_tokadd_front(t_tok **lst, t_tok *new)
{
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	new->prev = NULL;
	(*lst)->prev = new;
	*lst = new;
}
