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
	write_str(str);
	printf("str%%p = %p\n", str);
	free_registry();
}