/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 17:09:31 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/13 09:29:45 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"
#include <limits.h>

int main()
{
	setlocale(LC_CTYPE, "");
	printf("%s\n", setlocale(LC_CTYPE, NULL));
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
	str[0] = 0x1d00;
	str[1] = 7425;
	str[2] = 7426;
	str[3] = 1792;
	str[4] = '\n';
	str[5] = 0;

	ft_printf("as%6.10sdsdgbv%9.3dxg%#X %#x%u%u%s%ls%16pfsgj\n", "hel", 15, 15, -15, 5, 1, "\u1d00\u1d01\u1d02\u0700\n", str, str);
	printf("as%6.10sdsdgbv%9.3dxg%#X %#x%u%u%s%ls%16pfsgj", "hel", 15, 15, -15, 5, 1, "\u1d00\u1d01\u1d02\u0700\n", str, str);
	//ft_printf("\n\n%*.*d\n", 10, 5, 9);
	free(str);

/*
	ft_printf("%s\n", setlocale(LC_NUMERIC, "en_GB.UTF-8"));
	struct lconv *ptrLocale = localeconv();
	ptrLocale->decimal_point = "v";
	ptrLocale->thousands_sep = " ";
	ft_printf("% 'd\n", 32000111);
	ft_printf("separator:'%s'\n", localeconv()->thousands_sep);
	ft_printf("%lu\n", ft_strlen(localeconv()->thousands_sep));*//*
	short *xeno;
	xeno = malloc(sizeof(short));
	ft_printf("hello%hn\n", xeno);
	ft_printf("%hd\n", *xeno);*/
	//ft_printf("adsg%lsagsd\n", NULL);
	//printf("adsg%lsagsd\n", NULL);
	return (0);
}
