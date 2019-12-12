/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fenrir <fenrir@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 09:15:42 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 21:22:37 by fenrir      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

static int	len_champ(t_printf *wip, int i)
{
	if (wip->formats[i] == '0')
		wip->flags = wip->flags | ZERO;
	if (wip->formats[i] == '*' ||
		(wip->formats[i] == '0' && wip->formats[i + 1] == '*'))
	{
		wip->size_champ = va_arg(wip->ap, size_t);
		if (wip->formats[i] == '0')
			i++;
		i++;
	}
	else
	{
		wip->size_champ = wip->formats[i++] - '0';
		while (wip->formats[i] >= '0' && wip->formats[i] <= '9')
		{
			wip->size_champ = wip->size_champ * 10 + (wip->formats[i++] - '0');
		}
	}
	return (i);
}

static void	fill_sym(t_printf *wip, int n)
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

static int	check(t_printf *wip, int i)
{
	int		n;

	n = -1;
	if (wip->formats[i] == '*')
		wip->precision = va_arg(wip->ap, size_t);
	while (SYMBOL[++n])
	{
		if (wip->formats[i] == SYMBOL[n])
		{
			fill_sym(wip, n);
			return (0);
		}
	}
	if (wip->formats[i - 1] == '.')
		wip->precision = ft_atoi(&wip->formats[i]);
	return (1);
}

int			ft_parse(t_printf *wip, int i)
{
	char *temp_form;

	temp_form = wip->formats;
	wip->conv = INIT_C;
	wip->flags = INIT_F;
	wip->precision = 0;
	wip->size_champ = 0;
	temp_form[i] = '\0';
	wip->strdone = ft_strjoinmod(wip->strdone, wip->formats, 1);
	while (wip->formats[++i] && wip->conv == 0)
	{
		if (((wip->formats[i] >= '0' && wip->formats[i] <= '9') ||
			wip->formats[i] == '*') && ((wip->flags & POINT) == 0))
			i = len_champ(wip, i);
		check(wip, i);
	}
	wip->formats = ft_strdup(&temp_form[i]);
	free(temp_form);
	wip->strdone = ft_strjoinmod(wip->strdone, ch_conv1(wip), 3);
	return (-1);
}
