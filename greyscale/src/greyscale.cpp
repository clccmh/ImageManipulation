/**
 * Author: Carter Hay
 *
 * Converts an image into a greyscale png.
 *
 * Version: 0.1
 * License: MIT
 */

#include <iostream>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>


using namespace std;

int main(int argc, char** argv) {
  int width, height, n;

  if (argc == 3) {

    cout << "input: " << argv[1] << "\toutput: " << argv[2] << endl;
    cout << "Converting image..." << endl;

    unsigned char* data = stbi_load(argv[1], &width, &height, &n, 0);

    if (data) {

      unsigned int channel_total;
      unsigned int pos = 0;

      for (int y = 0; y < height; y++) {
        for (int x = 0; x < width * n; x+=n) {
          channel_total = 0;
          for (int i = 0; i < n; i++) {
            channel_total += data[y * (width * n) + x + i];
          }
          channel_total = channel_total / n;
          data[pos++] = channel_total;
        }

      }
      stbi_write_png(argv[2], width, height, 1, data, width);
    }

  } else {
    cout << "ERROR: Incorrect number of arguments." << endl;
    cout << "usage: run.out input.png output.png" << endl;
  }
  return 1;
}
