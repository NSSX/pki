#include "my_printf.h"

int add_mini(t_main *main)
{
  int needzero;
  char *final;
  char *myfinal;

  myfinal = (char *)malloc(sizeof(char) * 1);
  final = (char *)malloc(sizeof(char) * 1);
  needzero = main->width - main->size;
  if(needzero > 0)
    {
      while(needzero > 0)
        {
          main->print = ft_strjoin(" ", main->print);
          main->size++;
          needzero--;
        }
    }
  return (0);
}

int my_width(t_main *main, va_list *myva)
{
  int i;
  int size;
  int i2;
  char *myacc;

  i2 = 0;
  if(main->chaine[main->i + 1] >= '0' && main->chaine[main->i + 1] <= '9')
    {
      i = main->i + 1;
      while(main->chaine[main->i + 1] >= '0' && main->chaine[main->i + 1] <= '9')
        {
          main->i++;
        }
      size = main->i - i;
      myacc = (char *)malloc(sizeof(char) * size + 1);
      while(i <= main->i)
        {
          myacc[i2] = main->chaine[i];
          i2++;
          i++;
        }
      myacc[i2] = '\0';
      main->width = ft_atoi(myacc);
      main->etatmini = 1;
    }
  else if(main->chaine[main->i + 1] == '*')
    {
      main->i++;
      main->width = (int)main->elem;
      main->elem = va_arg(*myva, void *);
      main->etatmini = 1;
    }
  return (0);
}
