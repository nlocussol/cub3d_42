/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:16:59 by averdon           #+#    #+#             */
/*   Updated: 2022/11/26 15:21:44 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDPRINTF_H
# define FT_FDPRINTF_H

# include<stdarg.h>
# include<unistd.h>
# include<stdlib.h>
# include"../libft.h"

void	ft_put_unbr(int fd, unsigned long nbr, char *base, int *n);
void	ft_putnbr_hex(int fd, int nbr, char *base, int *n);
void	ft_putnbr_dec(int fd, int nbr, int *n);
int		ft_fdprintf(int fd, const char *str, ...);
long	ft_iterative_power(int nb, int power);
void	ft_check_pointer(int fd, unsigned long nbr, char *base, int *n);

#endif
