#include <omp.h>
#define N     1000

int main ()
{

   int i;
   float a[N], b[N], c[N], d[N];

   /* Some initializations */
   for (i=0; i < N; i++) {
      a[i] = i * 1.5;
      b[i] = i + 22.35;
   }

   #pragma omp parallel shared(a,b,c,d) private(i)
   {

      int tid = omp_get_thread_num();

      #pragma omp sections nowait
      {

         #pragma omp section
         for (i=0; i < N; i++) {
            printf("thread id: %d, i: %d, loop 1\n",tid,i);
            c[i] = a[i] + b[i];
         }

         #pragma omp section
         for (i=0; i < N; i++) {
            printf("thread id: %d, i: %d, loop 2\n",tid,i);
            d[i] = a[i] * b[i];
         }

      }  /* end of sections */

  }  /* end of parallel section */

  return 0;

}