/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:13:52 by antoda-s          #+#    #+#             */
/*   Updated: 2023/01/15 15:47:30 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**********ft_pf_printf.c**********/
/// @brief			all starts here: the ft_printf
/// @param format	the string to printf format
/// @return			the #chars prined
int	ft_printf(const char *format, ...)
{
	int			pf_len;
	t_printf	*f;

	f = (t_printf *)malloc(sizeof(t_printf));
	if (!f)
		return (0);
	(*f).pf_len = 0;
	va_start((*f).args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				(*f).pf_len += write(1, format++, 1);
			else
				format = ft_pf_type(f, format) + 1;
		}
		else
			(*f).pf_len += write(1, format++, 1);
	}
	va_end((*f).args);
	pf_len = (*f).pf_len;
	free(f);
	return (pf_len);
}

/// @brief 		sslection of the printf formating option
/// @param f 	struct with formating options and arg type info
/// @param s 	string to format
/// @return 	the string at a new position
const char	*ft_pf_type(t_printf *f, const char *s)
{
	char	a;

	s = ft_pf_all2f(f, s);
	a = (*f).at;
	if (a == 'i' || a == 'd' || a == 'u' || a == 'o' || a == 'x' || a == 'X')
		ft_pf_type_iduox(f);
	else if (a == 'f' || a == 'a' || a == 'A' || \
	a == 'e' || a == 'E' || a == 'g' || a == 'G')
		ft_pf_type_fega(f);
	else if (a == 's' || a == 'c' || a == 'p' )
	{
		(*f).f_zpad = ' ';
		if (a == 's')
			ft_pf_type_s(f);
		else if (a == 'c' )
			ft_pf_type_c(f);
		else if (a == 'p')
			ft_pf_type_p(f);
	}
	else if (a == 'n')
		ft_pf_type_n(f);
	return (s);
}

/// @brief 		initialize with neutral printing format info
/// @param f 	struct where the printing format is stored
void	ft_pf_f_init(t_printf *f)
{
	(*f).f_hash = 0;
	(*f).f_align = 0;
	(*f).f_stype = '\0';
	(*f).f_zpad = ' ';
	(*f).w_num = 0;
	(*f).p_dot = 0;
	(*f).p_num = 0;
	(*f).e_sign = '+';
	(*f).e_val = 0;
	(*f).e_symb = 'e';
	(*f).e_radix = 10;
	(*f).arg_len1 = '\0';
	(*f).arg_len2 = '\0';
	(*f).at = '\0';
	(*f).arg_zero = 0;
	(*f).res_len = 0;
	return ;
}
