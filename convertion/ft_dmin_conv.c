/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dmin_conv.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fenrir <fenrir@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 15:42:54 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 06:23:31 by fenrir      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libconv.h"

char	*ft_dmin_conv(t_printf *wip)
{
	char *res;
	char *prec;
	char *temp;
	size_t size_res;

	res = ft_itoa(va_arg(wip->ap, int));
	size_res = ft_strlen(res);
	if (((wip->flags & POINT) == POINT) && (size_res < wip->precision))
	{
		if(!(prec = calloc(sizeof(char), (wip->precision + 1 - size_res))))
			return (NULL);
		prec = ft_memset(prec, '0', (sizeof(char) * (wip->precision - size_res)));
		res = ft_strjoinmod(prec, res, 3);
		size_res = wip->precision;
	}
	if (size_res >= wip->size_champ)
		return (res);
	if(!(temp = ft_calloc(sizeof(char), (wip->size_champ - size_res + 1))))
		return (NULL);
	temp = ft_memset(temp, ' ', wip->size_champ - size_res);
	if ((wip->flags & MINUS) == 0)
		return (ft_strjoinmod(temp, res, 3));
	return (ft_strjoinmod(res, temp, 3));
}
