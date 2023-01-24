/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_pf_type_numbers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:13:52 by antoda-s          #+#    #+#             */
/*   Updated: 2023/01/19 10:25:11 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**********ft_pf_type_numbers.c**********/
/// @brief 		selection of the type of float into a string conversion
/// @param f 	struct containing the format parameters and the float
void	ft_pf_type_fega(t_printf *f)
{
	char	t;
	size_t	i;
	char	*res;

	res = (char *)ft_calloc((60 + (*f).w_num), sizeof(char));
	if (!res)
		return ;
	t = (*f).at;
	if (t == 'f' || t == 'a' || t == 'A' || t == 'e' || t == 'E')
		i = ft_pf_tools_f2s(f, res);
	else if (t == 'g' || t == 'G')
		ft_pf_type_g(f);
	if ((*f).f_align)
		i = ft_pf_fwp_wal2s(f, res, i);
	else
		i = ft_pf_fwp_war2s(f, res, i);
	while (res[i])
	{
		write(1, &res[i++], 1);
		(*f).pf_len++;
	}
	free(res);
	return ;
}

/// @brief 		sets value of the flags and symbols for float conversion
/// @param f 	struct with the flags varaiables
void	ft_pf_type_fega_flags(t_printf *f)
{
	char	type;

	type = (*f).at;
	(*f).e_sign = '+';
	(*f).e_radix = 10;
	if (type == 'a' || type == 'A')
	{
		(*f).e_radix = 2;
		(*f).e_symb = type + 15;
	}
	else if (type == 'e' || type == 'E')
		(*f).e_symb = type;
	else if (type == 'g' || type == 'G')
		(*f).e_symb = type - 2;
	return ;
}

/// @brief 		converts a float into a string or exponent string
/// @param f 	struct containing the format parameters and the float
void	ft_pf_type_g(t_printf *f)
{
	(*f).at = 'g';
	return ;
}

/// @brief 		convert an integer into a string
/// @param f 	struct containing the format parameters and the integer
/// @return 	???
void	ft_pf_type_iduox(t_printf *f)
{
	size_t	i;
	int		arg;
	char	*res;

	res = (char *)ft_calloc((60 + (*f).w_num), sizeof(char));
	if (!res)
		return ;
	arg = (int)(va_arg((*f).args, int));
	if ((*f).at == 'i' || (*f).at == 'd')
		ft_pf_fwp_u(f, &arg);
	if ((!arg) && ((*f).at == 'x' || (*f).at == 'X'))
		(*f).f_hash = 0;
	i = ft_pf_tools_i2s((*f).at, (int)arg, res);
	i = ft_pf_fwp_p2s(f, res, i);
	if ((*f).f_align)
		i = ft_pf_fwp_wal2s(f, res, i);
	else
		i = ft_pf_fwp_war2s(f, res, i);
	while (res[i])
	{
		write(1, &res[i++], 1);
		(*f).pf_len++;
	}
	free(res);
}

/// @brief 		saves thea = printf lenght into a pointer address
/// @param f 	struct containing the format parameters and the float
void	ft_pf_type_n(t_printf *f)
{
	int	*p;

	p = va_arg((*f).args, int *);
	*p = (*f).pf_len;
}
