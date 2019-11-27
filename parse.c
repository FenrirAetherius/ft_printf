/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 09:15:42 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/27 14:06:13 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void	fill_sym(t_printf *wip, int n)
{
	if (n < 13)
		wip->conv = 1 << n;
	else if (n < 17)
		wip->flags = wip->flags | (1 << (n - 13));
	else if (n == 17)
	{
		if ((wip->flags & H_MIN) != 0)
			wip->flags = (wip->flags & ~H_MIN) | HH_MIN;
		else
			wip->flags = wip->flags | H_MIN;
	}
	else if (n == 18)
	{
		if ((wip->flags & L_MIN) != 0)
			wip->flags = (wip->flags & ~L_MIN) | LL_MIN;
		else
			wip->flags = wip->flags | L_MIN;
	}
	else
		wip->flags = wip->flags | (1 << (n - 11));
}

/*
**	return 0 ok
**	return 1 error
*/

int		check(t_printf *wip, int i)
{
	int		n;
	char	*symbol;

	if (!(symbol = malloc(sizeof(char) * 24)))
		return (NULL);
	symbol = CONVERT;
	*(symbol + 13) = FLAG;
	symbol[23] = '\0';
	n = -1;
	while (symbol[++n])
	{
		if (wip->formats[i] == symbol[n])
		{
			fill_sym(wip, n);
			free(symbol);
			return (0);
		}
	}
	free(symbol);
	return (1);
}

int		parse(t_printf *wip, int i)
{
	char *temp_done;
	char *temp_form;

	temp_done = wip->strdone;
	temp_form = wip->formats;
	wip->conv = INIT_C;
	wip->flags = INIT_F;
	temp_form[i] = '\0';
	wip->strdone = ft_strjoin(temp_done, wip->formats);
	free(temp_done);
	while (wip->conv == 0 && wip->formats[++i])
	{
		check(wip, i);
	}
	wip->formats = ft_strdup(temp_form[++i]);
	free(temp_form);
	temp_done = wip->strdone;
	temp_form = ch_conv(wip);
	wip->strdone = ft_strjoin(temp_done, temp_form);
	free(temp_form);
	free(temp_done);
	return (0);
}
