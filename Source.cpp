//
//  Mandlebrot_set.cpp
//
//
//  Created by Riley Ballachay on 2021-02-06.
//


#include "Source.hpp"

#include <iostream>
#include <fstream>
#include <complex>


#define WIDTH 600
#define HEIGHT 600

using namespace std;

int value (int x, int y)  {
    complex<float> point((float)x/WIDTH-1.5, (float)y/HEIGHT-0.5);
    complex<float> z(0, 0);
    int nb_iter = 0;
    while (abs (z) < 2 && nb_iter <= 20) {
        z = z * z + point;
        nb_iter++;
    }
    if (nb_iter < 20)
       return (255*nb_iter)/30;
    else
       return 0;
}

int main ()  {

    ofstream my_Image ("mandelbrot.ppm");

    if (my_Image.is_open ()) {
        my_Image << "P3\n" << WIDTH << " " << HEIGHT << " 255\n";
        for (int i = 0; i < WIDTH; i++) {
            for (int j = 0; j < HEIGHT; j++)  {
                int val = value(i, j);
                int val2 = value(WIDTH-i,HEIGHT-j);
                int val3 = value(j, i);
                my_Image << val << ' ' << val2 << ' ' << val3 << "\n";
            }
        }
        my_Image.close();
    }
    else
      cout << "Could not open the file";

    return 0;
}
