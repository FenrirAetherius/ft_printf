/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_zero.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 21:31:15 by fenrir       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/14 14:09:50 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libflag.h"

char	*ft_zero(char *res, t_printf *wip, size_t size_data)
{
	char	*temp;
	char	*modif;

	if (!(temp = ft_calloc(sizeof(char), (wip->size_champ - size_data + 1))))
		return (NULL);
	temp = ft_memset(temp, '0', wip->size_champ - size_data);
	if (res[0] != '-')
		return (ft_strjoinmod(temp, res, 3));
	modif = ft_strjoinmod("-", ft_strjoinmod(temp, res + 1, 1), 2);
	free(res);
	return (modif);
}
