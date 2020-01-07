/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_convert.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 13:56:54 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 09:57:28 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "convertion/libconv.h"

static char	*ch_conv2(t_printf *wip)
{
	char *res;

	if ((wip->conv == 512) || (wip->conv == 1024) || (wip->conv == 2048))
		res = ft_efgmin_select(wip);
	else if (wip->conv == 4096)
		res = ft_nmin_conv(wip);
	else if (wip->conv == 8192)
		res = ft_omin_conv(wip);
	else
	{
		wip->flags = wip->flags & ~SPACE;
		wip->flags = wip->flags & ~PLUS;
		wip->flags = wip->flags & ~POINT;
		res = ft_strdup("\0");
		if (wip->size_champ > 1)
			res = ft_size_champ(res, wip, 1);
		wip->flags = INIT_F;
	}
	return (res);
}

char		*ch_conv1(t_printf *wip)
{
	char *res;

	if (wip->conv == 1)
		res = ft_perc_conv(wip);
	else if (wip->conv == 2)
		res = ft_xmaj_conv(wip);
	else if (wip->conv == 4)
		res = ft_xmin_conv(wip);
	else if (wip->conv == 8)
		res = ft_umin_conv(wip);
	else if (wip->conv == 16 || wip->conv == 32)
		res = ft_dmin_conv(wip);
	else if (wip->conv == 64)
		res = ft_pmin_conv(wip);
	else if (wip->conv == 128)
		res = ft_smin_conv(wip);
	else if (wip->conv == 256)
		res = ft_cmin_conv(wip);
	else
		res = ch_conv2(wip);
	return (res);
}
