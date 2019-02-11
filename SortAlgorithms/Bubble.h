#pragma once
#include "SortBase.h"

/**
 * @brief Specification of Sorting algorithm, this class 
 * implements all the logical stuff made in bubble sort 
 * algorithm
 */
class Bubble : public SortBase
{
public:
  Bubble(std::string &output);
  ~Bubble() = default;
  void SortLine(std::string &currentLine) override;
};