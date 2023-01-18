/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:08:35 by antoda-s          #+#    #+#             */
/*   Updated: 2023/01/17 16:08:53 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/**********************
	LIBS
**********************/

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "../libft/libft.h"

/*# include "libft.h" */

/**********************
	TYPEDEF
**********************/

typedef struct s_printf
{
	va_list	args;
	int		f_hash;
	int		f_align;
	char	f_stype;
	int		f_zpad;
	int		w_num;
	int		p_dot;
	int		p_num;
	char	e_sign;
	int		e_val;
	char	e_symb;
	char	e_radix;
	char	at;
	char	arg_len1;
	char	arg_len2;
	int		arg_zero;
	int		res_len;
	int		pf_len;
}	t_printf;

/**********************
 FUNCTIONS PROTOTYPES
**********************/

/**********ft_pf_all2s_1.c**********/
int				ft_pf_tools_d2s(t_printf *f, unsigned int n, char *str);
int				ft_pf_tools_i2s(char arg_type, unsigned int n, char *str);
int				ft_pf_tools_f2s(t_printf *f, char *str);
int				ft_pf_tools_f2s_power(t_printf *f, char *arg_arr, \
				char *str, void *arg);
void			ft_pf_tools_f2s_exp(t_printf *f, long double *arg);
/**********ft_pf_all2s_2.c**********/
int				ft_pf_tools_f2s_fill_arr(char base, char *arg_arr, void *arg);
int				ft_pf_tools_f2s_round(t_printf *f, int k, char *arg_arr);
int				ft_pf_tools_f2s_round_offset(t_printf *f);
int				ft_pf_tools_f2s_mantissa(t_printf *f, char dot, \
				char *arg_arr, char *str);
/* ft_pf_fwp2f.c - prepare t_printf for each new arg */
const char		*ft_pf_all2f(t_printf *flgs, const char *s);
const char		*ft_pf_f2f(t_printf *flgs, const char *s);
const char		*ft_pf_w2f(t_printf *flgs, const char *s);
const char		*ft_pf_p2f(t_printf *f, const char *s);
const char		*ft_pf_l2f(t_printf *flgs, const char *s);
/*	ft_pf_fwp2s.c */
int				ft_pf_fwp_p2s(t_printf *f, char *digit, int i);
int				ft_pf_fwp_war2s(t_printf *f, char *ds, int i);
int				ft_pf_fwp_wal2s(t_printf *f, char *ds, int i);
int				ft_pf_fwp_hash2s(t_printf *f, char *digit, int i);
void			ft_pf_write(t_printf *f, char *res);
/* ft_pf_tools1.c */
void			ft_pf_fwp_u(t_printf *f, void *arg);
char			ft_pf_tools_d2c(const int n, char radix);
char			*ft_pf_tools_strrev(char *str, int j);
char			ft_pf_tools_radix(char base);
int				ft_isdigit(int c);
/* ft_pf_type_numbers.c*/
void			ft_pf_type_fega(t_printf *f);
void			ft_pf_type_fega_flags(t_printf *f);
void			ft_pf_type_g(t_printf *f);
void			ft_pf_type_iduox(t_printf *f);
void			ft_pf_type_n(t_printf *f);
/* ft_pf_type_scp.c*/
void			ft_pf_type_s(t_printf *f);
int				ft_pf_type_s2s(t_printf *f, char *res, char *ds, int ds_len);
void			ft_pf_type_c(t_printf *f);
void			ft_pf_type_p(t_printf *f);
int				ft_pf_type_p2s(t_printf *f, char *res, unsigned long long arg);
/*	ft_printf.c -  where the printf and most directly functions reside */
int				ft_printf(const char *format, ...);
const char		*ft_pf_type(t_printf *flgs, const char *s);
void			ft_pf_f_init(t_printf *f);

#endif
