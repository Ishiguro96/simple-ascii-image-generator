#include "ImageConverter.h"

#include <iostream>

namespace ish::ascii {

ImageConverter::ImageConverter()
  : m_sizeX(0)
  , m_sizeY(0)
{
}

ImageConverter::ImageConverter(size_t sizeX, size_t sizeY, std::string_view charSet)
  : m_sizeX(sizeX)
  , m_sizeY(sizeY)
  , m_charSet(charSet)
{
}


ReturnCode ImageConverter::convertImage(std::string_view filename)
{
  // Check output image size.
  if (!m_sizeX || !m_sizeY) {
    return ReturnCode::ERROR_WRONG_PARAMETERS;
  }

  ReturnCode readImageReturn = _readImage(filename);
  if (readImageReturn != ReturnCode::SUCCESS) {
    return readImageReturn;
  }

  // If output image size is greater than input image size, shrink output image.
  if (m_sizeX > m_image.cols) m_sizeX = m_image.cols;
  if (m_sizeY > m_image.rows) m_sizeY = m_image.rows;

  // Actual conversion.
  return _convert();
}


ReturnCode ImageConverter::_convert()
{
  double colsDiv = static_cast<double>(m_image.cols) / static_cast<double>(m_sizeX);
  double rowsDiv = static_cast<double>(m_image.rows) / static_cast<double>(m_sizeY);

  double initialStep[2] = {0.0, 0.0};

  // Iterate over individual regions.
  for (size_t iterY = 0; iterY < m_sizeY; ++iterY) {
    for (size_t iterX = 0; iterX < m_sizeX; ++iterX) {
      size_t sum = {0};
      size_t counter = {0};

      // Iterate over all pixels inside current region.
      for (auto divY = static_cast<int>(initialStep[1]); divY < static_cast<int>(initialStep[1] + rowsDiv); ++divY) {
        for (auto divX = static_cast<int>(initialStep[0]); divX < static_cast<int>(initialStep[0] + colsDiv); ++divX) {
          sum += m_image.at<uint8_t>(divY, divX);
          counter++;
        }
      }
      // Increment regions column.
      initialStep[0] += colsDiv;

      // Calculate mean value of current region.
      size_t avg = sum / counter;

      // Determine which character from whole set should be used.
      size_t sec = 255 / m_charSet.length();
      for (size_t cx = 0; cx < m_charSet.length(); ++cx) {
        if (avg <= (cx + 1) * sec ||cx == m_charSet.length() - 1) {
          std::cout << m_charSet[cx];
          break;
        }
      }
    }
    // All columns in current row were used, go to next row.
    initialStep[0] = {0.0};
    initialStep[1] += rowsDiv;
    std::cout << "\n";
  }
  return ReturnCode::SUCCESS;
}


ReturnCode ImageConverter::_readImage(std::string_view filename)
{
  if (filename.empty()) {
    return ReturnCode::ERROR_WRONG_PARAMETERS;
  }

  m_image = cv::imread(filename.data(), cv::IMREAD_GRAYSCALE);

  if (!m_image.data) {
    return ReturnCode::ERROR_READING_FILE;
  }
  return ReturnCode::SUCCESS;
}

} // namespace
