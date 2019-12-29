/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 17:09:31 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/29 11:18:23 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"
#include <limits.h>
#include <float.h>

int main()
{
	//setlocale(LC_CTYPE, "");
	//printf("%s\n", setlocale(LC_CTYPE, NULL));
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

	//ft_printf("as%6.10sdsdgbv%9.3dxg%#X %#x%u%u%s%ls %16pfsgj\n", "hel", 15, 15, -15, 5, 1, "\u1d00\u1d01\u1d02\u0700\n", str, str);
	//printf("as%6.10sdsdgbv%9.3dxg%#X %#x%u%u%s%ls %16pfsgj\n", "hel", 15, 15, -15, 5, 1, "\u1d00\u1d01\u1d02\u0700\n", str, str);
	//ft_printf("\n\n%*.*d\n", 10, 5, 9);
	free(str);


	//ft_printf("%s\n", setlocale(LC_NUMERIC, "en_GB.UTF-8"));
	/*struct lconv *ptrLocale = localeconv();
	ptrLocale->decimal_point = ",";
	ptrLocale->thousands_sep = " ";*//*
	ft_printf("% 'd\n", 32000111);
	ft_printf("separator:'%s'\n", localeconv()->thousands_sep);
	ft_printf("%lu\n", ft_strlen(localeconv()->thousands_sep));
	short *xeno;
	xeno = malloc(sizeof(short));
	ft_printf("hello%hn\n", xeno);
	ft_printf("%hd\n", *xeno);*/
	//ft_printf("adsg%lsagsd\n", NULL);
	//printf("adsg%lsagsd\n", NULL);
	wchar_t	t[4];
	t[0] = 65;
	t[1] = 0xBF;
	t[2] = 128519;
	t[3] = 0;
	int		z;
	wchar_t	y[10];
	y[0] = 65;
	y[1] = 0xBF;
	y[2] = 128519;
	y[3] = 32;
	y[4] = 0;
	/*printf("%s\n", */setlocale(LC_ALL, "en_US")/*)*/;
	/*printf("%s\n", *///setlocale(LC_CTYPE, NULL)/*)*/;
/*
	int		t1 = -1;
	int		t2 = -1;
	int		t1bis = -1;
	int		t2bis = -1;
*/

	ft_printf("\nf/%-10c/\n", 0);
	printf("\nv/%-10c/\n", 0);
	//ft_printf("\n/%10c/\n", 0);
	//printf("\n/%10c/\n", 0);
	//printf("size = %d\n", t2);
	//printf("\n\n%d\n", printf("012%c3456%s789%%012%i3456%x789%u012%p456789%e012%f3456789%g0123456789%o01%lc3456%ls789%n012%c3456%s789%%012%i3456%x789%u012%p456789%e012%f3456789%g0123456789%o01%lc3456%ls789%n", 'A', "TEST", 42, 0x42, 42, (void*)42, 4.2, -4.2, 4.101, 042, 35211, y, &z, 'A', "TEST", -21, -0x21, 0, (void*)0x101, 4.2, -4.2, 4.101, 042, 35211, y, &z));
	//printf("size = %d\n", t1);
}
