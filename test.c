#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>

int main ()
{
	int *n;

	n = malloc(sizeof(int));

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

	str = malloc(sizeof(wchar_t) * 4);
	str[0] = 7424;
	str[1] = 7425;
	str[2] = 7426;
	str[3] = 1792;
	printf("%ls\n", str);
	return 0;
}
