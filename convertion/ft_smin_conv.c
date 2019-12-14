/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_smin_conv.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 09:14:09 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/14 15:23:34 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libconv.h"

#include <stdio.h>

char	*ft_smin_conv(t_printf *wip)
{
	char	*res;
	int		size_data;

	if (((wip->flags & POINT) != 0) && (wip->precision == 0))
		res = ft_strdup("");
	else
	{
		if ((wip->flags & L_MIN) != 0)
			res = ft_lflag(wip);
		else
		{
			if ((res = va_arg(wip->ap, char *)) == NULL)
				res = ft_strdup("(null)");
			res = ft_strdup(res);
		}
	}
	size_data = ft_strlen(res);
	if ((wip->flags & POINT) != 0)
		size_data = ft_precision(&res, wip, size_data);
	wip->flags = wip->flags & ~ZERO;
	if (size_data >= wip->size_champ)
		return (res);
	return (ft_size_champ(res, wip, size_data));
}
