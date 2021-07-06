# Simple ASCII image generator
C++ project that converts standard image into ASCII one!

This project contains:
- library to convert standard image into ASCII one,
- example code with command line argument parsing to show usage of lib.

# ImageConverter library
This library provides single class `ImageConverter` that does all the job. You can specify parameters through constructor or by setters. Mandatory parameters are output dimensions. Sample character set is provided as default, but it can be easily changed.
Output image is printed into standard output, thus it can be further redirected to, for example, a file with `>` operator.

## Sample use
```
ish::ascii::ImageConverter imgConverter(64, 28, "-:x#");
imgConverter.convertImage("image.jpg");
```
Above code converts `image.jpg` to ASCII 64x28 ASCII image with used characters `-:x#`.
Example code provides better understanding of whole process with error checking.

## Dependencies
ImageConverter library depends on OpenCV to read and convert input image.
Instalation guide can be found on OpenCV website.

# Example application
Provided example application is able to parse command line arguments to use ImageConverter lib with ease.
Source code is rather self-explanatory. Feel free to play with it and modify it.

## Sample output
Let's convert some image! For the testing purpose, popular meme was chosen:

![Stonks](stonks.jpg)

Used command:
```
./simple_ascii_image_generator -i stonks.jpg -s 64x28 -c .:xX
```

Output:
```
............::......:...::xxx::::::xxxxxxxxx:..::::::.:::::x::x:
......::.............:xxxxxxxxxx::xxxxxxXxxxxx:.::..:::::..:x::x
...................:xxxxxxxxxxx::xxxxxxXXxxxxxxx:.:..:::::::::.:
................::xXXXXxxxxxxx:::xxxxxxxXxxxxxXxx::::::..::::...
...:............:XXXXXXXXXxxxx:::xxxxxx:xxxxxxXXxx..............
:::.:...........xXXXXXXXxxxxx::::xxxx::x:::xxxx::........:::::::
:::::.::.......:xxxxxxxxxxxx::::::xxxxx:xxxxxxxx::::............
::..:.:::......:xxxxxxxxxx:::::::::xxxXXXxxxxxxxxxx.............
.::..:.::......:xxx::::::::::::::::xxxxxxxxxxxxxxx:....::::..:::
.:.............:::::::::::::::::::::xxxxxxxxxxxxx:....::..::.::.
................::::::::::::::::::::xxxxxx::::::::........:::.::
................::::::::::::::::::::xxxxxx:::xxx:::.......::..::
............:....::::::::::::::::::::xxx:::::::::.::.....:::::::
..::.:.:::.:......:::::::.......:::::::xxxxxxxx....:...:..::....
....:...:....::::.::::::::.........:::::xxxxxx..................
:....:..:....:.:::.:::::::::::........::::xxx:..................
.:.:..:..::........::::::::::::::...............................
...................:::::::::::::::::...........................:
......................:::::::::::::..:................::.::....:
........................::::::::::::xxX:..................::....
..........................xxxxx::::xxXX:.................::.....
...........................:XXXxxxxXXXX:.................:::::.:
.............................:XXxxx:xxXx........................
...............................:::x:::.x........................
..................................:::xx:........................
...................................:xxX:........................
.....................................:xx........................
......................................:x........................
```

To create bigger image, stdout redirection is recommended, e.g.:
```
./simple_ascii_image_generator -i 4k_image.jpg -s 1920x1080 -c .:xX# > ASCII_image.txt
```
