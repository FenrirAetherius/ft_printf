/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_xmaj_conv.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fenrir <fenrir@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 10:48:29 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 06:23:11 by fenrir      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libconv.h"

char	*ft_xmaj_conv(t_printf *wip)
{
	char *res;

	if ((wip->flags & L_MIN == 0) && (wip->flags & LL_MIN == 0))
		res = ft_itoa_base(va_arg(wip->ap, unsigned int), "0123456789ABCDEF");
	else if (wip->flags & L_MIN != 0)
		res = ft_llitoa_base((unsigned long long)va_arg(wip->ap, unsigned long), "0123456789ABCDEF");
	else if (wip->flags & LL_MIN != 0)
		res = ft_llitoa_base(va_arg(wip->ap, unsigned long long), "0123456789ABCDEF");
	if ((wip->flags & HASH) == HASH)
		return (ft_hash(res, wip));
	return (res);
}
