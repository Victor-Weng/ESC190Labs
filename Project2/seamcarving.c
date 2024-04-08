#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "seamcarving.h"
#include "c_img.h"

void calc_energy(struct rgb_img *im, struct rgb_img **grad)
{
    /*
    Compute the dual-gradient energy function then place it in struct rgb_img *grad

    rx, gx, bx are the differnces in the red, green, and blue components
    of pixels surrounding the central pixel along x axis

    "" for y

    rx = (y, x+1)red - (y,x-1)red
    */

    // 1: COMPUTE rx, gx, bx, ry, gy, by

    for (int y = 0; y < im->height; y++)
    {
        for (int x = 0; x < im->width; x++)
        {

            // rx, gx, bx

            // uint8_t get_pixel(struct rgb_img *im, int y, int x, int col){
            //    return im->raster[3 * (y*(im->width) + x) + col];

            // For pixels at the edge of the image, you should "wrap around" the image (if at border, go to the bottom)

            double xi = 0; // x increment
            double xd = 0; // x derement
            double yi = 0; // y increment
            double yd = 0; // y decrement

            // EDGE CASES FOR X:

            if (x == 0) // if column at very left
            {
                xi = x + 1;
                xd = im->width - 1;
            }
            else if (x == im->width - 1) // or column very right
            {
                xi = 0;
                xd = x - 1;
            }
            else
            {
                xi = x + 1;
                xd = x - 1;
            }

            // EDGE CASES FOR Y:

            if (y == 0) // if very top row
            {
                yi = y + 1;
                yd = im->height - 1;
            }
            else if (y == im->height - 1) // or very last row
            {
                yi = 0;
                yd = y - 1;
            }
            else
            {
                yi = y + 1;
                yd = y - 1;
            }

            double rx = get_pixel(im, y, xi, 0) - get_pixel(im, y, xd, 0);
            double gx = get_pixel(im, y, xi, 1) - get_pixel(im, y, xd, 1);
            double bx = get_pixel(im, y, xi, 2) - get_pixel(im, y, xd, 2);

            // ry, gy, by
            double ry = get_pixel(im, yi, x, 0) - get_pixel(im, yd, x, 0);
            double gy = get_pixel(im, yi, x, 1) - get_pixel(im, yd, x, 1);
            double by = get_pixel(im, yi, x, 2) - get_pixel(im, yd, x, 2);

            // 2: COMPUTE dx, dy

            double dx = rx * rx + gx * gx + bx * bx;
            double dy = ry * ry + gy * gy + by * by;

            // 3: COMPUTE energy

            double energy = sqrt(dx + dy);
            uint8_t dgenergy = energy/10; // dual gradient energy

            // 4: SET energy
            
            if(y == 0 && x == 1){
                printf("yi: %f\n",yi);
                printf("yd: %f\n",yd);

            

                printf("red below: %f\n", get_pixel(im, yi, x, 0));
                printf("red wrap around: %f\n", get_pixel(im, yd, x, 0));

                printf("ry: %f\n",ry);
                printf("gy: %f\n",gy);

                printf("dy: %f\n",dy);
                printf("Energy: %f\n", energy);
                printf("DGEnergy: %u\n", dgenergy);
            }
            
            set_pixel(*grad, y, x, dgenergy, dgenergy, dgenergy);
            // set red green and blue pixel values to dgenergy
        }
    }
}