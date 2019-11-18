/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libftprintf.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/17 15:14:25 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/18 13:39:12 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdlib.h>
# include <unistd.h>

/*
**	conv contain convert symbol in this order :
**	MSB(most significant bite) (complet with 0) nfgecspdiuxX% LSB
**
**	flags contains flags in this order : + space # ' l ll h hh - 0 . *
*/

typedef struct	s_conv
{
	short		conv;
	short		flags;
	char		*format;
	char		*strdone;
}				t_conv;

# define	CONVERT	"nfgecspdiuxX%"
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
# define	E_MIN	0b0000001000000000
# define	G_MIN	0b0000010000000000
# define	F_MIN	0b0000100000000000
# define	N_MIN	0b0001000000000000

# define	FLAG	"+ #'lllhhh-0.*"
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
#endif
