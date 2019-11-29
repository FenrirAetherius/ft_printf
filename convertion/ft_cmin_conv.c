/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cmin_conv.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 08:52:17 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 09:27:38 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

char	*ft_cmin_conv(t_printf *wip)
{
	char *res;

	if (!(res = malloc(sizeof(char) * 2)))
		return (NULL);
	res[0] = (char)va_arg(wip->ap, int);
	res[1] = '\0';
	return (res);
}
