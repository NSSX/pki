#include "my_printf.h"

//SpdDoOuUxXcC
int main()
{
  int res1;
  int res2;
  //les modifier l ll etc voir dans le man 3 printf
  //La precision dit cb de carac afficher
  //peut etre un ft_strjoin pour un bloc ?
  printf("VRAI PRINTF : \n");
  res1 = printf("lol%% %.4d\n", 1234);
  printf("MON PRINTF : \n");
  res2 = ft_printf("lol%% %.2d\n", 1234);
  ft_putstr("\nret 1 : ");
  ft_putnbr(res1);
  ft_putstr("\nret 2 : ");
  ft_putnbr(res2);
  return (0);
}

