#include <limits.h>
#include <stdio.h>
#include "holberton.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char *str1 = "Hello";
	char *str2 = "Holberton";
	char ch1 = 'X';
	int count = 0;
	int bytes = 0;

	printf("Expected:\n");
	bytes = printf("%s %s%c%c%c%%%\n", str1, str2, ch1, ch1, ch1);
	printf("Count: %d\n\nGot:\n", bytes);
	count = _printf("%s %s%c%c%c%%%\n", str1, str2, ch1, ch1, ch1);
	printf("Count: %d\n\n", count);

	printf("0------------------------\n\n");

	printf("Expected:\n");
	bytes = _printf("%s", "This sentence is retrieved from va_args!\n");
	printf("Count: %d\n\nGot:\n", bytes);
	count = _printf("%s", "This sentence is retrieved from va_args!\n");
	printf("Count: %d\n\n", count);

	printf("1------------------------\n\n");

	printf("Exptected:\n");
	bytes = printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
	printf("Count: %d\n\nGot:\n", bytes);
	count = _printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
	printf("Count: %d\n\n", count);

	printf("2------------------------\n\n");

	printf("Exptected:\n");
        bytes = printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');
        printf("Count: %d\n\nGot:\n", bytes);
        count = _printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');
        printf("Count: %d\n\n", count);

	printf("3------------------------\n\n");

	printf("Expected:\n");
        bytes = printf("%%");
        printf("\nCount: %d\n\nGot:\n", bytes);
        count = _printf("%%");
        printf("\nCount: %d\n\n", count);

	printf("4------------------------\n\n");

	printf("Expected:\n");
        bytes = printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');
        printf("\nCount: %d\n\nGot:\n", bytes);
        count = _printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');
        printf("\nCount: %d\n\n", count);

	printf("5------------------------\n\n");

	printf("Expected:\n");
        bytes = printf("css%ccs%scscscs", 'T', "Test");
        printf("\nCount: %d\n\nGot:\n", bytes);
        count = _printf("css%ccs%scscscs", 'T', "Test");
        printf("\nCount: %d\n\n", count);

	printf("6------------------------\n\n");

	printf("Expected:\n");
        bytes = printf(NULL);
        printf("\nCount: %d\n\nGot:\n", bytes);
        count = _printf(NULL);
        printf("\nCount: %d\n\n", count);

	printf("7------------------------\n\n");

	printf("Expected:\n");
        bytes = printf("%c", '\0');
        printf("\nCount: %d\n\nGot:\n", bytes);
        count = _printf("%c", '\0');
        printf("\nCount: %d\n\n", count);

	printf("8------------------------\n\n");

	printf("Expected:\n");
        bytes = printf("%");
        printf("\nCount: %d\n\nGot:\n", bytes);
        count = _printf("%");
        printf("\nCount: %d\n\n", count);

	printf("9------------------------\n\n");

	printf("Expected:\n");
        bytes = printf("%!\n");
        printf("\nCount: %d\n\nGot:\n", bytes);
        count = _printf("%!\n");
        printf("\nCount: %d\n\n", count);

	printf("10------------------------\n\n");

	printf("Expected:\n");
        bytes = printf("%K\n");
        printf("\nCount: %d\n\nGot:\n", bytes);
        count = _printf("%K\n");
        printf("\nCount: %d\n\n", count);

	return (0);
}
