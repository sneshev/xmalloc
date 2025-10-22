#include "xmalloc.h"

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

void	write_str(char *str)
{
	printf("%s\n", str);
}

int main() {
	char *str = create_str();
	char *str2 = create_str();
	char *str3 = create_str();
	write_str(str2);
	xfree(&str);
	char *str4 = create_str();
	xfree(&str2);
	char *str5 = create_str();
	write_str(str3);
	write_str(str4);
	write_str(str5);

	free_registry();
}