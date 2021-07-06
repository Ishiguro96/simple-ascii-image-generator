/*
The MIT License (MIT)

Copyright (c) 2021 Ishiguro

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#pragma once

#include <cstdint>
#include <string>
#include <string_view>
#include <opencv2/opencv.hpp>

namespace ish::ascii {

/**
 * @brief Return codes used in ImageConverter.
 */
enum class ReturnCode {
  SUCCESS,               	///< No error.
  ERROR_READING_FILE,    	///< Error during file reading.
  ERROR_WRONG_PARAMETERS,	///< Wrong parameters (filename, size, etc.).
};


/**
 * @brief Image Converter class
 *
 * @details Used to convert image into ASCII art
 *          Supported extensions: As for cv::imread() method.
 */
class ImageConverter {
public:
  /**
   * @brief Default constructor.
   */
  ImageConverter();

  /**
   * @brief         Parametrized constructor.
   *
   * @param sizeX   Size of ASCII image in X-axis.
   * @param sizeY   Size of ASCII image in Y-axis.
   * @param charSet Set of characters to be used to create ASCII image.
   */
  explicit ImageConverter(size_t sizeX, size_t sizeY, std::string_view charSet = ".,-+=xX@#");

  /**
   * @brief Convert image loaded from given path.
   * @param filename Path to image to convert.
   * @return ReturnCode
   * @see ReturnCode
   */
  ReturnCode convertImage(std::string_view filename);

  /**
   * @brief Setter for dimensions for ASCII image
   * @param sizeX New X-axis length.
   * @param sizeY New Y-axis length.
   */
  [[maybe_unused]] void setDimensions(size_t sizeX, size_t sizeY) { m_sizeX = sizeX; m_sizeY = sizeY; }

  /**
   * @brief Getter fir dimensions for ASCII image.
   * @return std::pair<size_t, size_t> Pair with (X,Y) image size.
   */
  [[maybe_unused]] [[nodiscard]] auto getDimensions() const { return std::make_pair(m_sizeX, m_sizeY); }

  /**
   * @brief Setter for character set.
   * @param charset String with new character set.
   */
  [[maybe_unused]] void setCharset(std::string_view charset) { m_charSet = charset; }

  /**
   * @brief Getter for character set.
   * @return std::string_view String view with existing character set.
   */
  [[maybe_unused]] [[nodiscard]] std::string_view getCharset() const { return m_charSet; }

private:
  ReturnCode _readImage(std::string_view filename);
  ReturnCode _convert();

  size_t m_sizeX; ///< Default X-axis length of ASCII image.
  size_t m_sizeY; ///< Default Y-axis length of ASCII image.
  std::string m_charSet = {".,-+=xX@#"}; ///< Default character set.

  cv::Mat m_image;
};

} // namespace
