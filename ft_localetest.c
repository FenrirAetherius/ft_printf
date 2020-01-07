/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_localetest.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/22 11:46:16 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 09:26:09 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_localetest(t_printf *wip, int *i, int n)
{
	char	*temp_form;

	temp_form = NULL;
	if (!(ft_strnstr(wip->strloc, "UTF-8", ft_strlen(wip->strloc))) &&
	(wip->conv == S_MIN || wip->conv == C_MIN) && ((wip->flags & L_MIN) != 0))
	{
		wip->error = 1;
		temp_form = ch_conv1(wip);
		if (wip->error == 1)
		{
			free(temp_form);
			temp_form = NULL;
			wip->formats[n] = '\0';
			*i = n - 1;
		}
	}
	return (temp_form);
}
