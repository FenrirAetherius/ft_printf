/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_xmin_conv.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fenrir <fenrir@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 10:46:55 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 08:43:34 by fenrir      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libconv.h"

char	*ft_xmin_conv(t_printf *wip)
{
	char *res;
	size_t size_data;

	if (wip->flags & L_MIN != 0)
		res = ft_lflag(wip);
	else if (wip->flags & LL_MIN != 0)
		res = ft_llflag(wip);
	else if (wip->flags & H_MIN != 0)
		res = ft_hflag(wip);
	else if (wip->flags & HH_MIN != 0)
		res = ft_hhflag(wip);
	else
		res = ft_itoa_base(va_arg(wip->ap, unsigned int), "0123456789abcdef");
	size_data = ft_strlen(res);
	if (wip->flags & POINT != 0 && size_data < wip->precision)
		size_data = ft_precision(res, wip, size_data);
	else if (wip->flags & ZERO != 0)
		res = ft_zero(res, wip, size_data);
	if ((wip->flags & HASH) == HASH)
		res = ft_hash(res, wip);
	if (wip->size_champ <= size_data)
		return (res);
	return(ft_size_champ(res, wip, size_data));
}
