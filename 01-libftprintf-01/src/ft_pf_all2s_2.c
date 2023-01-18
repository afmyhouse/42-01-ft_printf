/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_all2s_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:13:52 by antoda-s          #+#    #+#             */
/*   Updated: 2023/01/18 15:14:20 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**********ft_pf_all2s_2.c**********/
/// @brief 		initilize float into array
/// @param base 	radix to be represented in printf fprmat f|a|e|g
/// @param arg_arr 	array to save the float the base number digits
/// @param arg 		float number
/// @return 		the total number of digits
int	ft_pf_tools_f2s_fill_arr(char base, char *arg_arr, void *arg)
{
	int			k;
	long double	ld_arg;

	k = 0;
	ld_arg = (*(long double *)arg);
	while ((k < 35 && ld_arg))
	{
		arg_arr[k] = (char)ld_arg;
		ld_arg = ld_arg - (unsigned long)ld_arg;
		ld_arg = ld_arg * base;
		k++;
	}
	return (--k);
}

/// @brief 		calculates the rounding float after precision
/// @param f 	struct with round up parameters
/// @return 	carry flag contained at arg_arr[0]
int	ft_pf_tools_f2s_round(t_printf *f, int k, char *af)
{
	char	carry;
	char	b;
	int		e;

	carry = 0;
	b = ft_pf_tools_radix((*f).at);
	if (!(*f).p_dot && ((*f).at == 'f' || (*f).at == 'e' || ((*f).at == 'E')))
		(*f).p_num = 6;
	else if (!(*f).p_dot && ((*f).at == 'a' || (*f).at == 'A'))
		(*f).p_num = 13;
	e = ft_pf_tools_f2s_round_offset(f);
	k = (*f).p_num + e + 1;
	carry = (b == 10 && af[k] >= 5) + (b == 16 && af[k] >= 8);
	while ((--k >= 0) && carry)
	{
		af[k] += carry;
		if (af[k] < b)
			carry = 0;
		else
			af[k] %= b;
	}
	return (af[0]);
}

/// @brief 		selects the precision offset based on the float conversion type
/// @param f 	struct with conversion information
/// @return 	the precision offset
int	ft_pf_tools_f2s_round_offset(t_printf *f)
{
	int	precision_offset;

	precision_offset = (*f).e_val;
	if ((*f).at == 'a' || (*f).at == 'A')
		precision_offset = 0;
	else if ((*f).at == 'e' || (*f).at == 'E')
		precision_offset = 1;
	return (precision_offset);
}

/// @brief 		adds precision to the mantissa of a 'e'|'E' printf format
/// @param f	struct contains format parameters
/// @param str	string to save result
/// @param arg	float number to convert
/// @return		last empty  index of changed string str
int	ft_pf_tools_f2s_mantissa(t_printf *f, char dot, char *arg_arr, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!arg_arr[j] && dot)
		j++;
	else if (!arg_arr[j] && !dot)
		str[i++] = ft_pf_tools_d2c(arg_arr[j++], (char)((*f).at + 23));
	while (dot && (dot - i))
		str[i++] = ft_pf_tools_d2c(arg_arr[j++], (char)((*f).at + 23));
	if (((*f).p_num || (*f).f_hash))
		str[i++] = '.';
	while ((*f).p_num--)
		str[i++] = ft_pf_tools_d2c(arg_arr[j++], (char)((*f).at + 23));
	str = ft_pf_tools_strrev(str, i);
	return (i);
}
