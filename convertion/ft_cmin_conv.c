/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cmin_conv.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 08:52:17 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 16:56:02 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

char	*ft_cmin_conv(t_printf *wip)
{
	char *res;
	char *temp;

	if (!(res = malloc(sizeof(char) * 2)))
		return (NULL);
	res[0] = (char)va_arg(wip->ap, int);
	res[1] = '\0';
	if (wip->size_champ <= 2)
		return (res);
	if(!(temp = ft_calloc(sizeof(char), (wip->size_champ - 1))))
		return (NULL);
	temp = ft_memset(temp, ' ', wip->size_champ - 2);
	if ((wip->flags & MINUS) == 0)
		return (ft_strjoinmod(temp, res, 3));
	return (ft_strjoinmod(res, temp, 3));
}
