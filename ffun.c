#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <malloc.h>
#include <ctype.h>
void ffun()
{ printf("\nЗдраствуйте! Введите свое имя!");
  char* inp;
  const char st[] = " ";
  char s[29];
  inp = readline(st);
  sscanf(inp, "%s", s);
  printf("\nПриветствуем Вас, %s !", s);
}
