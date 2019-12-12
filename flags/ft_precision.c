/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_precision.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fenrir <fenrir@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 15:03:32 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 06:38:29 by fenrir      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libflag.h"

static size_t ft_cutlstr(char *res, t_printf *wip)
{
	size_t preci;

	preci = wip->precision;
	if (((((res[preci - 1] >> 4) & 0x08) == 0b00000) && preci >= 1) ||
		((((res[preci - 2] >> 4) & 0x0e) == 0b01100) && preci >= 2) ||
		((((res[preci - 3] >> 4) & 0x0f) == 0b01110) && preci >= 3) ||
		((((res[preci - 4] >> 3) & 0x01f) == 0b011110) && preci >= 4))
		return (preci);
	else if (((((res[preci - 1] >> 4) & 0x0e) == 0b01100) ||
			(((res[preci - 1] >> 4) & 0x0f) == 0b01110) ||
			(((res[preci - 1] >> 3) & 0x01f) == 0b011110)) && preci >= 1)
		return (preci - 1);
	else if (((((res[preci - 2] >> 4) & 0x0f) == 0b01110) ||
			(((res[preci - 2] >> 3) & 0x01f) == 0b011110)) && preci >= 2)
		return (preci - 2);
	else if ((((res[preci - 3] >> 3) & 0x01f) == 0b011110) && preci >= 3)
		return (preci - 3);
}

static size_t ft_prec_smin(char *res, t_printf *wip)
{
	char *prec;
	size_t	newstrl;

	newstrl = wip->precision;
	if (wip->flags & L_MIN != 0)
	{
		newstrl = ft_cutlstr(res, wip);
	}
	if(!(prec = calloc(sizeof(char), (newstrl + 1))))
		return (NULL);
	prec = ft_memcpy(prec, res, (sizeof(char) * newstrl));
	free(res);
	res = prec;
	return (newstrl);
}

size_t	ft_precision(char *res, t_printf *wip, size_t size_data)
{
	char *temp;

	if ((wip->conv == X_MAJ) || (wip->conv == X_MIN) || (wip->conv == D_MIN) ||
		(wip->conv == U_MIN) || (wip->conv == I_MIN))
	{
		if (!(temp = calloc(sizeof(char), (wip->precision - size_data + 1))))
			return (NULL);
		temp = ft_memset(temp, '0', wip->precision - size_data);
		res = ft_strjoinmod(temp, res, 3);
	}
	if (wip->conv == S_MIN)
		return(ft_prec_smin(res, wip));
	return (wip->precision);
}
