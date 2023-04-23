#include <ctype.h>
#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @index: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *index, va_list list)
{
	int curr_index = *index + 1;
	int precision = -1;

	/* Check if the current character is a '.' */
	if (format[curr_index] != '.')
		return (precision);

	precision = 0;

	/* Loop through the characters after the '.' */
	for (curr_index += 1; format[curr_index] != '\0'; curr_index++)
	{
		/* If the current character is a digit, calculate the precision */
		if (isdigit(format[curr_index]))
		{
			precision *= 10;
			precision += format[curr_index] - '0';
		}
		/* If the current character is a '*', get the precision from the argument list */
		else if (format[curr_index] == '*')
		{
			curr_index++;
			precision = va_arg(list, int);
			break;
		}
		/* If the current character is not a digit or '*', stop processing */
		else
			break;
	}

	*index = curr_index - 1;

	return (precision);
}
