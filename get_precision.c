#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 *
 * Return: Precision.
 */
int get_precision(const char *format)
{
int precision = -1;
int i = 0;

while (format[i] != '\0')
{
if (format[i] == '.')
{
i++;
if (isdigit(format[i]))
{
precision = atoi(&format[i]);
}
else
{
precision = 0;
}
break;
}
i++;
}

return (precision);
}

/**
 * main - Entry point of the program.
 *
 * Return: Always 0.
 */
int main(void)
{
const char *format1 = "%.2f";
const char *format2 = "%s";
const char *format3 = "%.0f";
printf("Precision for format1: %d\n", get_precision(format1));
printf("Precision for format2: %d\n", get_precision(format2));
printf("Precision for format3: %d\n", get_precision(format3));
return (0);
}
