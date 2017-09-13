/**
 * Author: Carter Hay
 *
 * Darkens an image by a percentage
 *
 * Version: 0.1
 * License: MIT
 */

#include <iostream>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

using namespace std;

int main(int argc, char** argv) {
  int width, height, n;

  if (argc == 2) {

    cout << "input: " << argv[1] << endl;
    cout << "Converting image..." << endl;

    unsigned char* data = stbi_load(argv[1], &width, &height, &n, 0);

    if (data) {

      unsigned int red = 0;
      unsigned int green = 0;
      unsigned int blue = 0;

      for (int y = 0; y < height; y++) {
        for (int x = 0; x < width * n; x+=n) {
          red += data[y * (width * n) + x];
          green += data[y * (width * n) + x + 1];
          blue += data[y * (width * n) + x + 2];
        }
      }

      unsigned long long total = red + green + blue;
      float red_percent = (float) red / total;
      float green_percent = (float) green / total;
      float blue_percent = (float) blue / total;


      cout << "red : " << red_percent << "\ngreen: " << green_percent 
           << "\nblue: " << blue_percent << endl;
    }

  } else {
    cout << "ERROR: Incorrect number of arguments." << endl;
    cout << "usage: run.out input.png" << endl;
  }
  return 1;
}
