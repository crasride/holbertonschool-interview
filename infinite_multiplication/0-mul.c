#include "holberton.h"

/**
* error_exit - Prints "Error" and exits with status 98
*/
void error_exit(void)
{
	write(2, "Error\n", 6);
	exit(98);
}

/**
* is_digit - Checks if a string is composed of digits
* @str: The string to check
* Return: 1 if composed of digits, 0 otherwise
*/
int is_digit(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

/**
* multiply - Multiplies two numbers and prints the result
* @num1: The first number as a string
* @num2: The second number as a string
*/
void multiply(char *num1, char *num2)
{
	int len1 = 0, len2 = 0, i, j, carry = 0, result;
	int *res;

	len1 = strlen(num1);
	len2 = strlen(num2);

	res = malloc(sizeof(int) * (len1 + len2));
	if (!res)
		error_exit();

	for (i = 0; i < len1 + len2; i++)
		res[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			result = (num1[i] - '0') * (num2[j] - '0') + res[i + j + 1] + carry;
			res[i + j + 1] = result % 10;
			carry = result / 10;
		}
		res[i + j + 1] = carry;
	}

	for (i = 0; i < len1 + len2; i++)
		res[i] += '0';

	if (res[0] == '0')
		i = 1;
	else
		i = 0;

	for (; i < len1 + len2; i++)
		_putchar(res[i]);

	_putchar('\n');
	free(res);
}
