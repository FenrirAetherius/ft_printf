/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 17:09:31 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/13 02:25:54 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int main()
{

	setlocale(LC_ALL, "");
	//char *str2;
	//if(!(str2 = malloc(sizeof(char) * 6)))
		//return(-1);
	/*\u1d00*//*
	str2[0] = 0xe1;
	str2[1] = 0xb4;
	str2[2] = 0x80;*/
	/*\u1d01*//*
	str2[3] = 0xe1;
	str2[4] = 0xb4;
	str2[5] = 0x81;*/
	/*\u1d02*//*
	str2[6] = 0xe1;
	str2[7] = 0xb4;
	str2[8] = 0x82;*/
	/*\u0700*//*
	str2[9] = 0xdc;
	str2[10] = 0x80;

	str2[11] = '\n';

	str2[12] = '\0';*/
	
	wchar_t *str;

	if(!(str = malloc(sizeof(wchar_t) * 6)))
		return(-1);
	str[0] = 7424;
	str[1] = 7425;
	str[2] = 7426;
	str[3] = 1792;
	str[4] = '\n';
	str[5] = 0;

	ft_printf("as\n%6.10s\ndsdgbv\n%9.10d\nxg\n%#X %#x\n%u\n%u\n%.8ls\n", "hel", 15, 15, -15, 5, 1, str);
	ft_printf("\n\n%*.*d\n", 10, 5, 9);
	free(str);
	return (0);
}
