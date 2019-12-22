/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_perc_conv.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 15:33:09 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/22 21:22:17 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libconv.h"

char	*ft_perc_conv(t_printf *wip)
{
	char *res;

	wip->flags = wip->flags & ~SPACE;
	wip->flags = wip->flags & ~PLUS;
	if (!(res = malloc(sizeof(char) * 2)))
		return (NULL);
	res[0] = '%';
	res[1] = '\0';
	if ((wip->flags & POINT) != 0)
		wip->flags = wip->flags & ~ZERO;
	if (wip->size_champ < 2)
		return (res);
	return (ft_size_champ(res, wip, 1));
}
