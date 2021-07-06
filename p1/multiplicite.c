#include "multiplicite.h"

int multiplicite(int *T, const int N,  int *max){
   
    int i = 0;
    int nbr = 1;
    *max = -2147483647; // le minimum pour un entier 

    while(i<N){

        if(T[i]> *max){

            *max = T[i];
            nbr = 1;

        }else if(T[i]== *max){

            nbr++;

        }

        i++;

    }

   return nbr;

}
