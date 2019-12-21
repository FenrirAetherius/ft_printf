/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_hflags.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 21:46:09 by fenrir       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 11:24:13 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libflag.h"

static char	*ft_short_hexa(t_printf *wip)
{
	unsigned short temp;

	temp = (unsigned short)va_arg(wip->ap, unsigned int);
	if (wip->conv == X_MIN)
		return (ft_hitoa_base(temp, "0123456789abcdef"));
	else if (wip->conv == X_MAJ)
		return (ft_hitoa_base(temp, "0123456789ABCDEF"));
	else if (wip->conv == U_MIN)
		return (ft_hitoa_base(temp, "0123456789"));
	else
		return (ft_hitoa_base(temp, "01234567"));
}

static char	*ft_short_num(t_printf *wip)
{
	short temp;

	temp = (short)va_arg(wip->ap, int);
	return (ft_itoa((int)temp));
}

static void	ft_short_nconv(t_printf *wip)
{
	short	*temp;

	temp = va_arg(wip->ap, short *);
	if (temp != NULL)
		*temp = (short)ft_strlen(wip->strdone);
}

char		*ft_hflag(t_printf *wip)
{
	if (wip->conv == X_MAJ || wip->conv == X_MIN || wip->conv == U_MIN ||
		wip->conv == O_MIN)
		return (ft_short_hexa(wip));
	if (wip->conv == I_MIN || wip->conv == D_MIN)
		return (ft_short_num(wip));
	if (wip->conv == N_MIN)
		ft_short_nconv(wip);
	return ("");
}
