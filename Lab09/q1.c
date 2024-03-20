#include "c_img.c"
#include <stdio.h>
#include <stdlib.h>

int main(){
    //struct rgb_img* img_block = (struct rgb_img*)malloc(5*sizeof(struct rgb_img)); // Define block of rgb_imgs
    // maybe fix this make it a struct rgb_img variable instead of a block?

    rgb_img* img_block = (rgb_img*)malloc(sizeof(rgb_img));
    
    char *filename = "cannon.bin"; // the file name
    printf("main!!\n");
    int gain = 1.1; // gain value for each pixel
    for(int i = 0; i < 5; i++) // loop through the 5 images
    {
        printf("ahoy, %d\n", i);
        read_in_img(&img_block, filename); // puts into first slot
        printf("ahoy to you too, %d\n", i);

        printf("AHOY!!! %d, %d\n", (img_block)->height, (img_block)->width);

        for(int j = 0; j < ((img_block)->height); j++) // each row
        {
            printf("aloha %d\n", j);
            for(int k = 0; k < ((img_block)->width); k++) // each column
            {   
                printf("best %d\n", k);
                printf("before red %d\n", k);
                int red = get_pixel((img_block), j, k, 0)*gain; // get red values
                printf("after red %d\n", k);
                int green = get_pixel((img_block), j, k, 1)*gain; // get green values
                int blue = get_pixel((img_block), j, k, 2)*gain; // get blue values


                // If max value reached, cap it
                if(red > 255)
                {
                    red = 255;
                }
                if(green > 255)
                {
                    green = 255;
                }
                if(blue > 255)
                {
                    blue = 255;
                }

                // If color is black, give it gain value
                if(red == 0)
                {
                    red = gain;
                }
                if(green == 0)
                {
                    green = gain;
                }
                if(blue == 0)
                {
                    blue = gain;
                }

                set_pixel(img_block, j, k, red, green, blue); // set values
                
            }
            
        }
        gain += gain; // increase gain for the next iteration

        if(i == 0){
            write_img(img_block, "image0.bin");
        }
        if(i == 1){
            write_img(img_block, "image1.bin");
        }
        if(i == 2){
            write_img(img_block, "image2.bin");
        }
        if(i == 3){
            write_img(img_block, "image3.bin");
        }
        if(i == 4){
            write_img(img_block, "image4.bin");
        }
        
    }
}
