#pragma once

#include <cstdint>
#include <string>
#include <string_view>

namespace ish::ascii {

enum class ReturnCode : uint8_t {
  SUCCESS,
  ERROR_READING_FILE,
  ERROR_WRONG_PARAMETERS,
  ERROR_GENERIC,
};

class ImageConverter {
public:
	ImageConverter() = default;
  ImageConverter(uint32_t rowsDivider, uint32_t colsDivider, std::string_view charSet);
  //ReturnCode convertImage(std::string_view filename);
private:
  uint32_t m_rowsDivider;
  uint32_t m_colsDivider;
  std::string m_charSet;
};

} // namespace
