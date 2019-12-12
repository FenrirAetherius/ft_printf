/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pmin_conv.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fenrir <fenrir@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 13:36:21 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 06:22:27 by fenrir      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libconv.h"

char	*ft_pmin_conv(t_printf *wip)
{
	unsigned long res;
	res = (unsigned long)va_arg(wip->ap, void *);
	return (ft_litoa_base(res, "0123456789abcdef"));
}
