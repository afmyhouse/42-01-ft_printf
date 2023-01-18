/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_type_scp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:13:52 by antoda-s          #+#    #+#             */
/*   Updated: 2023/01/17 13:20:10 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**********ft_pf_type_scpn.c**********/
/// @brief 		retrieve the string arg from va-args when arg is of type string
/// @param f 	struct witha = printf parameters
/// @return 	the string pointer
void	ft_pf_type_s(t_printf *f)
{
	int		i;
	char	*res;
	char	*ds;
	int		dl;

	ds = va_arg((*f).args, char *);
	dl = ft_strlen(ds);
	if (ds == NULL)
		dl = 6 * (((*f).p_dot && ((*f).p_num >= 6)) || !(*f).p_dot);
	else
		dl = ((*f).p_dot * (dl * ((*f).p_num >= dl)) + \
		(*f).p_num * (dl > (*f).p_num)) + !(*f).p_dot * dl;
	(*f).res_len = ((*f).w_num * ((*f).w_num >= dl) + dl * (dl > (*f).w_num));
	res = (char *)ft_calloc(((*f).res_len + 1), sizeof(char));
	if (!res)
		return ;
	i = ft_pf_type_s2s(f, res, ds, dl);
	res = ft_pf_tools_strrev(res, i);
	if ((*f).f_align)
		i = ft_pf_fwp_wal2s(f, res, i);
	else
		i = ft_pf_fwp_war2s(f, res, i);
	ft_pf_write(f, res);
	free(res);
	return ;
}

/// @brief 		post process for the s printf format
/// @param f	struct witha = printf parameters
/// @param res	destination string
/// @param ds	input string to "printf format"
/// @return		the last added element to print string
//int	ft_pf_type_s2s(t_printf *f, char *res, char *ds)
int	ft_pf_type_s2s(t_printf *f, char *res, char *ds, int ds_len)
{
	int	i;

	if (ds == NULL && !(*f).p_dot)
		i = ft_strlcpy(res, "(null)", 34);
	else if (ds == NULL && (*f).p_dot)
	{
		i = 0;
		if ((char)ft_strlen("(null)") <= (*f).p_num)
		{
			ft_strlcpy(res, "(null)", (ft_strlen("(null)") + 1));
			i = ft_strlen("(null)");
		}
	}
	else
	{
		ft_strlcpy(res, ds, (*f).res_len + 1);
		i = ds_len;
	}
	return (i);
}

/// @brief		printf type c
/// @param f	struct with the printf format
void	ft_pf_type_c(t_printf *f)
{
	int		i;
	char	c1;
	char	c2;

	i = 0;
	c1 = (char)va_arg((*f).args, int);
	c2 = c1;
	if ((*f).f_align)
	{
		write(1, &c1, 1);
		c1 = ' ';
		while (i++ < ((*f).w_num - 1))
			write(1, &c1, 1);
		(*f).pf_len += i;
	}
	else if (!(*f).f_align)
	{
		c1 = ' ';
		while (i++ < ((*f).w_num - 1))
			write(1, &c1, 1);
		(*f).pf_len += i;
		write(1, &c2, 1);
	}
	return ;
}

/// @brief 		converts a pointer address into a string
/// @param f 	struct containing the format parameters and the float
void	ft_pf_type_p(t_printf *f)
{
	int					i;
	char				*res;
	unsigned long long	arg;

	res = (char *)ft_calloc((34), sizeof(char));
	if (!res)
		return ;
	arg = (unsigned long long)va_arg((*f).args, void *);
	i = ft_pf_type_p2s(f, res, arg);
	if ((*f).f_align)
		i = ft_pf_fwp_wal2s(f, res, i);
	else
		i = ft_pf_fwp_war2s(f, res, i);
	ft_pf_write(f, res);
	free(res);
	return ;
}

/// @brief 		write pointer addres to a string of chars + 0x header
/// @param f	struct with printf format info
/// @param res	string to save result
/// @param arg	pointer address
/// @return		index of the last added item to res
int	ft_pf_type_p2s(t_printf *f, char *res, unsigned long long arg)
{
	int					i;
	int					base;

	i = 0;
	if (!arg)
	{
		i = ft_strlcpy(res, "(nil)", 34);
		res = ft_pf_tools_strrev(res, i);
	}
	else
	{
		base = ft_pf_tools_radix((*f).at);
		while (arg)
		{
			res[i++] = ft_pf_tools_d2c((char)(arg % base), 'x');
			arg = arg / base;
		}
		res[i++] = 'x';
		res[i++] = '0';
	}
	return (i);
}
