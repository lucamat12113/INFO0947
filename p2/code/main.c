#include<stdio.h>
#include<stdlib.h>
#include"Polyligne.h"

int main(){



    Point2D *a= Create(1.0,1.0);
    Point2D *b= Create(-5,-8);
    Point2D *c= Create(3,3);

    float gxa = get_x(a);
    float gya = get_y(a);

    float gxb = get_x(b);
    float gyb = get_y(b);

    float gxc = get_x(c);
    float gyc = get_y(c);

    float dist = EuclDist(a,b);

    Point2D* translation = TranslatePoint2D(a, c);

    printf("a = ( %f, %f)\n", gxa, gya );
    printf("b = ( %f, %f)\n", gxb, gyb );
    printf("c = ( %f, %f)\n", gxc, gyc );

    printf("distance = %f \n", dist);
    printf("transl = %f, %f\n", get_x(TranslatePoint2D(a, b)), get_y(TranslatePoint2D(a, b)));
    printf("rot = %f, %f\n", get_x(RotatePoint2D(a, c, 30)), get_y(RotatePoint2D(a, c, 30)));


    return 0;
}