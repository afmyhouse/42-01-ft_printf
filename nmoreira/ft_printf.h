/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:29:33 by nmoreira          #+#    #+#             */
/*   Updated: 2022/11/21 13:29:39 by nmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printformat(va_list args, const char f);
int		ft_printf(const char *str, ...);

int		ft_lenhex(unsigned int nbr);
void	ft_writehex(unsigned int nbr, const char f);
int		ft_printhex(unsigned int nbr, const char f);

int		ft_lenint(int n);
char	*ft_itoa(int nbr);
int		ft_printnbr(int nbr);

int		ft_lenptr(unsigned long long nbr);
void	ft_writeptr(unsigned long long nbr);
int		ft_printptr(void *ptr);

int		ft_lenuint(unsigned int nbr);
char	*ft_uitoa(unsigned int nbr);
int		ft_printuint(unsigned int nbr);

int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_printperc(char c);

#endif
