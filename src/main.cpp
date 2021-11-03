#include "./bin/imgToAscii.cpp"
#include <string>

int main(int argc, char* argv[]) {
    std::string imageFile;
    std::string outputFile;

    // imageFile = "trump.jpeg";
    // outputFile = "trump.txt";

    imageFile = argv[1];
    outputFile = argv[2];
    
    // std::cin >> imageFile;

    AsciiTools::ImageData imageData = AsciiTools::loadImage(imageFile.c_str());
    AsciiTools::convertToAscii(imageData, outputFile, " _-*oOQA");
}