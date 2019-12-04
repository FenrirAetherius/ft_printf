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
	char *temp;
	size_t	size_data;

	size_data = ft_strlen(res = ft_strdup(va_arg(wip->ap, char *)));
	if (((wip->flags & POINT) == POINT) && (wip->precision < size_data))
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
	if(!(temp = ft_calloc(sizeof(char), (wip->size_champ - size_data + 1))))
		return (NULL);
	temp = ft_memset(temp, ' ', wip->size_champ - size_data);
	if ((wip->flags & MINUS) == 0)
		return (ft_strjoinmod(temp, res, 3));
	return (ft_strjoinmod(res, temp, 3));
}
