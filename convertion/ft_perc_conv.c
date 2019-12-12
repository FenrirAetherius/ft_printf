/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_perc_conv.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fenrir <fenrir@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 15:33:09 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 06:23:26 by fenrir      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libconv.h"

char	*ft_perc_conv(t_printf *wip)
{
	char *res;

	if (!(res = malloc(sizeof(char) * 2)))
		return (NULL);
	res[0] = '%';
	res[1] = '\0';
	return (res);
}
