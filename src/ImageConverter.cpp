#include "ImageConverter.h"

#include <iostream>

namespace ish::ascii {

ImageConverter::ImageConverter(uint32_t rowsDivider, uint32_t colsDivider, std::string_view charSet)
  : m_rowsDivider(rowsDivider)
  , m_colsDivider(colsDivider)
  , m_charSet(charSet)
{
  std::cout << m_rowsDivider << " - " << m_colsDivider << " - " << charSet << "\n";
}

} // namespace
