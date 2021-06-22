#include <opencv2/opencv.hpp>
#include <cstdio>
#include <iostream>

#include "ImageConverter.h"

using namespace cv;

int main(int argc, char** argv )
{
	ish::ascii::ImageConverter imgConverter(48, 164, "/home/dawid/Downloads/yoda.jpg");
  constexpr uint32_t RowsDiv = 48;
	constexpr uint32_t ColsDiv = 164;
  if ( argc != 2 )
  {
    printf("usage: ascii_majster <Image_Path>\n");
    return -1;
  }

  Mat image;
  image = imread(argv[1], IMREAD_GRAYSCALE);

  if (!image.data)
  {
    printf("No image data \n");
    return -1;
  }

	std::string charset = ".,-+=xX@#";

  for (int divy = 0; divy < RowsDiv; ++divy) {
    for (int divx = 0; divx < ColsDiv; ++divx) {
			uint32_t counter = 0;
			uint32_t sum = 0;
			for (int i = 0; i < image.rows / RowsDiv; ++i) {
				for (int k = 0; k < image.cols / ColsDiv; ++k) {
					//std::cout << i << " - " << k << " = " << static_cast<int>(image.at<uint8_t>(i + divy * image.rows / RowsDiv, k + divx * image.cols / ColsDiv)) << "\n";
					sum += image.at<uint8_t>(i + divy * image.rows / RowsDiv, k + divx * image.cols / ColsDiv);
					counter++;
				 }
			}
			uint32_t avg = sum / counter;

			uint32_t sec = 255 / charset.length();
			for (uint32_t cx = 0; cx < charset.length(); ++cx) {
				if (avg <= (cx + 1) * sec) {
					std::cout << charset[cx];
					break;
				}
			}
    }
		std::cout << "\n";
  }


  //namedWindow("Display Image", WINDOW_AUTOSIZE);
  //imshow("Display Image", image);
  waitKey(0);
  return 0;
}
