#include "my_printf.h"

int manage_arg(t_main *main)
{
  main->i++;
  if(main->chaine[main->i] == 'd' || main->chaine[main->i] == 'i')
    {
      if(main->etat == 0)
	{
	  char *number;
	  int size;

	  if(main->accurate == 0)
	    main->accurate = ft_strlen(ft_itoa((int)main->elem));
	  size = ft_strlen(ft_itoa((int)main->elem));
	  number = ft_itoa((int)main->elem);
	  if(main->accurate > size)
	    number = ft_strsub(number, 0, main->accurate);
	  main->size += ft_strlen(ft_itoa((int)main->elem));
	  if(main->accurate > size)
	    {
	      while(size < main->accurate)
		{
		  main->print = ft_strjoin(main->print, "0");
		  size++;
		}
	    }
	  main->print = ft_strjoin(main->print, &number[0]);
	  //	  ft_putnbr((int)main->elem);
	}
      else  if(main->etat == 1)
        ft_putnbr((long int)main->elem);
      else  if(main->etat == 2)
        ft_putnbr((long long int)main->elem);
    }
  else if(main->chaine[main->i] == 's')
    {
      if(main->accurate == 0)
        main->accurate = ft_strlen((char *)main->elem);
      int i;
      char *lp;
      
      lp = (char *)main->elem;
      lp = ft_strsub(lp, 0, main->accurate);
      i = 0;
      main->print = ft_strjoin(main->print, &lp[0]);
      main->size += main->accurate;
    }
  else if(main->chaine[main->i] == 'u')
    {
      ft_putnbr((unsigned int)main->elem);
    }
  else if(main->chaine[main->i] == 'c')
    {
      ft_putchar((int)main->elem);
    }
  else if(main->chaine[main->i] == '%')
    {
      main->sizeword++;
      ft_putchar('%');
    }
  else if(main->chaine[main->i] == 'p')
    {
      ft_putstr("0x");
      base_converter((int)main->elem, 16);
    }
  else if(main->chaine[main->i] == 'x')
    {
      base_converter((unsigned int)main->elem, 16);
    }
  else if(main->chaine[main->i] == 'X')
    {
      base_converter_upper((unsigned int)main->elem, 16);
    }
  else if(main->chaine[main->i] == 'o')
    {
      ft_putnbr((unsigned int)main->elem);
    }
  else
    main->i--;
  return (1);
}
