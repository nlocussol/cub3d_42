/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:03:55 by averdon           #+#    #+#             */
/*   Updated: 2022/11/01 18:03:25 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

char	*ft_strdup_gnl_bonus(const char *s)
{
	char	*duplicate_string;
	int		i;
	int		size_s;

	if (!s)
		return (NULL);
	size_s = 0;
	size_s = ft_strlen(s) + 1;
	duplicate_string = ft_calloc(size_s, sizeof(char));
	if (!duplicate_string)
		return (NULL);
	i = 0;
	while (i < size_s)
	{
		duplicate_string[i] = s[i];
		if (s[i] == '\n')
		{
			duplicate_string[i + 1] = '\0';
			break ;
		}
		i++;
	}
	return (duplicate_string);
}

static char	*concatenate_string(char *dest, const char *src)
{
	int	len_dest;
	int	i;

	if (!dest[0])
		len_dest = 0;
	else
		len_dest = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[len_dest + i] = src[i];
		if (src[i] == '\n')
			break ;
		i++;
	}
	return (dest);
}

char	*ft_strjoin_gnl_bonus(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	char	*new_s;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new_s = ft_calloc(len_s1 + len_s2 + 2, sizeof(char));
	if (!new_s)
		return (NULL);
	concatenate_string(new_s, s1);
	if (new_s[ft_strlen(new_s)] == '\n')
	{
		new_s[ft_strlen(new_s) + 1] = '\0';
		return (new_s);
	}
	concatenate_string(new_s, s2);
	if (new_s[ft_strlen(new_s)] == '\n')
	{
		new_s[ft_strlen(new_s) + 1] = '\0';
		return (new_s);
	}
	new_s[len_s1 + len_s2] = '\0';
	return (new_s);
}
