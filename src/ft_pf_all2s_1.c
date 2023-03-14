/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_all2s_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:13:52 by antoda-s          #+#    #+#             */
/*   Updated: 2023/01/12 01:42:51 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**********ft_pf_all2s_1.c**********/
/// @brief		convert number to equivalent string char with radix
/// @param f	the struct with the arg type
/// @param n	the number to convert
/// @param str 	the string to fill with result
/// @return		number of chars added to the string
int	ft_pf_tools_d2s(t_printf *f, unsigned int n, char *str)
{
	int	i;
	int	base;

	i = 0;
	base = ft_pf_tools_radix((*f).at);
	while (i < (*f).p_num)
	{
		str[i++] = ft_pf_tools_d2c((char)(n % base), (*f).at);
		n = n / base;
	}
	return (i);
}

/// @brief		convert number to equivalent string char with radix
/// @param f	the struct with the arg type
/// @param n	the number to convert
/// @param str 	the string to fill with result
/// @return		number of chars added to the string
int	ft_pf_tools_i2s(char arg_type, unsigned int n, char *str)
{
	int	i;
	int	base;

	i = 0;
	base = ft_pf_tools_radix(arg_type);
	if (!n)
		str[i++] = '0';
	while (n)
	{
		str[i++] = ft_pf_tools_d2c((char)(n % base), arg_type);
		n = n / base;
	}
	return (i);
}

/// @brief 		converts a float to a string
/// @param f 	struct with the flags (*f).args and (*f).arg_type
/// @param res 	pointer to string to write the char sequence result
/// @return		the number pf chars of the result
int	ft_pf_tools_f2s(t_printf *f, char *str)
{
	int			i;
	long double	arg;
	char		*arg_arr;

	arg_arr = (char *)ft_calloc((35), sizeof(char));
	if (!arg_arr)
		return (-1);
	arg = (va_arg((*f).args, double));
	ft_pf_type_fega_flags(f);
	ft_pf_fwp_u(f, &arg);
	i = ft_pf_tools_f2s_power(f, arg_arr, str, &arg);
	if ((*f).at == 'f')
		i = ft_pf_tools_f2s_mantissa(f, i, arg_arr, str);
	else if ((*f).at == 'a' || (*f).at == 'A' || \
				(*f).at == 'e' || (*f).at == 'E')
	{
		i += ft_pf_tools_f2s_mantissa(f, 1, arg_arr, str + i);
		(*f).f_hash = 1;
	}
	free(arg_arr);
	return (i);
}

/// @brief 		calculates the base 10 power of 'e'|'E' printf format
/// @param f
/// @param str
/// @param arg
/// @return
int	ft_pf_tools_f2s_power(t_printf *f, char *arg_arr, char *str, void *arg)
{
	int		i;
	char	base;

	base = ft_pf_tools_radix((*f).at);
	if (arg)
		ft_pf_tools_f2s_exp(f, arg);
	i = ft_pf_tools_f2s_fill_arr(base, arg_arr, arg);
	i = ft_pf_tools_f2s_round(f, i, arg_arr);
	if ((*f).at == 'f')
		return ((*f).e_val + arg_arr[0]);
	else
	{
		(*f).e_val -= !arg_arr[0];
		if ((*f).e_val < 0)
		{
			(*f).e_val *= -1;
			(*f).e_sign = '-';
		}
		i = ft_pf_tools_i2s('d', (*f).e_val, str);
		if (((*f).e_val < 10) && ((*f).e_radix == 10))
			str[i++] = '0';
		str[i++] = (*f).e_sign;
		str[i++] = (*f).e_symb;
	}
	return (i);
}

/// @brief 		calculates the exponent|comma value for e|E|a|A printf formats
/// @param f 	formats and flags
/// @param arg 	float argument to apply function
void	ft_pf_tools_f2s_exp(t_printf *f, long double *arg)
{
	if ((*f).at != 'f')
	{
		while (*arg < 1)
		{
			*arg *= (*f).e_radix;
			(*f).e_val--;
		}
	}
	while (((*f).e_radix == 10 && *arg >= 1) || \
			((*f).e_radix == 2 && *arg >= 2))
	{
		*arg /= (*f).e_radix;
		(*f).e_val++;
	}
}
