// Wen Fan
// WenFan@csu.fullerton.edu
// @Wen-qqi
// Partners: @iloi05

#include "make_message_functions.h"

#include <iomanip>

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

std::seed_seq rng_seed{1, 2, 3, 4, 5};

RandomNumberGenerator rng_01{0, 1, rng_seed};

RandomNumberGenerator rng_11{-1, 1, rng_seed};

RandomNumberGenerator rng_coin_flip{-1, 1, rng_seed};

double RandomDouble01() { return rng_01.Next(); }

double RandomDouble11() { return rng_11.Next(); }

bool CoinFlip() {
  double value = rng_coin_flip.Next();
  return (value > 0.0);
}
