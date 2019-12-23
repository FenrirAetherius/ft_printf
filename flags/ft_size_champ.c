/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_size_champ.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 15:04:15 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/23 03:40:11 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libflag.h"

static char	*ft_conv_c(char *res, t_printf *wip, size_t size_data)
{
	char	*temp;
	char	*tmp;

	free(res);
	if (!(temp = ft_calloc(sizeof(char), (wip->size_champ - size_data + 2))))
		return (NULL);
	tmp = &temp[1];
	if ((wip->flags & MINUS) == 0)
		tmp = ft_memset(temp, ' ', wip->size_champ - size_data);
	else
		temp = ft_memset(temp, ' ', wip->size_champ - size_data);
	return (temp);
}

char	*ft_size_champ(char *res, t_printf *wip, size_t size_data)
{
	char	*temp;

	if (((wip->flags & SPACE) || (wip->flags & PLUS)) && (wip->neg == '0'))
		size_data++;
	if (((wip->flags & HASH) != 0) && ((wip->conv == X_MAJ ||
		wip->conv == X_MIN) && (res[1] == 'x' || res[1] == 'X')))
		wip->size_champ -= 2;
	if (((wip->flags & HASH) != 0) && wip->conv == O_MIN && res[0] == '0')
		wip->size_champ -= 1;
	if (((wip->flags & ZERO) != 0) && ((wip->flags & MINUS) == 0) &&
		((wip->flags & POINT) == 0) && ((wip->flags & PLUS) != 0))
		return (ft_plus(ft_zero(res, wip, size_data), wip));
	if (((wip->flags & ZERO) != 0) && ((wip->flags & MINUS) == 0) &&
		(((wip->flags & POINT) == 0) || (wip->conv == F_MIN) ||
		(wip->conv == E_MIN) || (wip->conv == G_MIN)) &&
		((wip->flags & PLUS) == 0))
		return (ft_zero(res, wip, size_data));
	if ((wip->conv == C_MIN) && (res[0] == 0))
		return (ft_conv_c(res, wip, size_data));
	if (!(temp = ft_calloc(sizeof(char), (wip->size_champ - size_data + 1))))
		return (NULL);
	temp = ft_memset(temp, ' ', wip->size_champ - size_data);
	if ((wip->flags & MINUS) == 0)
		return (ft_strjoinmod(temp, res, 3));
	return (ft_strjoinmod(res, temp, 3));
}
