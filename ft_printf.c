/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 10:08:12 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/22 16:01:44 by mrozniec    ###    #+. /#+    ###.fr     */
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
	if (wip->error == 0)
		wip->strdone = ft_strjoinmod(wip->strdone, wip->formats, 3);
	wip->size_strdone += ft_strlen(wip->strdone);
	i = wip->size_strdone;
	write(1, wip->strdone, wip->size_strdone);
	va_end(wip->ap);
	free(wip->strdone);
	if (wip->error == 1)
		i = -1;
	free(wip);
	return (i);
}
