/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fmin_conv.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/19 23:54:08 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/20 21:33:06 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <float.h>
#include "libconv.h"

static int		ft_signbit(double d)
{
	t_doubles u;

	u.d = d;
	return (u.bits.sign);
}

static long double	ft_arrondi(int i)
{
	long double res;

	res = 0.5;
	while (i-- > 0)
		res = res / 10.0;
	return (res);
}

char			*ft_fmin_conv(t_printf *wip)
{
	long double		ret;
	char		*res;
	char		*tmp;
	int			i;
	int			pre;
	int			size_res;

	i = 0;
	ret = (long double)va_arg(wip->ap, double);
	if (ft_signbit((double)ret))
	{
		ret = -ret;
		wip->neg = '1';
	}
	if ((wip->flags & POINT) != 0)
		pre = wip->precision;
	else
		pre = 6;
	ret = ret + ft_arrondi(pre);
	while (ret > 18446744073709551616.0)
	{
		ret = ret / 10.0;
		i++;
	}
	if (ret == 18446744073709551616.0)
		res = ft_strdup("18446744073709551616");
	else
		res = ft_llitoa_base((unsigned long long)ret, "0123456789");
	if (!(tmp = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	tmp = ft_memset(tmp, '0', i * sizeof(char));
	res = ft_strjoinmod(res, tmp, 3);
	if ((wip->flags & APOST) != 0)
		res = ft_apost(res);
	if ((((wip->flags & POINT) != 0) && (wip->precision > 0)) ||
		((wip->flags & POINT) == 0))
	{
		res = ft_strjoinmod(res, localeconv()->decimal_point, 1);
		ret -= (long double)((long long)ret);
		while (i-- > 0)
			ret = ret * 10;
		while (pre-- > 0)
		{
			ret = ret * 10;
			res = ft_strjoinmod(res, ft_itoa((int)ret), 3);
			ret -= (long double)((int)ret);
		}
	}
	if (wip->neg == '1')
		res = ft_strjoinmod("-", res, 2);
	if (((wip->flags & PLUS) != 0) && ((wip->flags & ZERO) == 0))
		res = ft_plus(res);
	size_res = ft_strlen(res);
	if (size_res >= wip->size_champ)
		return (res);
	return (ft_size_champ(res, wip, size_res));
}
