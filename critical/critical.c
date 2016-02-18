#include <stdio.h>
#include <omp.h>

int main ()  
{

   int x;
   x = 0;

   #pragma omp parallel shared(x) 
   {

      #pragma omp critical (norace)   // try commenting this out and increasing thread count
      x = x + 1;

   }  /* end of parallel section */

   printf("x: %d\n",x);

   return 0;

}