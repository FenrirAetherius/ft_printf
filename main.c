/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 17:09:31 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 16:50:29 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int main()
{
	char *str2;
	if(!(str2 = malloc(sizeof(char) * 13)))
		return(-1);
	/*\u1d00*/
	str2[0] = 0xe1;
	str2[1] = 0xb4;
	str2[2] = 0x80;
	/*\u1d01*/
	str2[3] = 0xe1;
	str2[4] = 0xb4;
	str2[5] = 0x81;
	/*\u1d02*/
	str2[6] = 0xe1;
	str2[7] = 0xb4;
	str2[8] = 0x82;
	/*\u0700*/
	str2[9] = 0xdc;
	str2[10] = 0x80;

	str2[11] = '\n';

	str2[12] = '\0';
	ft_printf("as\n%-5s\ndsdgbv%045.2dxg%X%x%u%u\n%p", "hel", 15, 15, -15, 5, 1, str2);
	free(str2);
	return (0);
}
