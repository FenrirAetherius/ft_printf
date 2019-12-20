/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 10:08:12 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/20 00:02:16 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_init(t_printf *wip, const char *format)
{
	wip->formats = ft_strdup(format);
	wip->strdone = ft_strdup("");
	wip->size_strdone = 0;
}

int			ft_printf(const char *format, ...)
{
	int			i;
	t_printf	*wip;

	if (!(wip = malloc(sizeof(t_printf))))
		return (0);
	ft_init(wip, format);
	va_start(wip->ap, format);
	i = -1;
	if (wip->formats)
		while (wip->formats[++i] != '\0')
		{
			if (wip->formats[i] == '%')
				i = ft_parse(wip, i);
		}
	wip->strdone = ft_strjoinmod(wip->strdone, wip->formats, 3);
	wip->size_strdone += ft_strlen(wip->strdone);
	i = wip->size_strdone;
	write(1, wip->strdone, wip->size_strdone);
	va_end(wip->ap);
	free(wip->strdone);
	free(wip);
	return (i);
}
