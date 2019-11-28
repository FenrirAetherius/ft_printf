/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 10:08:12 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/28 13:47:55 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	t_printf	*wip;

	if (!(wip = malloc(sizeof(t_printf))))
		return (0);
	wip->formats = ft_strdup(format);
	wip->strdone = ft_strdup("");
	i = -1;
	va_start(ap, format);
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
	/*test
	printf("\nshort conv :%#.2x\n", wip->conv);
	printf("short flags :%#.2x\n", wip->flags);
	printf("int precision :%zu\n", wip->precision);
	printf("int size_champ :%zu\n", wip->size_champ);
	printf("int size_done :%zu\n", wip->size_strdone);
	end test*/
	free(wip->strdone);
	free(wip);
	return (i);
}
