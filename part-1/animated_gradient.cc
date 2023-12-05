// Wen Fan
// WenFan@csu.fullerton.edu
// @Wen-qqi
// Partners: @iloi05

#include <Magick++.h>

#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "animated_gradient_functions.h"

const int kImageWidth{512};
const int kImageHeight{512};
const int kNumberOfImages = 10;

int main(int argc, char* argv[]) {
  Magick::InitializeMagick(*argv);
  std::vector<std::string> arguments(argv, argv + argc);
  if (arguments.size() < 2) {
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

  std::vector<double> sine_lookup_table = {BuildSineLookupTable(kImageWidth)};
  Magick::ColorRGB white(1, 1, 1);
  std::vector<Magick::Image> images;

  double blue_step = {M_PI / static_cast<double>(kNumberOfImages)};
  int row_col_step = {kImageHeight / kNumberOfImages};

  for (int current_image = 0; current_image < kNumberOfImages;
       current_image++) {
    Magick::Image image(Magick::Geometry(kImageWidth, kImageHeight), white);
    double blue = {sin(blue_step * current_image)};
    for (int row = 0; row < image.rows(); row++) {
      for (int column = 0; column < image.columns(); column++) {
        int current_step = {current_image * row_col_step};
        double red = {sine_lookup_table.at((row + current_step) % kImageWidth)};
        double green = {
            sine_lookup_table.at((column + current_step) % kImageHeight)};
        Magick::ColorRGB color{red, green, blue};
        image.pixelColor(column, row, color);
      }
    }
    images.push_back(image);
    std::cerr << "completed.\n";
  }
  Magick::writeImages(images.begin(), images.end(), output_file_name);

  return 0;
}