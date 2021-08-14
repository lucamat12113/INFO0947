#include <stdio.h>
#include "multiplicite.h"


int main(){

   int T[8] = {13, -1, 16, 9, -12, 2, 4, 16};
   int max;

   multiplicite(T, 8, &max);

   printf("%d - %d\n", multiplicite(T, 8, &max), max);
}//fin main