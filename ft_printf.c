/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 10:08:12 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/11 18:41:09 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include "libftprintf.h"
#include <stdarg.h>
#include <stdio.h>

int ft_printf (const char *format, ...)
{
	va_list ap;
	int i;

	i = -1;
	va_start(ap, format);
	if (format)
		while (format[++i] != '\0')
		{
			if (format[i] == '%')
				i += ft_parse(*format + i);
			else
				write(1, format[i], 1);
		}
}
