#include <omp.h>
#define CHUNKSIZE 100
#define N     1000

int main ()  
{

   int i, chunk;
   float a[N], b[N], \
         c[N];

   /* Some initializations */
   for (i=0; i < N; i++)
      a[i] = b[i] = i * 1.0;
   chunk = CHUNKSIZE;

   /* Note that we cannot apply the nowait construct here */
   #pragma omp parallel for shared(a,b,c,chunk) private(i) schedule(static,chunk)
   for (i=0; i < N; i++)
   {
      c[i] = a[i] + b[i];
   }

   return 0;

}