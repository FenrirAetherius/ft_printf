/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_xmin_conv.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 10:46:55 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 13:08:59 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

char	*ft_xmin_conv(t_printf *wip)
{
	return (ft_itoa_base(va_arg(wip->ap, unsigned int), "0123456789abcdef"));
}
