/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_smin_conv.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fenrir <fenrir@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 09:14:09 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 07:58:27 by fenrir      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libconv.h"

char	*ft_smin_conv(t_printf *wip)
{
	char *res;
	char *prec;
	size_t	size_data;

	if (wip->flags & L_MIN != 0)
		res = ft_lflag(wip);
	else
		res = ft_strdup(va_arg(wip->ap, char *));
	size_data = ft_strlen(res);
	if (((wip->flags & POINT) != 0) && (wip->precision < size_data))
		size_data = ft_precision(&res, wip, size_data);
	if (size_data >= wip->size_champ)
		return (res);
	return(ft_size_champ(res, wip, size_data));
}
