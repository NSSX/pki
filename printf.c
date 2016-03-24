#include "my_printf.h"

int ft_printf(const char *format, ...)
{
  va_list myva;
  t_main *main;

  main = (t_main *)malloc(sizeof(t_main) * 1); 
  main->print = (char *)malloc(sizeof(char) * 1);
  main->accurate = 0;
  main->width = 0;
  main->sizeword = 0;
  main->size = 0;
  main->mini = 0;
  main->etatmini = 0;
  main->taille = 0;
  main->etat = 0;
  main->i = 0;
  main->chaine = format;
  //initializzzzzze VA  
  va_start(myva, format); 
  while(format[main->i] != '\0')
    {
      if(format[main->i] != '%')
	{
	  ft_putchar(format[main->i]);
	  main->sizeword++;
	  //  main->i++;
	}      
      else
	{
      	  if(main->chaine[main->i + 1] != '%')
	    main->elem = va_arg(myva, void *); 
	  flag_fiel(main);
	  my_width(main, &myva);
	  my_accurate(main, &myva);
	  lenght_fiel(main);
	  manage_arg(main);
	  add_mini(main);
	  ft_putstr(main->print);
	}
      main->i++;
    }
  //END de mon VA
  va_end(myva);
  main->size += main->sizeword;
  return (main->size);
}
