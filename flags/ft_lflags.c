/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lflags.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fenrir <fenrir@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 13:55:02 by fenrir       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 06:38:59 by fenrir      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libflag.h"

static char	*ft_long_hexa(t_printf *wip)
{
	unsigned long temp;

	temp = va_arg(wip->ap, unsigned long int);
	if (wip->conv == X_MIN)
		return (ft_litoa_base(temp, "0123456789abcdef"));
	else if (wip->conv == X_MAJ)
		return (ft_litoa_base(temp, "0123456789ABCDEF"));
	else
		return (ft_litoa_base(temp, "0123456789"));
}

static char	*ft_long_num(t_printf *wip)
{
	long temp;

	temp = va_arg(wip->ap, long);
	return (ft_llitoa((long long)temp));
}

static char	*ft_long_char(t_printf *wip)
{
	wchar_t	*str;
	char	*res;
	int		i;

	if (wip->conv == S_MIN)
	{
		i = 0;
		str = va_arg(wip->ap, wchar_t *);
		res = ft_char_conv(str[i++]);
		while (str[i])
			res = ft_strjoinmod(res, ft_char_conv(str[i++]), 3);
	}
	else
		res = ft_char_conv(va_arg(wip->ap, wchar_t));
	return (res);
}

char	*ft_lflag(t_printf *wip)
{
	if (wip->conv == X_MAJ || wip->conv == X_MIN || wip->conv == U_MIN)
		return (ft_long_hexa(wip));
	if (wip->conv == I_MIN || wip->conv == D_MIN)
		return (ft_long_num(wip));
	if (wip->conv == S_MIN || wip->conv == C_MIN)
		return (ft_long_char(wip));
	return ("");
}
