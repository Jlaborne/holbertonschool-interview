#include "holberton.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * _isdigit - checks if a string contains only digits
 * @s: the string
 *
 * Return: 1 if all digits, 0 otherwise
 */
int _isdigit(char *s)
{
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

/**
 * _strlen - returns the length of a string
 * @s: the string
 *
 * Return: length
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}

/**
 * _putchar - writes a character to stdout (defined in separate _putchar.c)
 */
int _putchar(char c);

/**
 * print_result - prints the result skipping leading zeros
 * @res: the result array
 * @len: length of result
 */
void print_result(int *res, int len)
{
	int i = 0;

	while (i < len && res[i] == 0)
		i++;

	if (i == len)
		_putchar('0');

	for (; i < len; i++)
		_putchar(res[i] + '0');
	_putchar('\n');
}

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: argument vector
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	int len1, len2, i, j, *res;

	if (argc != 3 || !_isdigit(argv[1]) || !_isdigit(argv[2]))
	{
		write(1, "Error\n", 6);
		exit(98);
	}

	len1 = _strlen(argv[1]);
	len2 = _strlen(argv[2]);
	res = calloc(len1 + len2, sizeof(int));
	if (!res)
		exit(98);

	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			int mul = (argv[1][i] - '0') * (argv[2][j] - '0');

			res[i + j + 1] += mul;
			res[i + j] += res[i + j + 1] / 10;
			res[i + j + 1] %= 10;
		}
	}

	print_result(res, len1 + len2);
	free(res);
	return (0);
}
