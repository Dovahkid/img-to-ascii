#include "./bin/imgToAscii.cpp"
#include <string>

int main(int argc, char* argv[]) {
    std::string imageFile;
    std::string outputFile;

    if(argc == 3) {
        imageFile = argv[1];
        outputFile = argv[2];
    }
    else {
        std::cout << "Please enter the image to be processed then the output text file" << std::endl;
        std::cin >> imageFile >> outputFile;
    }

    AsciiTools::ImageData imageData = AsciiTools::loadImage(imageFile.c_str());
    AsciiTools::convertToAscii(imageData, outputFile, " _-*oOQA");

    return 0;
}