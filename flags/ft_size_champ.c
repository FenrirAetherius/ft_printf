/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_size_champ.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 15:04:15 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/13 01:14:51 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libflag.h"

char	*ft_size_champ(char *res, t_printf *wip, size_t size_data)
{
	char	*temp;

	if (((wip->flags & ZERO) != 0) && ((wip->flags & MINUS) == 0) &&
		((wip->flags & POINT) == 0) && ((wip->flags & PLUS) != 0))
		return (ft_plus(ft_zero(res, wip, size_data)));
	if (((wip->flags & ZERO) != 0) && ((wip->flags & MINUS) == 0) &&
		((wip->flags & POINT) == 0) && ((wip->flags & PLUS) == 0))
		return (ft_zero(res, wip, size_data));
	if (!(temp = ft_calloc(sizeof(char), (wip->size_champ - size_data + 1))))
		return (NULL);
	temp = ft_memset(temp, ' ', wip->size_champ - size_data);
	if ((wip->flags & MINUS) == 0)
		return (ft_strjoinmod(temp, res, 3));
	return (ft_strjoinmod(res, temp, 3));
}