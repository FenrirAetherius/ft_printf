#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
#include <unistd.h>

int main ()
{
	int *n;

	if(!(n = malloc(sizeof(int))))
		return(-1);

	printf("test '.f at the same time:\n\n");


	setlocale(LC_NUMERIC, "");
	struct lconv *ptrLocale = localeconv();
	ptrLocale->decimal_point = "v";
	ptrLocale->thousands_sep = "m";
	printf("asgh% '.2f\n", 32000111.0050);
	printf("separator:'%s'\n", localeconv()->thousands_sep);
	printf("%lu\n", strlen(localeconv()->thousands_sep));

	setlocale(LC_NUMERIC, "POSIX");
	printf("asgh% '.2f\n", 32000111.00501);
	printf("separator:'%s'\n", localeconv()->thousands_sep);
	printf("%lu\n", strlen(localeconv()->thousands_sep));

	printf("\ntest %% without arg :\n\n");

	printf("_ %dd _\n");
	printf("\n\ntest \"%% w\":\n\n");
	printf("_ % w _\n");

	printf("\ntest n:\n\n");

	printf("\n%d", printf("asdgha%ddsg%n", 50, n));
	printf("\n%d\n", *n);

	printf("\ntest * :\n\n");
	printf("%.*f\n\n", 3, 35.765421);

	printf("\n%d", printf("asdgha%ddsg sduh", 500));
	printf("\n%s\n", "dfh%");

	setlocale(LC_ALL, "en_US.UTF-8");
	setlocale(LC_CTYPE, "en_US.UTF-8");
	wchar_t *str;

	if(!(str = malloc(sizeof(wchar_t) * 6)))
		return(-1);
	str[0] = 7424;
	str[1] = 7425;
	str[2] = 7426;
	str[3] = 1792;
	str[4] = 0x11a2d;
	str[5] = 0;
	printf("%ls%d\n", str, 5);

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

	write(1, str2, 13);
	/*printf("\n%#x\n", (char)str2[0]);
	printf("\n%#x\n", str2[1]);
	printf("\n%#x\n", str2[2]);
	printf("\n%#x\n", str2[3]);
	printf("\n%#x\n", 'a');

	write(1, "\u1d00\u1d01\u1d02\u0700\n", 13);*/
	return 0;
}
