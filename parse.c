/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 09:15:42 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/27 17:14:56 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int		len_champ(t_printf *wip, int i)
{
	wip->size_champ = wip->formats[i++] - '0';
	while (wip->formats[i] >= '0' && wip->formats[i] <= '9')
	{
		wip->size_champ = wip->size_champ * 10 + (wip->formats[i++] - '0');
	}
	return (i);
}

void	ft_precision(t_printf *wip, int i)
{
	wip->precision = 0;
	i++;
	while (wip->formats[i] >= '0' && wip->formats[i] <= '9')
	{
		wip->precision = wip->precision * 10 + (wip->formats[i++] - '0');
	}
}

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

	n = -1;
	while (SYMBOL[++n])
	{
		if (wip->formats[i] == SYMBOL[n])
		{
			fill_sym(wip, n);
			return (0);
		}
	}
	if (wip->formats[i] == '.')
		ft_precision(wip, i);
	return (1);
}

int		ft_parse(t_printf *wip, int i)
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
		if (wip->formats[i] >= '0' && wip->formats[i] <= '9' &&
		((wip->flags & POINT) == 0))
			i = len_champ(wip, i);
		check(wip, i);
	}
	wip->formats = ft_strdup(&temp_form[++i]);
	free(temp_form);
	/*temp_done = wip->strdone;
	temp_form = ch_conv(wip);
	wip->strdone = ft_strjoin(temp_done, temp_form);
	free(temp_form);
	free(temp_done);*/
	return (0);
}
