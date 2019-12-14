/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fenrir <fenrir@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 10:08:12 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/14 00:59:30 by fenrir      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	int			i;
	t_printf	*wip;

	if (!(wip = malloc(sizeof(t_printf))))
		return (0);
	wip->formats = ft_strdup(format);
	wip->strdone = ft_strdup("");
	va_start(wip->ap, format);
	i = -1;
	if (wip->formats)
		while (wip->formats[++i] != '\0')
		{
			if (wip->formats[i] == '%')
				i = ft_parse(wip, i);
		}
	wip->strdone = ft_strjoinmod(wip->strdone, wip->formats, 3);
	i = wip->size_strdone;
	wip->size_strdone = ft_strlen(wip->strdone);
	write(1, wip->strdone, wip->size_strdone);
	va_end(wip->ap);
	free(wip->strdone);
	free(wip);
	return (i);
}
