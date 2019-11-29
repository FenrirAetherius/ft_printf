/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 13:56:54 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 14:26:20 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

/*static char	*ch_conv2(t_printf *wip)
{
	char *res;

	res = "you've been gnomed";
	if (wip->conv == 512)
		res = ft_emin_conv(wip);
	else if (wip->conv == 1024)
		res = ft_gmin_conv(wip);
	else if (wip->conv == 2048)
		res = ft_fmin_conv(wip);
	else if (wip->conv == 4096)
		res = ft_nmin_conv(wip);
	return (res);
}*/

char	*ch_conv1(t_printf *wip)
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
		res = ft_cmin_conv(wip);/*
	else
		res = ch_conv2(wip);*/
	else
	{
		if (!(res = malloc(sizeof(char) * 5)))
			return (NULL);
		res[0] = 'h';
		res[1] = 'a';
		res[2] = 'h';
		res[3] = 'a';
		res[4] = '\0';
	}

	return (res);
}