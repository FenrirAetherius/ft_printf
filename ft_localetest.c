/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_localetest.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/22 11:46:16 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/29 14:41:15 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_localetest(t_printf *wip, int *i, int n)
{
	if (!(ft_strnstr(wip->strloc, "UTF-8", ft_strlen(wip->strloc))) &&
	(wip->conv == S_MIN || wip->conv == C_MIN) && ((wip->flags & L_MIN) != 0))
	{
		wip->formats[n] = '\0';
		*i = n - 1;
		wip->error = 1;
	}
}
