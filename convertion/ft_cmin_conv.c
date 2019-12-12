/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cmin_conv.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fenrir <fenrir@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 08:52:17 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 06:23:36 by fenrir      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libconv.h"

char	*ft_cmin_conv(t_printf *wip)
{
	char	*res;
	char	*temp;
	size_t	size_data;

	if (wip->flags & L_MIN != 0)
		res = ft_lflag(wip);
	else
	{
		if (!(res = malloc(sizeof(char) * 2)))
			return (NULL);
		res[0] = (char)va_arg(wip->ap, int);
		res[1] = '\0';
	}
	size_data = ft_strlen(res);
	if (wip->size_champ <= size_data)
		return (res);
	return(ft_size_champ(res, wip, size_data));
}
