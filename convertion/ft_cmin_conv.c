/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cmin_conv.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 08:52:17 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/22 21:46:52 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libconv.h"

char	*ft_cmin_conv(t_printf *wip)
{
	char	*res;
	int		size_data;

	wip->flags = wip->flags & ~SPACE;
	wip->flags = wip->flags & ~PLUS;
	if ((wip->flags & L_MIN) != 0)
		res = ft_lflag(wip);
	else
	{
		if (!(res = malloc(sizeof(char) * 2)))
			return (NULL);
		res[0] = (char)va_arg(wip->ap, int);
		res[1] = '\0';
	}
	if (res[0] == 0)
	{
		wip->size_strdone++;
		size_data = 1;
		res = ft_strdup("");
	}
	else
		size_data = ft_strlen(res);
	if (wip->size_champ <= size_data)
		return (res);
	return (ft_size_champ(res, wip, size_data));
}
