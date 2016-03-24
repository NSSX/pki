#include "my_printf.h"

int flag_fiel(t_main *main)
{
  char *tr;
  int used;
  int needzero;
  int totalneed;

  main->i++;
  if(main->chaine[main->i] == '+')
    {
      if((int)main->elem >= 0)
        {
          main->taille++;
          main->size++;
          main->print = ft_strjoin(main->print, "+");
          ft_putchar('+');
        }
      flag_fiel(main);
    }
  else if(main->chaine[main->i] == '#')
    {
      flag_fiel(main);
    }
  else if(main->chaine[main->i] == ' ')
    {
      if((int)main->elem >= 0)
        {
          main->taille++;
          main->size++;
          main->print = ft_strjoin(main->print, " ");
          ft_putchar(' ');
        }
      flag_fiel(main);
    }
  else if(main->chaine[main->i] == '0')
    {
      tr = ft_itoa((int)main->elem);
      used = ft_strlen(tr);
      needzero = main->taille + used;
      if(main->chaine[main->i + 1] >= '0' && main->chaine[main->i + 1] <= '9')
        {
          main->i++;
          totalneed = ft_atoi(&main->chaine[main->i]);
          if(totalneed > needzero)
            {
              while(needzero < totalneed)
                {
                  main->size++;
                  main->print = ft_strjoin(main->print, "0");
                  ft_putchar('0');
                  needzero++;
                }
            }
        }
      flag_fiel(main);
    }
  else
    main->i--;
  return (0);
}
