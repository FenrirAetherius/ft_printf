/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fmin_conv.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/19 23:54:08 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/20 03:45:31 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libconv.h"

int		signbit(double d)
{
	t_doubles u;

	u.d = d;
	return (u.bits.sign);
}

char	*ft_fmin_conv(t_printf *wip)
{
	double	ret;
	char	*res;
	char	*tmp;
	int		i;
	int		size_res;

	i = 0;
	ret = va_arg(wip->ap, double);
	if (ret < 0)
		wip->neg = '1';
	while (ret > 18446744073709551616.0)
	{
		ret = ret / 10.0;
		i++;
	}
	if (ret == 18446744073709551616.0)
		res = ft_strdup("18446744073709551616");
	else
		res = ft_llitoa_base((unsigned long long)res, "0123456789");
	if (!(tmp = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	tmp = ft_memset(tmp, '0', i * sizeof(char));
	res = ft_strjoinmod(res, tmp, 3);
	if ((wip->flags & APOST) != 0)
		res = ft_apost(res);
	if (((wip->flags & POINT) != 0) && (wip->precision == 0) ||
		((wip->flags & POINT) == 0))
	{
		res = ft_strjoinmod(res, localeconv()->decimal_point, 1);
		while (i-- > 0)
			ret = ret * 10.0;
		ret -= ft_atof(res);
		if ((wip->flags & POINT) != 0)
			i = wip->precision;
		else
			i = 6;
		while (i-- > 0)
		{
			ret = ret * 10.0;
			res = ft_strjoinmod(res, ft_itoa(ret), 3);
			ret -= (double)((int)ret);
		}
	}
	size_res = ft_strlen(res);
	if (((wip->flags & PLUS) != 0) && ((wip->flags & ZERO) == 0))
		res = ft_plus(res);
	if (res[0] == '-')
		wip->neg = '1';
	if (size_res >= wip->size_champ)
		return (res);
	return (ft_size_champ(res, wip, size_res));
}
