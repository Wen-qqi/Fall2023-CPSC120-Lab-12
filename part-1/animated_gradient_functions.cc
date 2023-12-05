// Wen Fan
// WenFan@csu.fullerton.edu
// @Wen-qqi
// Partners: @iloi05

#include "animated_gradient_functions.h"

#include <cmath>
#include <iostream>

bool HasMatchingFileExtension(const std::string& file_name,
                              const std::string& extension) {
  int file_name_length = file_name.size();
  int extension_length = extension.size();
  bool is_long_enough = (file_name_length >= extension_length);
  bool ends_with_extentions = false;
  if (is_long_enough) {
    int period_location = (file_name_length - extension_length);
    ends_with_extentions =
        (file_name.compare(period_location, extension_length, extension) == 0);
    return ends_with_extentions;
  }

  return ends_with_extentions;
}

std::vector<double> BuildSineLookupTable(int image_width) {
  std::vector<double> lookup_table;
  double step = M_PI / static_cast<double>(image_width);
  for (int counter = 0; counter < image_width; counter++) {
    double sine_value = std::sin(step * counter);
    lookup_table.push_back(sine_value);
  }
  return lookup_table;
}
