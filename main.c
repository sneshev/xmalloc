#include "xmalloc.h"

#include <stdio.h>

char *create_str()
{
	char *str;

	str = xmalloc(5, CHAR);
	str[0] = 'W';
	str[1] = 'S';
	str[2] = 'A';
	str[3] = 'D';
	str[4] = '\0';
	return (str);
}

char *create_str2()
{
	char *str;

	str = xcalloc(5, CHAR);
	str[0] = 'W';
	str[1] = 'S';
	str[2] = 'A';
	str[3] = 'D';
	str[4] = '\0';
	return (str);
}

void	write_str(char *str)
{
	printf("%s\n", str);
}

int main() {
	char *str = create_str();
	char *str2 = create_str();
	char *str3 = create_str();
	xfree(&str2);
	char *str4 = create_str();
	xfree(&str4);
	xfree(&str);
	char *str5 = create_str();
	printf("str = %s\n", str);
	printf("str2 = %s\n", str2);
	printf("str3 = %s\n", str3);
	printf("str4 = %s\n", str4);
	printf("str5 = %s\n", str5);

	xexit(0);
}