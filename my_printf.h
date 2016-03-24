#ifndef MY_PRINTF_H
#define MY_PRINTF_H
#include <stdio.h>
#include <stdlib.h>
#include "libft/includes/libft.h"
#include <stdarg.h>

typedef struct s_main
{
  int i;
  const char *chaine;
  int nb;
  int taille;
  void *elem;
  int type;
  int etat;
  int accurate;
  int width;
  int mini;
  int etatmini;
  char *print;
  int size;
  int sizeword;
}t_main;

int manage_arg(t_main *main);
int base_converter(int convert, int basee);
int base_converter_upper(int convert, int basee);
int ft_printf(const char *format, ...);
int add_mini(t_main *main);
int my_width(t_main *main, va_list *myva);
int flag_fiel(t_main *main);
int my_accurate(t_main *main, va_list *myva);
int lenght_fiel(t_main *main);
#endif
