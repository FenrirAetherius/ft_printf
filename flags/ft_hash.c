/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_hash.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 15:04:18 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 23:38:17 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libflag.h"

char	*ft_hash(char *res, t_printf *wip)
{
	if (wip->conv == X_MIN)
		return (ft_strjoinmod("0x", res, 2));
	else if (wip->conv == X_MAJ)
		return (ft_strjoinmod("0X", res, 2));
	else
		return (res);
}
