#include "my_printf.h"

int base_converter(int convert, int basee)
{
  char base_digits[16] =
    {'0', '1', '2', '3', '4', '5', '6', '7',
     '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

  int converted_number[64];
  long int number_to_convert = convert;
  int base;
  int index=0;
  base = basee;
  while (number_to_convert != 0)
    {
      converted_number[index] = number_to_convert % base;
      number_to_convert = number_to_convert / base;
      ++index;
    }

  --index;  /* back up to last entry in the array */
  while(index >= 0)
    {
      ft_putchar(base_digits[converted_number[index]]);
      index--;
    }
  return (0);
}

int base_converter_upper(int convert, int basee)
{
  char base_digits[16] =
    {'0', '1', '2', '3', '4', '5', '6', '7',
     '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

  int converted_number[64];
  long int number_to_convert = convert;
  int base;
  int index=0;
  base = basee;
  while (number_to_convert != 0)
    {
      converted_number[index] = number_to_convert % base;
      number_to_convert = number_to_convert / base;
      ++index;
    }

  --index;  /* back up to last entry in the array */
  while(index >= 0)
    {
      ft_putchar(base_digits[converted_number[index]]);
      index--;
    }
  return (0);
}
