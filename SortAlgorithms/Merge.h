#pragma once
#include "SortBase.h"

/**
 * @brief Specification of Sorting algorithm, this class 
 * implements all the logical stuff made in merge sort 
 * algorithm
 */
class Merge : public SortBase
{
public:
  Merge::Merge(std::string &output);
  Merge::~Merge() = default;
  void SortLine(std::string &currentLine) override;

private:
  /**
   * @brief Conquer part of the algorithm, in which we made the respective comparison
   * between the values contained both sub vectors, giving as result the recursive
   * append of sorted sub vectors
   * @param leftSide vector made in the form of (vector[0:len/2])
   * @param rightSide vector made in the form of (vector[len/2:len])
   * @return std::vector<int8_t> sorted subvector composed by the union of both sides
   */
  std::vector<int8_t> MergeSorted(std::vector<int8_t> &leftSide, std::vector<int8_t> &rightSide);
  /**
   * @brief This methods implements the divide startegy into the input vector recursively
   * ending with the paste of all the sub vectors   
   */
  std::vector<int8_t> MergeStep(std::vector<int8_t> &target);
};