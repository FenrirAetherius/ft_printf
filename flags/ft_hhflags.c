/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_hhflags.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fenrir <fenrir@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 21:50:29 by fenrir       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 21:51:29 by fenrir      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

static char	*ft_short_hexa(t_printf *wip)
{
	unsigned char temp;

	temp = va_arg(wip->ap, unsigned char);
	if (wip->conv == X_MIN)
		return (ft_hhitoa_base(temp, "0123456789abcdef"));
	else if (wip->conv == X_MAJ)
		return (ft_hhitoa_base(temp, "0123456789ABCDEF"));
	else
		return (ft_hhitoa_base(temp, "0123456789"));
}

static char	*ft_short_num(t_printf *wip)
{
	char temp;

	temp = va_arg(wip->ap, char);
	return (ft_itoa((int)temp));
}

char	*ft_hhflag(t_printf *wip)
{
	if (wip->conv == X_MAJ || wip->conv == X_MIN || wip->conv == U_MIN)
		return (ft_short_hexa(wip));
	if (wip->conv == I_MIN || wip->conv == D_MIN)
		return (ft_short_num(wip));
	return ("");
}
