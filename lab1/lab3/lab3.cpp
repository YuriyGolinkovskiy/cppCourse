#include "iostream"
#include "cstdio"
#include "cstring"

using namespace std;

char* strnCat(char* dest, const char* src, size_t maxlen)
{
	int len = 0;
	while (dest[len] != '\0')//находим длинну строки dest
	{
		len++;
	}
	for (int i = 0; i < maxlen; i++)// дописываем в конец строки dest символы из строки src
	{
		dest[len] += src[i];
		len++;
	}
	dest[maxlen+len] = '\0';//символ конца строки, что бы не выводился мусор из памяти
	return dest;
}

int main()
{
	char s[100] = "Hello,my name is ";
	char s1[100] = "Anastasia";
	char s2[100] = "Hello,my name is ";
	printf("Initial string: %s\n", s);
	strncat_s(s, s1, 10);
	strnCat(s2, s1, 10);
	printf("Standard: %s\nMy version: %s\n", s, s2);
	system("pause");
	return 0;
}

