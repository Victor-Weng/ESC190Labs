#include <stdio.h>
#include <stdlib.h>
#include "seamcarving.h"
#include <math.h>

void create_image(struct rgb_img **im, int width, int height)
{
    *im = (struct rgb_img *)malloc(sizeof(rgb_img));
    (*im)->height = height;
    (*im)->width = width;
    (*im)->data = (struct pixel *)malloc(sizeof(struct pixel) * height * width);
}


void calc_energy(struct rgb_img *im, struct rgb_img **grad)
{
    /*
    Compute the dual-gradient energy function then place it in struct rgb_img *grad

    rx, gx, bx are the differnces in the red, green, and blue components 
    of pixels surrounding the central pixel along x axis

    "" for y

    rx = (y, x+1)red - (y,x-1)red
    */

    // 1: COMPUTE rx, gx, bx


    *grad = (struct rgb_img *)malloc(sizeof(struct rgb_img));
    (*grad)->height = im->height;
    (*grad)->width = im->width;
    (*grad)->data = (struct pixel *)malloc(sizeof(struct pixel) * im->height * im->width);
    double dx = rx*rx + gx*gx + bx*bx;
    double dy = ry*ry + gy*gy + by*by;
}