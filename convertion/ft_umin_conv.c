/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_umin_conv.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 11:12:41 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/14 14:51:18 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libconv.h"

char		*ft_umin_conv(t_printf *wip)
{
	char	*res;
	int		size_res;

	if ((wip->flags & L_MIN) != 0)
		res = ft_lflag(wip);
	else if ((wip->flags & LL_MIN) != 0)
		res = ft_llflag(wip);
	else if ((wip->flags & H_MIN) != 0)
		res = ft_hflag(wip);
	else if ((wip->flags & HH_MIN) != 0)
		res = ft_hhflag(wip);
	else
		res = ft_itoa_base(va_arg(wip->ap, unsigned int), "0123456789");
	size_res = ft_strlen(res);
	if ((wip->flags & APOST) != 0)
		res = ft_apost(res);
	if ((wip->flags & POINT) != 0)
		size_res = ft_precision(&res, wip, size_res);
	wip->flags = wip->flags & ~PLUS;
	if (size_res >= wip->size_champ)
		return (res);
	return (ft_size_champ(res, wip, size_res));
}
