/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wchar_utf_32.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 12:51:12 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 15:18:05 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <wchar.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char	*char_conv(wchar_t origin)
{
	char *new;

	if (origin < 0x0d800 || (origin > 0x0dfff && origin < 0x0110000))
	{
		if (!(new = malloc(sizeof(char) * 5)))
			return (NULL);
		new[3] = (char)(origin & 0x0ff);
		new[2] = (char)((origin >> 8) & 0x0ff);
		new[1] = (char)((origin >> 16) & 0x0ff);
		new[0] = (char)((origin >> 24) & 0x0ff);
		new[4] = '\0';
		return (new);
	}
	else
		return ("");
}
