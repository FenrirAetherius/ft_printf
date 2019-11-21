/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wchar_utf_16BE.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 12:51:12 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 15:13:44 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <wchar.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

static char *two_char(wchar_t origin)
{
	char *new;
	if (!(new = malloc(sizeof(char) * 3)))
		return (NULL);
	new[1] = (char)(origin & 0x0ff);
	new[0] = (char)((origin >> 8) & 0x0ff);
	new[2] = '\0';
	return (new);
}

static char *four_char(wchar_t origin)
{
	char *new;
	if (!(new = malloc(sizeof(char) * 5)))
		return (NULL);
    origin = origin - 0x10000;
	new[3] = (char)(((origin & 0x03ff) + 0x0dc00) & 0x0ff);
	new[2] = (char)((((origin & 0x03ff) + 0x0dc00) >> 8) & 0x0ff00);
	new[1] = (char)((((origin >> 10) & 0x3ff) + 0xd800) & 0xff);
	new[0] = (char)(((((origin >> 10) & 0x3ff) + 0xd800) >> 8) & 0xff);
	new[4] = '\0';
	return (new);
}

char	*char_conv(wchar_t origin)
{
	if (origin < 0x0d800 || (origin > 0x0dfff && origin < 0x010000))
		return (two_char(origin));
	else if (origin > 0x0ffff && origin < 110000)
		return (four_char(origin));
	else
		return ("");
}
