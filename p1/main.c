#include "multiplicite.h"
#include <stdio.h>

int main(){
   int T[8] = {13, -1, 7, 9, -12, 2, 4, 16};
   int max;

   printf("%d - %d\n", multiplicite(T, 8, &max), max");
}//fin main