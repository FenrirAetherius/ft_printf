/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 10:08:12 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/23 13:09:39 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

static t_printf	*ft_init(const char *format, int *i, int *n)
{
	t_printf	*wip;

	if (!(wip = malloc(sizeof(t_printf))))
		return (0);
	wip->formats = ft_strdup(format);
	wip->strdone = ft_strdup("");
	wip->size_strdone = 0;
	wip->strloc = ft_strdup(setlocale(LC_CTYPE, NULL));
	wip->error = 0;
	*i = -1;
	*n = 0;
	return (wip);
}

static void		ft_free_wip(t_printf *wip)
{
	free(wip->formats);
	free(wip->strdone);
	free(wip->strloc);
}

int				ft_printf(const char *format, ...)
{
	int			i;
	int			n;
	t_printf	*wip;

	wip = ft_init(format, &i, &n);
	va_start(wip->ap, format);
	while (wip->formats[++i] != '\0')
		if (wip->formats[i] == '%')
			n = ft_parse(wip, &i, n);
	wip->size_strdone = i - n;
	wip->strdone = ft_join_ns(wip->strdone, &(wip->formats[n]),
	&(wip->size_strdone), -1);
	i = write(1, wip->strdone, wip->size_strdone);
	va_end(wip->ap);
	ft_free_wip(wip);
	if (wip->error == 1)
		i = -1;
	free(wip);
	return (i);
}
