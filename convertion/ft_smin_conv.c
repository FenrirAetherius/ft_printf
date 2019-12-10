/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_smin_conv.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 09:14:09 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/02 13:28:23 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

char	*ft_smin_conv(t_printf *wip)
{
	char *res;
	char *prec;
	size_t	size_data;

	size_data = ft_strlen(res = ft_strdup(va_arg(wip->ap, char *)));
	if (((wip->flags & POINT) != 0) && (wip->precision < size_data))
	{
		if(!(prec = calloc(sizeof(char), (wip->precision + 1))))
			return (NULL);
		prec = ft_memcpy(prec, res, (sizeof(char) * wip->precision));
		free(res);
		res = prec;
		size_data = wip->precision;
	}
	if (size_data >= wip->size_champ)
		return (res);
	return(ft_size_champ(res, wip, size_data));
}
