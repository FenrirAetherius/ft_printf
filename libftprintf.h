/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libftprintf.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fenrir <fenrir@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/17 15:14:25 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 06:33:09 by fenrir      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

/*
**	conv contain convert symbol in this order :
**	MSB(most significant bite) (complet with 0) nfgecspdiuxX% LSB
**
**	flags contains flags in this order : + space # ' l ll h hh - 0 . *
*/

typedef struct	s_printf
{
	va_list		ap;
	short		conv;
	short		flags;
	char		*formats;
	char		*strdone;
	size_t		precision;
	size_t		size_champ;
	size_t		size_strdone;
}				t_printf;

# define	SYMBOL "%Xxuidpscegfn*.0-hl'# +"

# define	INIT_C	0b0000000000000000

# define	PERCENT	0b0000000000000001
# define	X_MAJ	0b0000000000000010
# define	X_MIN	0b0000000000000100
# define	U_MIN	0b0000000000001000
# define	I_MIN	0b0000000000010000
# define	D_MIN	0b0000000000100000
# define	P_MIN	0b0000000001000000
# define	S_MIN	0b0000000010000000
# define	C_MIN	0b0000000100000000
# define	E_MIN	0b0000001000000000 //todo
# define	G_MIN	0b0000010000000000 //todo
# define	F_MIN	0b0000100000000000 //todo
# define	N_MIN	0b0001000000000000 //todo

# define	INIT_F	0b0000000000000000

# define	STAR	0b0000000000000001
# define	POINT	0b0000000000000010
# define	ZERO	0b0000000000000100
# define	MINUS	0b0000000000001000
# define	HH_MIN	0b0000000000010000
# define	H_MIN	0b0000000000100000
# define	LL_MIN	0b0000000001000000
# define	L_MIN	0b0000000010000000
# define	APOST	0b0000000100000000
# define	HASH	0b0000001000000000
# define	SPACE	0b0000010000000000
# define	PLUS	0b0000100000000000


int		ft_printf (const char *format, ...);
int		ft_parse(t_printf *wip, int i);
char	*ch_conv1(t_printf *wip);
char	*ft_char_conv(wchar_t origin);

#endif
