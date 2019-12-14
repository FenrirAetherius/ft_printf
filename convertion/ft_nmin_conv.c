/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_nmin_conv.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/13 04:32:00 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/14 15:42:32 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libconv.h"

char	*ft_nmin_conv(t_printf *wip)
{
	int		*res;
	char	*voidstr;

	if (!(voidstr = ft_calloc(1, sizeof(char))))
		return (NULL);
	if ((wip->flags & L_MIN) != 0)
		ft_lflag(wip);
	else if ((wip->flags & LL_MIN) != 0)
		ft_llflag(wip);
	else if ((wip->flags & H_MIN) != 0)
		ft_hflag(wip);
	else if ((wip->flags & HH_MIN) != 0)
		ft_hhflag(wip);
	else
	{
		res = va_arg(wip->ap, int *);
		if (res != NULL)
			*res = ft_strlen(wip->strdone);
	}
	return (voidstr);
}
