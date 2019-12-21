/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_float_utils.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/21 01:26:04 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 03:24:28 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libconv.h"

int			ft_signbit(double d, t_printf *wip)
{
	t_doubles u;

	u.d = d;
	if (u.bits.sign)
		wip->neg = '1';
	return (u.bits.sign);
}

long double	ft_arrondi(int i)
{
	long double res;

	res = 0.5;
	while (i-- > 0)
		res = res / 10.0;
	return (res);
}

char		*ft_checkvalue(double ret, t_printf *wip)
{
	t_doubles	u;
	char		*res;

	u.d = ret;
	res = NULL;
	if (u.bits.exp == 0x7ff)
		wip->flags = wip->flags & ~ZERO;
	if ((u.bits.exp == 0x7ff) && (u.bits.manh == 0) && (u.bits.manl == 0) &&
	(u.bits.sign == 0))
		res = ft_strdup("inf");
	else if ((u.bits.exp == 0x7ff) && (u.bits.manh == 0) &&
	(u.bits.manl == 0) && (u.bits.sign == 1))
		res = ft_strdup("-inf");
	else if (u.bits.exp == 0x7ff)
	{
		res = ft_strdup("nan");
		wip->flags = wip->flags & ~PLUS;
	}
	return (res);
}
