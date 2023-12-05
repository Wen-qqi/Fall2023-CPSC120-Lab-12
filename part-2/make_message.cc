// Wen Fan
// WenFan@csu.fullerton.edu
// @Wen-qqi
// Partners: @iloi05

#include <Magick++.h>

#include <iostream>
#include <string>
#include <vector>

#include "make_message_functions.h"

int main(int argc, char const* argv[]) {
  Magick::InitializeMagick(*argv);
  std::vector<std::string> arguments(argv, argv + argc);
  if (arguments.size() < 3) {
    std::cout << "Please provide a path to a file" << std::endl;
    return 1;
  }
  std::string output_file_name = arguments.at(1);
  std::string image_format = ".gif";
  if (!HasMatchingFileExtension(output_file_name, image_format)) {
    std::cerr << arguments.at(1)
              << " is missing the required file extension .gif." << std::endl;
    return 1;
  }

  std::string message = {arguments.at(2)};

  const double aspect_ratio = 16.0 / 9.0;

  const int image_width = 1024;
  const int image_height = static_cast<int>(lround(image_width / aspect_ratio));
  Magick::ColorRGB yellow(1, 1, 0);
  Magick::Image image(Magick::Geometry(image_width, image_height), yellow);
  const int number_of_images = 5;
  std::vector<Magick::Image> images;

  for (int image_count = 0; image_count < number_of_images; image_count++) {
    std::cerr << "Image " << image_count + 1 << "...";
    for (int row = 0; row < image.rows(); row++) {
      for (int column = 0; column < image.columns(); column++) {
        double random_color_intensity = RandomDouble01();
        double red = 0.0;
        if (CoinFlip()) {
          red = random_color_intensity;
        }
        double green = 0.0;
        if (CoinFlip()) {
          green = random_color_intensity;
        }
        double blue = 0.0;
        if (CoinFlip()) {
          blue = random_color_intensity;
        }

        Magick::ColorRGB color{red, green, blue};
        image.pixelColor(column, row, color);
      }
    }
    image.font("Helvetica");
    image.fontPointsize(image.rows() / 3.0);
    image.fillColor(Magick::Color("yellow"));
    image.annotate(message, Magick::CenterGravity);
    images.push_back(image);
    std::cerr << "completed.\n";
  }

  Magick::writeImages(images.begin(), images.end(), output_file_name);
  return 0;
}