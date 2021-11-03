#include "./bin/imgToAscii.cpp"
#include <string>

int main() {
    std::string imageFile;
    std::cin >> imageFile;

    AsciiTools::ImageData imageData = AsciiTools::loadImage(imageFile.c_str());
    AsciiTools::convertToAscii(imageData, " _-*oOQA");
}