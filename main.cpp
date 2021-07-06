#include <iostream>
#include <unistd.h>

#include "ImageConverter/ImageConverter.h"

// Simple usage of ImageConverter lib with arg parsing.
// Feel free to use/modify it.

void printUsage()
{
  std::cout <<
    "Simple ASCII image generator by Ishiguro\n"
    "(https://github.com/Ishiguro96/simple-ascii-image-generator)\n"
    "\n"
    "Usage:\n"
    "\t-i\tInput file\n"
    "\t-s\tSize of ASCII image in format <X>x<Y> (e.g. 196x64)\n"
    "\t-c\t(optional) Character set used in conversion\n"
    "\t-h\tHelp"
  << std::endl;
}

int main(int argc, char** argv )
{
  std::string filename;
  std::string charSet;
  size_t x = {0};
  size_t y = {0};

  if (argc < 2) {
    printUsage();
    return EXIT_FAILURE;
  }

  int opt;
  while ((opt = getopt(argc, argv, "i:s:c:h::")) != -1)
  {
    switch (opt)
    {
      case 'i':
        filename = optarg;
        break;

      case 's':
        try {
          std::string sizeString = optarg;
          size_t xCharPos = sizeString.find('x');
          x = std::stoi(sizeString.substr(0, xCharPos));
          y = std::stoi(sizeString.substr(xCharPos + 1, sizeString.length() - 1));
        } catch (std::exception& e) {
          std::cerr << "Wrong parameters!\n";
          return EXIT_FAILURE;
        }
        break;

      case 'c':
        std::cout << optarg << std::endl;
        charSet = optarg;
        break;

      default:
        printUsage();
        return EXIT_FAILURE;
    }
  }

  if (!x || !y || filename.empty()){
    std::cout << "Wrong parameters!" << std::endl;
    return EXIT_FAILURE;
  }

  ish::ascii::ImageConverter imgConverter(x, y);
  if (!charSet.empty()) {
    imgConverter.setCharset(charSet);
  }

  ish::ascii::ReturnCode returnCode = imgConverter.convertImage(filename);
  if (returnCode != ish::ascii::ReturnCode::SUCCESS) {
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
