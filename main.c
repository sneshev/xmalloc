#include "xmalloc.h"

#include <stdio.h>

char *create_str()
{
	char *str;

	str = xmalloc(5, XCHAR);
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

	str = xcalloc(5, XCHAR);
	str[0] = 'W';
	str[1] = 'S';
	str[2] = 'A';
	str[3] = 'D';
	str[4] = '\0';
	return (str);
}

char **create_arr()
{
	char **arr;

	arr = xmalloc(5, XCHAR_P);
	arr[0] = create_str();
	arr[1] = create_str();
	arr[2] = create_str();
	arr[3] = create_str();
	arr[4] = NULL;
	return (arr);
}

void print_arr(char **arr) {
	if (!arr || !*arr)
		return ;
	int i = 0;
	do {
		printf("arr[%d]: %s\n", i, arr[i]);
		i++;
	} while(arr[i]);
	printf("arr[%d]: %s\n", i, arr[i]);
}

void	write_str(char *str)
{
	printf("%s\n", str);
}

int main() {
	char *str = create_str();
	char **arr = create_arr();
	char *str2 = create_str();

	print_arr(arr);
	xfree(arr);
	xfree(str);
	char *str3 = create_str();
	write_str(str2);
	xfree(str2);
	xfree(str3);

	xexit(0);
}

/*
	see header
*/