#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "seamcarving.h"
#include "c_img.h"

// Tester code for 3x4.png


int main(){

    struct rgb_img *grad = (struct rgb_img*)malloc(sizeof(struct rgb_img));
    struct rgb_img *im = (struct rgb_img*)malloc(sizeof(struct rgb_img));

    char * filename = "3x4.bin";

    read_in_img(&im, filename);
    create_img(&grad, im->height, im->width);
    calc_energy(im, &grad);
    print_grad(grad);

    return 0;

}


