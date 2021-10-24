#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
	int a = 0;
	char b = 0;
	char* c = "test";
	printf("%zd %zd %zd\n", sizeof(a), sizeof(b), sizeof(c));
	printf("Hi, python\n");
	char str[10];
	memset(str, '-', 6);
	char str2[] = "hello!";
	strncpy(str, str2, 6);
	str[9] = '\0';
	return 0;
}