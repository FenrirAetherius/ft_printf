/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pmin_conv.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 13:36:21 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/13 03:04:57 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libconv.h"

char	*ft_pmin_conv(t_printf *wip)
{
	unsigned long	res;
	char			*str;
	size_t			size_data;

	res = (unsigned long)va_arg(wip->ap, void *);
	str = ft_litoa_base(res, "0123456789abcdef");
	str = ft_hash(str, wip);
	size_data = ft_strlen(str);
	wip->flags = wip->flags & ~ZERO;
	if (wip->size_champ <= size_data)
		return (str);
	return (ft_size_champ(str, wip, size_data));
}
