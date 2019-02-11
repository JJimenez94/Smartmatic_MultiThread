#pragma once
#include <mutex>
#include <string>
#include <vector>

class SortBase
{
protected:
  std::mutex _outputMutex;
  std::string _outputPath;

public:
  /**
   * @brief Constructor used for the base sorting class   
   * @param output the path to the output file in which we've to write
   * the sorting operations results
   */
  SortBase(std::string &output);
  virtual ~SortBase() = default;
  /**
   * @brief This method takes a string line and do the sorting operations
   * depending on which implementation was selected (bubble sort or merge sort)
   * @param currentLine a string composed of digits and whitespaces
   */
  virtual void SortLine(std::string &currentLine) = 0;

protected:
  /**
   * @brief The responsability of this method is to parse a sorted vector of digits
   * into a string ready to be writed on a file separating every digit with a ','   
   * @param sortedVector the vector of digits in which the sorting operations were
   * executed
   * @return std::string 
   */
  std::string PrepareOutputString(const std::vector<int8_t> &sortedVector) const;
  /**
   * @brief Method used to parse the original string into a vector of digits suitable
   * to perform sorting operations
   * @param currentLine raw data contained in a std::string
   * @return std::vector<int8_t> unsorted data.
   */
  std::vector<int8_t> ExtractLineData(std::string &&currentLine) const;
  /**
   * @brief Gets the formatted output string and writes it in the output file   
   * @param formattedOutput string in processed previously by PrepareOutputString method
   * @remark this method depends on the availability of the output resource (a.k.a file)
   */
  void SaveOutputString(std::string &&formattedOutput);
};