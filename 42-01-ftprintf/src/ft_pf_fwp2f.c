/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_fwp2f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:13:52 by antoda-s          #+#    #+#             */
/*   Updated: 2023/01/12 02:22:02 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**********ft_pf_fwp2f.c**********/
/// @brief 		collects PRINTING FORMAT information froma = printf string
/// @param f 	struct where to store information about PRINTING FORMAT
/// @param s 	printf string
/// @return 	printf string last position
const char	*ft_pf_all2f(t_printf *f, const char *s)
{
	ft_pf_f_init(f);
	if (*s == '#' || *s == '-' || *s == ' ' || *s == '+' || *s == '0')
		s = ft_pf_f2f(f, s);
	if (ft_isdigit(*s) || *s == '*')
		s = ft_pf_w2f(f, s);
	if (*s == '.')
		s = ft_pf_p2f(f, s);
	s = ft_pf_l2f(f, s);
	(*f).at = *s;
	return (s);
}

/// @brief 		collects FORMAT FLAGS information froma = printf string
/// @param f 	struct where to store information about FORMAT FLAGS
/// @param s 	printf string
/// @return 	printf string last position
const char	*ft_pf_f2f(t_printf *f, const char *s)
{
	while (*s == '#' || *s == '-' || *s == ' ' || *s == '+' || *s == '0')
	{
		if (*s == '#')
			(*f).f_hash = 1;
		else if (*s == ' ' || *s == '+')
			(*f).f_stype = *s;
		else if (*s == '-')
		{
			(*f).f_align = 1;
			(*f).f_zpad = ' ';
		}
		else if (*s == '0' && !(*f).f_align)
			(*f).f_zpad = '0';
		s++;
	}
	return (s);
}

/// @brief 		collects WIDTH information froma = printf string
/// @param f 	struct where to store information about WIDTH
/// @param s 	printf string
/// @return 	printf string last position
const char	*ft_pf_w2f(t_printf *f, const char *s)
{
	while (ft_isdigit(*s))
		(*f).w_num = *s++ - 0x30 + (*f).w_num * 10;
	if (*s == '*')
	{
		s++;
		(*f).w_num = va_arg((*f).args, int);
		if ((*f).w_num < 0)
			(*f).w_num = 0;
	}
	return (s);
}

/// @brief 		collects PRECISION information froma = printf string
/// @param f 	struct where to store information about PRECISION
/// @param s 	printf string
/// @return 	printf string last position
const char	*ft_pf_p2f(t_printf *f, const char *s)
{
	s++;
	(*f).p_dot = 1;
	while (ft_isdigit(*s))
		(*f).p_num = *s++ - 0x30 + (*f).p_num * 10;
	if (*s == '*')
	{
		s++;
		(*f).p_num = va_arg((*f).args, int);
		if ((*f).p_num < 0)
			(*f).p_dot = 0;
	}
	return (s);
}

/// @brief 		collects LENGTH information froma = printf string
/// @param f 	struct where to store information about LENGTH
/// @param s 	printf string
/// @return 	printf string last position
const char	*ft_pf_l2f(t_printf *f, const char *s)
{
	if ((*s == 'l' || *s == 'h') && *s == *(s + 1))
	{
		(*f).arg_len1 = *s++;
		(*f).arg_len2 = *s++;
		return (s);
	}
	else if (*s == 'l' || *s == 'h' || *s == 'j' || \
			*s == 'z' || *s == 't' || *s == 'L')
		(*f).arg_len2 = *s++;
	return (s);
}
