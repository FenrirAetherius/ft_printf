#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
#include <unistd.h>
#include "libftprintf.h"

/*
**	attribut need to be completed
**
** for s:	attribut			: '-'
**			precision			: ok
**			largeur de champ	: ok
**			length modifier		: l
**			flags code mask		: 0b0000000010001010
**
** for c:	attribut			: '-'
**			precision			: no
**			largeur de champ	: ok
**			length modifier		: l
**			flags code mask		: 0b0000000010001000
**
**	p affiche l'adresse d'un pointer int *n n = 0xblabla affichera 0xblabla
** for p:	attribut			: '-'
**			precision			: no
**			largeur de champ	: ok
**			length modifier		: (null)
**			flags code mask		: 0b0000000000001000
**
** for d:	attribut			: '-' '0' ' ' '`' '+'
**			precision			: ok
**			largeur de champ	: ok
**			length modifier		: l ll h hh
**			flags code mask		: 0b0000110111111111
**
**	i work as the same as d with printf, the only diff is with scanf
** for i:	attribut			: '-' '0' ' ' '`' '+'
**			precision			: ok
**			largeur de champ	: ok
**			length modifier		: l ll h hh
**			flags code mask		: 0b0000110111111111
**
** for u:	attribut			: '-' '0' ' ' '`'
**			precision			: ok
**			largeur de champ	: ok
**			length modifier		: l ll h hh
**			flags code mask		: 0b0000010111111111
**
** for x:	attribut			: '-' '0' ' ' '#'
**			precision			: ok
**			largeur de champ	: ok
**			length modifier		: l ll h hh
**			flags code mask		: 0b0000011011111111
**
** for n:	attribut			:
**			precision			: no
**			largeur de champ	: no
**			length modifier		: l ll h hh
**			flags code mask		: 0b0000000011110000
*/

int main ()
{
	int *n;

	if(!(n = malloc(sizeof(int))))
		return(-1);/*

	printf("test '.f at the same time:\n\n");


	printf("%s\n", setlocale(LC_NUMERIC, "en_GB.UTF-8"));
	struct lconv *ptrLocale = localeconv();
	ptrLocale->decimal_point = "v";
	ptrLocale->thousands_sep = "m";
	printf("% 'f\n", 32000111.00501);
	printf("separator:'%s'\n", localeconv()->thousands_sep);
	printf("%lu\n", strlen(localeconv()->thousands_sep));

	printf("%s\n", setlocale(LC_ALL, "en_US.UTF-8"));
	printf("% 'f\n", 32000111.00501);
	printf("separator:'%s'\n", localeconv()->thousands_sep);
	printf("%lu\n", strlen(localeconv()->thousands_sep));

	printf("%s\n", setlocale(LC_ALL, "fr_FR.UTF-8"));
	printf("% 'f\n", 32000111.00501);
	printf("separator:'%s'\n", localeconv()->thousands_sep);
	printf("%lu\n", strlen(localeconv()->thousands_sep));

	printf("\ntest %% without arg :\n\n");

	printf("_ %dd _\n");
	printf("\n\ntest \"%% w\":\n\n");
	printf("_ %3. w _\n");
*/
	printf("\ntest n:\n\n");

	printf("\n%d", printf("asdgha%ddsg%n", 50, n));
	printf("\n%d\n", *n);
/*
	printf("\ntest * :\n\n");
	printf("%*f\n\n", 0, 35.765421);
	printf("%*f\n\n", 3, 35.765421);
	printf("%*f\n\n", 5, 35.765421);
	printf("%*.*s\n\n", 18, 3, "hello");

	printf("\n%d", printf("asdgha%ddsg sduh", 500));
	printf("\n%s\n", "dfh%");*/

	//setlocale(LC_ALL, "");
	printf("%s\n", setlocale(LC_ALL, "en_US.UTF-8"));
	//setlocale(LC_CTYPE, "UTF-8");
	printf("%s\n", setlocale(LC_CTYPE, "")); //to check local UTF or non UTF
	wchar_t *str;

	if(!(str = malloc(sizeof(wchar_t) * 6)))
		return(-1);
	str[0] = 7424;
	str[1] = 7425;
	str[2] = 7426;
	str[3] = 1792;
	str[4] = '\n';
	str[5] = 0;
	printf("%20s%12.04d\n", "\u1d00\u1d01\u1d02\u0700\n", 5); /*precision not working with C indicator conversion*/

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

	//write(1, str2, 13);
	/*printf("\n%#x\n", (char)str2[0]);
	printf("\n%#x\n", str2[1]);
	printf("\n%#x\n", str2[2]);
	printf("\n%#x\n", str2[3]);
	printf("\n%#x\n", 'a');

	write(1, "\u1d00\u1d01\u1d02\u0700\n", 13);
	printf("%-20p", "agasfc");*/
	/*
	**	test for %%
	*/
/*
	printf("%.3%\n");
	printf("%3%\n");
	printf("%003%\n");
	printf("%ll%\n");


	printf("%hhn", n);
	float z;
	z = 25.2;
	printf("%d%d.%d\n", ((int)(z/10)%10), ((int)(z/1)%10), (((int)(z/0.1))%10));*/

	//printf("%-10.6d", 5);
	/*str2 = (char *)0x0f402750;
	printf("%p\n%#lx", str2, (unsigned long)str2);*/
	//printf("%10.5s\n", "hel");
	//printf("%6.3u\n", 15);
	//printf("% +-20d", 65536);
	//printf("a%04d\n", -5);
	//printf("a%04d\n", 5);
	/*char *xeno;
	xeno = malloc(sizeof(char));
	printf("hello%hhn\n", xeno);
	printf("%hhd\n", *xeno);*/
	float hey;
	

	printf("%f\n", 15.51);
	printf("%g\n", 15.51);
	printf("%e\n", 15.51);
	return 0;
}
