#include <string>

namespace AsciiTools {

    struct ImageData {
        unsigned char* image;
        int width;
        int height;
    };

    ImageData loadImage(const char* imageName);
    void convertToAscii(ImageData imageData, std::string outputFile, std::string fillers = " _-*oOQA");
}