/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fmin_conv.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/19 23:54:08 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 10:13:11 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libconv.h"

static char	*ft_deci_part(long double ret, int *i)
{
	char	*res;
	char	*tmp;

	while (ret > 18446744073709551616.0)
	{
		ret = ret / 10.0;
		(*i)++;
	}
	if (ret == 18446744073709551616.0)
		res = ft_strdup("18446744073709551616");
	else
		res = ft_llitoa_base((unsigned long long)ret, "0123456789");
	if (!(tmp = malloc(sizeof(char) * (*i + 1))))
		return (NULL);
	tmp = ft_memset(tmp, '0', *i * sizeof(char));
	res = ft_strjoinmod(res, tmp, 3);
	return (res);
}

static char	*ft_fmin_preci(long double ret, int pre, char *res)
{
	res = ft_strjoinmod(res, localeconv()->decimal_point, 1);
	while (pre-- > 0)
	{
		ret = ret * 10;
		res = ft_strjoinmod(res, ft_itoa((int)ret), 3);
		ret -= (long double)((int)ret);
	}
	return (res);
}

static char	*ft_fmin_num(long double ret, t_printf *wip, int pre)
{
	int			i;
	char		*res;

	i = 0;
	if (ft_signbit((double)ret, wip))
		ret = -ret;
	ret = ret + ft_arrondi(pre);
	res = ft_deci_part(ret, &i);
	if ((wip->flags & APOST) != 0)
		res = ft_apost(res);
	ret -= (long double)((long long)ret);
	if ((((wip->flags & POINT) != 0) && pre) ||
		((wip->flags & POINT) == 0))
		res = ft_fmin_preci(ret, pre, res);
	else if ((wip->flags & HASH) != 0)
		res = ft_strjoinmod(res, ".", 1);
	if (wip->neg == '1')
		res = ft_strjoinmod("-", res, 2);
	return (res);
}

char		*ft_fmin_conv(t_printf *wip, long double ret, int pre)
{
	char		*res;
	int			size_res;

	if (!(res = ft_checkvalue((double)ret, wip)))
		res = ft_fmin_num(ret, wip, pre);
	size_res = ft_strlen(res);
	if (((wip->flags & PLUS) != 0) && ((wip->flags & ZERO) == 0) &&
		(wip->conv == F_MIN))
		res = ft_plus(res);
	if (size_res >= wip->size_champ)
		return (res);
	return (ft_size_champ(res, wip, size_res));
}
