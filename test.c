#include <stdio.h>
#include <locale.h>
#include <string.h>

int main ()
{
	int *n;

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

	printf("ha ha");
	printf(" %dd ");
	printf("ha ha\n");
	printf("\n\ntest \"%% w\":\n\n");
	printf("ha ha");
	printf(" % w ");
	printf("ha ha\n");

	printf("\ntest n:\n\n");

	printf("asdgha%ddsg%n sduh", 50, n);
	printf("%d", *n);

	printf("\ntest * :\n\n");
	printf("%.*f\n\n", 3, 35.765421);

	return (0);
}
