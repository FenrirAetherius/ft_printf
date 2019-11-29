/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_xmaj_conv.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 10:48:29 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 13:09:10 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

char	*ft_xmaj_conv(t_printf *wip)
{
	return (ft_itoa_base(va_arg(wip->ap, unsigned int), "0123456789ABCDEF"));
}
