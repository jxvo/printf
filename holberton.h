#ifndef _HOLBERTON_
#define _HOLBERTON_
/**
 * struct types - structure for type
 * @typ: char to comepare to
 * @f: fuction to go to if true
 */
typedef struct types
{
	char typ;
	int (*f)();
} types;

int _printf(const char *format, ...);
#endif
