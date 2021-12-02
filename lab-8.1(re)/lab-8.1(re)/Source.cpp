// Lab_08_1(re).cpp
// <Василик Юлія>
// Лабораторна робота №8.1(рекурсивний спосіб)
// Пошук та заміна символів у літерному рядку 
// Варіант 2

#include <iostream>
#include <windows.h>

using namespace std;

int Count(char* str, int i)
{
	if (str[i] != 0)
		if (str[i] == '+' || str[i] == '-' || str[i] == '=')
			return 1 + Count(str, i + 1);
		else
			return Count(str, i + 1);
	else
		return 0;
}

char* Change(char* dest, const char* str, char* t, int i)
{
	if (str[i] != 0)
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '=')
		{
			strcat_s(t, sizeof(t), "**");
			return Change(dest, str, t + 2, i + 1);
		}
		else
		{
			*t++ = str[i++];
			*t = '\0';
			return Change(dest, str, t, i);
		}
	}
	else
	{
		*t++ = str[i++];
		*t++ = str[i++];
		*t = '\0';
		return dest;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char str[101];
	cout << "Введіть літерний рядок:" << endl;
	cin.getline(str, 100);
	cout << "Літерний рядок містить " << Count(str, 1) << " символів '+ - ='" << endl;
	char* dest1 = new char[151];
	dest1[0] = '\0';
	char* dest2;
	dest2 = Change(dest1, str, dest1, 0);

	cout << "Модифікований літерний рядок: " << dest2 << endl;

	return 0;
}

