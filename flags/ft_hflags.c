/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_hflags.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fenrir <fenrir@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 21:46:09 by fenrir       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 06:39:11 by fenrir      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libflag.h"

static char	*ft_short_hexa(t_printf *wip)
{
	unsigned short temp;

	temp = va_arg(wip->ap, unsigned short);
	if (wip->conv == X_MIN)
		return (ft_hitoa_base(temp, "0123456789abcdef"));
	else if (wip->conv == X_MAJ)
		return (ft_hitoa_base(temp, "0123456789ABCDEF"));
	else
		return (ft_hitoa_base(temp, "0123456789"));
}

static char	*ft_short_num(t_printf *wip)
{
	short temp;

	temp = va_arg(wip->ap, short);
	return (ft_itoa((int)temp));
}

char	*ft_hflag(t_printf *wip)
{
	if (wip->conv == X_MAJ || wip->conv == X_MIN || wip->conv == U_MIN)
		return (ft_short_hexa(wip));
	if (wip->conv == I_MIN || wip->conv == D_MIN)
		return (ft_short_num(wip));
	return ("");
}
