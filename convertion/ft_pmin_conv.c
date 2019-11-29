/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pmin_conv.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 13:36:21 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 14:30:54 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

char	*ft_pmin_conv(t_printf *wip)
{
	unsigned long res;
	res = (unsigned long)va_arg(wip->ap, void *);
	return (ft_utoa_base(res, "0123456789abcdef"));
}
