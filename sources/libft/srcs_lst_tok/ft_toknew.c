/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_lstnew.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 09:38:09 by averdon           #+#    #+#             */
/*   Updated: 2022/10/19 18:45:05 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_tok.h"

t_tok	*ft_toknew(char *content, int type)
{
	t_tok	*new_element;

	new_element = malloc(sizeof(t_tok));
	if (!new_element)
		return (NULL);
	new_element->token = content;
	new_element->type = type;
	new_element->next = NULL;
	new_element->prev = NULL;
	return (new_element);
}
