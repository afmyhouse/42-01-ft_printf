/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_fwp2s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:13:52 by antoda-s          #+#    #+#             */
/*   Updated: 2023/01/17 13:21:25 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**********ft_pf_fwp2s.c**********/
/// @brief 		add left padding zeros if number length < precision
/// @param f 	struct with PRECISION information
/// @param ds 	char string with arg to format with PRECISION chars
/// @param i 	index of last element ds[i]
/// @return 	new last element of ds string if changed
int	ft_pf_fwp_p2s(t_printf *f, char *ds, int i)
{
	char	type;

	if ((*f).p_dot)
	{
		type = (*f).at;
		if (type != 'f')
			(*f).f_zpad = ' ';
		if (ds[i - 1] == '0' && !(*f).p_num)
			return (0);
		else if (type != 's' && type != 'c')
		{
			while (i < (*f).p_num)
				ds[i++] = '0';
		}
	}
	return (i);
}

/// @brief 		add RIGHT ALIGN + WIDTH, (fill with ZERO or SPACE)
/// @param f 	struct with WIDTH, PAD  or LEADING information
/// @param ds 	char string with arg to format with LEADING chars
/// @param i 	index of last element ds[i]
/// @return 	if ds is changed, index of the new last element ds[i]
int	ft_pf_fwp_war2s(t_printf *f, char *ds, int i)
{
	int		j;
	char	type;

	type = (*f).at;
	j = i;
	if ((type == 'i' || type == 'd' || type == 'f' || type == 'F' || \
		type == 'e' || type == 'E' || type == 'p') && (*f).f_stype)
		ds[j++] = (*f).f_stype;
	if ((*f).f_hash && (type == 'x' || type == 'X' || type == 'o' || \
		type == 'a' || type == 'A'))
	{
		j = ft_pf_fwp_hash2s(f, ds, i);
		if ((type == 'a' || type == 'A' || type == 'p') && (*f).f_stype)
			ds[j++] = (*f).f_stype;
		if ((*f).f_zpad == '0')
			ds = ft_pf_tools_strrev(ds + i, j) - i;
	}
	while (j < (*f).w_num)
		ds[j++] = (*f).f_zpad;
	if ((*f).f_zpad == '0')
		ds = ft_pf_tools_strrev(ds + i, j) - i;
	ds = ft_pf_tools_strrev(ds, j);
	return (0);
}

/// @brief 		(for integers) add LEFT ALIGN + WIDTH, (fill with SPACE)
/// @param f 	struct with WIDTH, PAD information
/// @param ds 	char string with arg to format with LEADING chars
/// @param i 	index of last element ds[i]
/// @return 	if ds is changed, index of the new last element ds[i]
int	ft_pf_fwp_wal2s(t_printf *f, char *ds, int i)
{
	char	type;

	type = (*f).at;
	(*f).f_zpad = ' ';
	if ((type == 'i' || type == 'd' || type == 'f' || type == 'F' || \
		type == 'e' || type == 'E' || type == 'p') && (*f).f_stype)
		ds[i++] = (*f).f_stype;
	if ((*f).f_hash)
		i = ft_pf_fwp_hash2s(f, ds, i);
	if ((type == 'a' || type == 'A') && (*f).f_stype)
		ds[i++] = (*f).f_stype;
	ds = ft_pf_tools_strrev(ds, i);
	while (i < (*f).w_num)
		ds[i++] = (*f).f_zpad;
	return (0);
}

/// @brief 		add HASH format to string ds
/// @param f 	struct with WIDTH, PAD  or LEADING information
/// @param ds 	char string with arg to format with LEADING chars
/// @param i 	index of last element ds[i]
/// @return 	if ds is changed, index of the new last element ds[i]
int	ft_pf_fwp_hash2s(t_printf *f, char *ds, int i)
{
	if ((*f).at == 'x' || (*f).at == 'X')
	{
		ds[i++] = (*f).at;
		ds[i++] = '0';
	}
	else if ((*f).at == 'p')
	{
		ds[i++] = 'x';
		ds[i++] = '0';
	}
	else if ((*f).at == 'a' || (*f).at == 'A')
	{
		ds[i++] = (*f).at + 23;
		ds[i++] = '0';
	}
	else if ((*f).at == 'o' && ds[i - 1] != '0')
		ds[i++] = '0';
	return (i);
}

/// @brief 		the ultimate function that outputs the string
/// @param f	struct with printf format info
/// @param res	the string to printf
void	ft_pf_write(t_printf *f, char *res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		write(1, &res[i++], 1);
		(*f).pf_len++;
	}
	return ;
}
