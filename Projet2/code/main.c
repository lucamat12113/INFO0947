#include<stdio.h>
#include<stdlib.h>
#include"course.h"

int main(){

    Escale *a = malloc(sizeof(Escale*));
    if(a==NULL)
        return NULL;
    
    Escale *b = malloc(sizeof(Escale*));
    if(b==NULL)
        return NULL;
    
    Escale *c = malloc(sizeof(Escale*));
    if(c==NULL)
        return NULL;

    a= creation(1.0,1.0, "cul");
    b= creation(2,2, "la");
    c= creation(3,3, "lo");

    Escale* gxa = get(a);

    Escale*  gxb = get(b);

    Escale*  gxc = get(c);

    float dist = calc_distance(a,b);

    printf("a = ( %f)\n", &gxa );
    printf("b = ( %f)\n", &gxb);
    printf("c = ( %f)\n", &gxc );

    printf("distance = %f \n", &dist);


    return 0;
}