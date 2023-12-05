// Wen Fan
// WenFan@csu.fullerton.edu
// @Wen-qqi
// Partners: @iloi05

/* Do not edit below this line. */
/* Do not edit below this line. */
/* Do not edit below this line. */

#ifndef MAKE_MESSAGE_FUNCTIONS_H
#define MAKE_MESSAGE_FUNCTIONS_H

#include <iostream>
#include <random>
#include <string>

bool HasMatchingFileExtension(const std::string& file_name,
                              const std::string& extension);

bool CoinFlip();

double RandomDouble(double min, double max);

double RandomDouble01();

double RandomDouble11();

class RandomNumberGenerator {
 private:
  std::mt19937 mt_engine_;
  std::uniform_real_distribution<double> uniform_dist_;

 public:
  RandomNumberGenerator(double minimum, double maximum) {
    std::random_device device;
    std::seed_seq seed{device()};
    mt_engine_ = std::mt19937{seed};
    uniform_dist_ = std::uniform_real_distribution<double>{minimum, maximum};
  }

  RandomNumberGenerator(double minimum, double maximum, std::seed_seq& seed) {
    mt_engine_ = std::mt19937{seed};
    uniform_dist_ = std::uniform_real_distribution<double>{minimum, maximum};
  }

  double Next() {
    double random_number = uniform_dist_(mt_engine_);
    return random_number;
  }
};

#endif