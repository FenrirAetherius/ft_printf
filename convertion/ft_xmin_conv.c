/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_xmin_conv.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fenrir <fenrir@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 10:46:55 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 00:36:12 by fenrir      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

char	*ft_xmin_conv(t_printf *wip)
{
	char *res;
	size_t size_data;

	if ((wip->flags & L_MIN == 0) && (wip->flags & LL_MIN == 0))
		res = ft_itoa_base(va_arg(wip->ap, unsigned int), "0123456789abcdef");
	else if (wip->flags & L_MIN != 0)
		res = ft_llitoa_base((unsigned long long)va_arg(wip->ap, unsigned long), "0123456789abcdef");
	else if (wip->flags & LL_MIN != 0)
		res = ft_llitoa_base(va_arg(wip->ap, unsigned long long), "0123456789abcdef");
	if ((wip->flags & HASH) == HASH)
		res = ft_hash(res, wip);
	size_data = ft_strlen(res);
	if (wip->flags & POINT != 0 && size_data < wip->precision)
	{
		res = ft_precision(res, wip, size_data);
		size_data = wip->precision;
	}
	else if (wip->flags & ZERO != 0)
		res = ft_zero(res, wip, size_data);
	if (wip->size_champ <= size_data)
		return (res);
	return(ft_size_champ(res, wip, size_data));
}

