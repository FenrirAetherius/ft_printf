/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_localetest.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/22 11:46:16 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/22 12:20:28 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_localetest(t_printf *wip)
{
	if ((ft_strnstr(wip->strloc, "C", ft_strlen(wip->strloc))) &&
	(wip->conv == S_MIN || wip->conv == C_MIN) && ((wip->flags & L_MIN) != 0))
	{
		free(wip->formats);
		wip->error = 1;
		free(wip->strloc);
	}
	if ((ft_strnstr(wip->strloc, "POSIX", ft_strlen(wip->strloc))) &&
	(wip->conv == S_MIN || wip->conv == C_MIN) && ((wip->flags & L_MIN) != 0))
	{
		free(wip->formats);
		wip->error = 1;
		free(wip->strloc);
	}
}
