#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <malloc.h>
#include <ctype.h>
#include "ffun.h"
main()
{ 
//вводим количество уравнений и количество коэффициентов в уравнениях.
//записываем эти значения в переменные y и c соответственно.))
float *p,d;

int i,n,y,c,k,re,rb;
int ll;
ffun();
printf("\n Введите количество уравнений ^_^ ");
do {
  printf("\n Вводимое Вами число должно быть положительным)) ");
  scanf("%d",&y);
} while (y<=0);
printf("\n Введите количество коэффициентов в каждом уравнении ^_^ ");
do {
  printf("\n Вводимое Вами число должно быть положительным))) ");
  scanf("%d",&c);
} while (c<=0);
n=y*c;
//организуем динамический массив, в котором содержатся значения коэффициентов.
p=(float *)malloc(n*sizeof(float));
for (i=0;i<n;i++)
{
  printf("x[%d]=",i);
  scanf("%f",&d);
  p[i]=d;
}
//выводим значения массива
for (i=0;i<n;i++)
{ 
  if (i%c==0) printf("\n");
  printf("\t x[%d]=%6.2f",i,p[i]);
}
//Организация работы пользователя с программой
for(;;)
{
  const char std_promt[1];
  const char std[] = " ";
  char* input;
  char* input2;
  printf("\nВведите команду.(1-умножение строки на число,2-сложение строки со строкой,3-вычитание одной строки из другой)  ");
  int s;
//вводим команду
  input = readline(std_promt);
  sscanf(input, "%d", &s);
  while(s != 2 && s !=1 && s != 3)
  {
    printf("Команды могут быть либо 1(умножение строки на число), 2(сложение строки со строкой), 3(вычитание строки из строки) ");
    input = readline(std_promt);
    sscanf(input, "%d", &s);
  }
  add_history(input);
  printf("\nВведите числа, с которыми будете работать(номера строк или номер строки и число). Нужно вводить : число, затем пробел, затем число. < число><пробел><число>");
  int a;
  float b;
  input2 = readline(std);
  sscanf(input2, "%d %f", &a, &b);
  while (a<0 || a>y)
  {
    printf("\nОшибка! Возможно Вы ввели неправильный номер строки. или что-то подобное. Попробуйте еще ");
    input2 = readline(std);
    sscanf(input2, "%d %f", &a, &b);
  }
  add_history(input2);
  //printf("Команда : %d\n ", s);
  //printf("Число1 : %d\n", a);
  // printf("Число2 : %f\n", b);
  free(input);
  free(input2);
  if(s==1)
  { printf("Умножаю строку %d на число %f : ", a, b);
    for (i=(a-1)*c;i<(a-1)*c+c;i++)
       p[i]=p[i]*b;

    for (i=0;i<n;i++)
    {
      if (i%c==0) printf("\n");
        printf("\t x[%d]=%6.2f",i,p[i]);
    }
  }

  else
  { 
    rb = (int)b;
    while (b<1 || b>y || b-rb != 0)
    {
    printf("\nВторой строки с таким номером нет, попробуйте еще ввести номер ВТОРОЙ строки ");
    scanf("%f", &b);
    }
    re = (int)b;
    if(s==2)
    {
      if(a>re)
      {printf("\nСкладываю строку %d со строкой %d : ", a, re);
        for(i=(a-1)*c;i<(a-1)*c+c;i++)
          p[i]=p[i]+p[i-(a-re)*c];
        for (i=0;i<n;i++)
        {
           if (i%c==0) printf("\n");
            printf("\t x[%d]=%6.2f",i,p[i]);
        }
      }

      else
      {
        if(a<re)
        {printf("Складываю строку %d со строкой %d : ", a, re);
          for(i=(a-1)*c;i<(a-1)*c+c;i++)
            p[i]=p[i]+p[i+(re-a)*c];
          for (i=0;i<n;i++)
          {
             if (i%c==0) printf("\n");
              printf("\t x[%d]=%6.2f",i,p[i]);
          }
        }
        else
          printf("запрещенная операция");
      }
    }
    else
    {
      if(a>re)
      {printf("Вычитаю из строки %d строку %d : ", a, re);
        for(i=(a-1)*c;i<(a-1)*c+c;i++)
          p[i]=p[i]-p[i-(a-re)*c];
        for (i=0;i<n;i++)
        {
         if (i%c==0) printf("\n");
          printf("\t x[%d]=%6.2f",i,p[i]);
        }
      }



      else
      {
        if(a<re)
        {printf("Вычитаю из строки %d строку %d : ", a, re);
          for(i=(a-1)*c;i<(a-1)*c+c;i++)
            p[i]=p[i]-p[i+(re-a)*c];
          for (i=0;i<n;i++)
          {
             if (i%c==0) printf("\n");
              printf("\t x[%d]=%6.2f",i,p[i]);
          }
        }
        else
          printf("запрещенная операция");
      }
    }
  }
//Возможность прекратить работу
  printf("\n Вы будете продолжать? если да, то введите 1, если нет, введите 0 ");
  scanf("%d",&ll);
  while(ll != 1 && ll != 0)
  {
    printf("\nнеизвестная операция, попробуйте еще (1 или 0)");
    scanf("%d",&ll);
  }
    if (ll==0)
    {
      ffu();
      break;
    }
}
return 0;
}

