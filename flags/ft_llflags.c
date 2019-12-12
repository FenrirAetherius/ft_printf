/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_llflags.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fenrir <fenrir@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 21:40:39 by fenrir       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 06:38:53 by fenrir      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libflag.h"

static char	*ft_long_hexa(t_printf *wip)
{
	unsigned long long temp;

	temp = va_arg(wip->ap, unsigned long long int);
	if (wip->conv == X_MIN)
		return (ft_llitoa_base(temp, "0123456789abcdef"));
	else if (wip->conv == X_MAJ)
		return (ft_llitoa_base(temp, "0123456789ABCDEF"));
	else
		return (ft_llitoa_base(temp, "0123456789"));
}

static char	*ft_long_num(t_printf *wip)
{
	long long temp;

	temp = va_arg(wip->ap, long long);
	return (ft_llitoa(temp));
}

char	*ft_llflag(t_printf *wip)
{
	if (wip->conv == X_MAJ || wip->conv == X_MIN || wip->conv == U_MIN)
		return (ft_long_hexa(wip));
	if (wip->conv == I_MIN || wip->conv == D_MIN)
		return (ft_long_num(wip));
	return ("");
}
